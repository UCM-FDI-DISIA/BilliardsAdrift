#include "GameManager.h"
#include <iomanip>
#include "SceneLoader.h"
#include "Structure/MainLoop.h"
#include "Structure/Scene.h"
#include "Structure/GameObject.h"
#include "Components/RigidBody.h"
#include "Components/Animator.h"
#include "Components/MeshRenderer.h"
#include "ColoredBall.h"
#include "checkML.h"

template class JUEGO_API Tapioca::Singleton<BilliardsAdrift::GameManager>;
template<>
BilliardsAdrift::GameManager* Tapioca::Singleton<BilliardsAdrift::GameManager>::instance_ = nullptr;

namespace BilliardsAdrift {
GameManager::GameManager()
    : sceneLoader(nullptr), mainLoop(nullptr), firstStateName(""), currentStateName(""), currentState(), INIT_TIME(0),
      INIT_LIFE(0), time(0), life(0), score(0), processing(false), actualLevel(1) { }

GameManager::~GameManager() {
    sceneLoader = nullptr;
    mainLoop = nullptr;
}

bool GameManager::initComponent(const CompMap& variables) {
    if (!setValueFromMap(firstStateName, "firstStateName", variables)) {
        Tapioca::logError("GameManager: no se pudo inicializar firstSceneName.");
        return false;
    }

    if (!setValueFromMap(INIT_LIFE, "initLife", variables)) {
        Tapioca::logError("GameManager: no se pudo inicializar INIT_LIFE.");
        return false;
    }

    float timeAux;
    if (!setValueFromMap(timeAux, "initTime", variables)) {
        Tapioca::logError("GameManager: no se pudo inicializar INIT_TIME.");
        return false;
    }
    INIT_TIME = (long long int)timeAux;

    return true;
}

void GameManager::start() {
    sceneLoader = Tapioca::SceneLoader::instance();
    mainLoop = Tapioca::MainLoop::instance();


    currentStateName = firstStateName;
    if (currentStateName == "MainMenu") currentState = MainMenu;
    else if (currentStateName == "InGame")
        currentState = InGame;
    else if (currentStateName == "EndScreen")
        currentState = GameOver;
    else if (currentStateName == "PauseMenu")
        currentState = Pause;
    changeScene(currentStateName);
}

void GameManager::update(const uint64_t deltaTime) {
    if (currentState == InGame) {
        time -= deltaTime;

#ifdef _DEBUG
        //std::cout << std::fixed << std::setprecision(2) << time / 1000. << "\n";
        if (time <= 0) {
#ifdef _DEBUG
            std::cout << "El jugador se ha quedado sin tiempo.\n";
#endif
            currentState = Lose;
            pushEvent("ev_GameOver", nullptr);
        }
#endif
        // Compruueba que todas las bolas est�n inmovilizadas
        auto it = balls.begin();
        while (it != balls.end()) {
            Tapioca::RigidBody* rb = (*it)->getComponent<Tapioca::RigidBody>();
            auto v = rb->getVelocity();
            auto f = rb->getTotalForce();
            if (std::abs(v.x < 1e-4) && std::abs(v.y < 1e-4) && std::abs(v.z < 1e-4) && std::abs(f.x < 1e-4) &&
                std::abs(f.y < 1e-4) && std::abs(f.z < 1e-4)) {
                // rb->setVelocity(Tapioca::Vector3(0));
                ++it;
            }
            else {
                pushEvent("ev_ballMoved", nullptr, true);
                break;
            }
        }
        if (it == balls.end()) {
            processing = false;
            pushEvent("ev_endProcessing", nullptr, true);
        }
    }
}

void GameManager::handleEvent(std::string const& id, void* info) {
    if (id == "ev_Pause") {
        onPause();
    }
    else if (id == "loadBalls") {
        std::string str1 = "Level";
        std::string str2 = std::to_string(actualLevel);
        std::string result = str1 + str2;
        auto v = mainLoop->getScene(result)->getObjects();
        for (auto& g : v) {
            ColoredBall* ball = g->getComponent<ColoredBall>();
            if (ball != nullptr) {
                balls.insert(g);
                g->getComponent<Tapioca::RigidBody>()->setVelocity(Tapioca::Vector3(0));
            }
        }
    }
    else if (id == "ev_Lose") {
        onLose();
    }
    else if (id == "ev_Win") {
        onWin();
    }
    else if (id == "delete_ContinueButton") {
        mainLoop->getScene("EndScreen")->getHandler("ContinueImageButton")->die();
    }
    else if (id == "ev_onStart") {
        onStart();
    }

    else if (id == "ev_Processing") {
        processing = true;
    }
    else if (id == "ev_ToggleAnim") {
        Tapioca::Animator* animator = getObject()->getScene()->getHandler("Sinbad")->getComponent<Tapioca::Animator>();
        animator->playAnim("Dance");
        animator->setPlaying(animator->getPlaying());
    }
    else if (id == "BallShot") {
        Tapioca::GameObject* b = ((Tapioca::GameObject*)info);
        balls.erase(b);
    }
    else if (id == "ev_GameOver") {
        onGameOver();
    }
    else if (id == "BallShotWrongColor") {
        Tapioca::GameObject* b = ((Tapioca::GameObject*)info);
        balls.erase(b);
        loseLife();
    }
    else if (id == "whiteBallHasHit") {
        bool hit = *((bool*)info);
        if (!hit) {
            changeScore(-1);
#ifdef _DEBUG
            std::cout << "No se ha colisionado con ninguna bola\n";
#endif
        }
    }
    else if (id == "whiteBallIn") {
        if (balls.size() == 0) {
            onGameOver();
        }
    }
}

// Igual hay pasarle el nombre de la escena al motor y que el motor se encargue de cargarla, pero COMO?
void GameManager::changeScene(std::string const& scene) const { Tapioca::SceneLoader::instance()->loadScene(scene); }

void GameManager::goToNextLevel() {
    actualLevel++;
    changeScene(getActualLevelName());
    pushEvent("ev_onStart", nullptr, false, true);
}

void GameManager::changeScore(int s) { score += s; }

void GameManager::changeLife(int l) { life += l; }

void GameManager::loseLife() {
    if (life > 0) life--;
    else {
        Tapioca::logInfo("El jugador se ha quedado sin vidas.\n");
        currentState = Lose;
        pushEvent("ev_GameOver", nullptr, false, true);
    }
}

void GameManager::changeTime(float t) { time += t * 1000; }

void GameManager::changeActualLevel(int l) { actualLevel += l; }

std::string GameManager::getActualLevelName() const { return "Level" + std::to_string(actualLevel); }

void GameManager::onReset() { }

void GameManager::onStart() {

    time = INIT_TIME * 1000;
    score = 0;
    life = INIT_LIFE;

    pushEvent("loadBalls", nullptr, true, true);
}

void GameManager::onLose() { pushEvent("delete_ContinueButton", nullptr, true, true); }

void GameManager::onGameOver() {
    changeScene("EndScreen.lua");
    if (currentState == Lose) pushEvent("ev_Lose", nullptr, false, true);
    else
        pushEvent("ev_Win", nullptr, false, true);
}

void GameManager::onWin() { }

void GameManager::onPause() {
    std::string str1 = "Level";
    std::string str2 = std::to_string(actualLevel);
    std::string result = str1 + str2;

    Tapioca::logInfo("wdaujkdwaundawiudklawdaw\n");

    if (currentState == InGame) {
        currentState = Pause;
        mainLoop->getScene(result)->setActive(false);
        changeScene("PauseMenu.lua");
    }
    else if (currentState == Pause) {
        currentState = InGame;
        mainLoop->getScene(result)->setActive(true);
        mainLoop->deleteScene("PauseMenu.lua");
    }
}

void GameManager::onPlayConfirmed() {
    currentState = InGame;
    changeScene("Level" + std::to_string(actualLevel));

    mainLoop->deleteScene("MainMenu");
    pushEvent("ev_onStart", nullptr, true,true);
}

void GameManager::onContinueConfirmed() { goToNextLevel(); }

void GameManager::onRestartConfirmed() {
    std::string result = "Level" + std::to_string(actualLevel);
    mainLoop->deleteScene("EndScreen.lua");
    changeScene(result);
}

void GameManager::onMainMenuConfirmed() {
    currentState = MainMenu;
    std::string result = "Level" + std::to_string(actualLevel);
    mainLoop->deleteScene(result);
    changeScene("MainMenu.lua");
}
}