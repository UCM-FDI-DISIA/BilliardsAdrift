#include "GameManager.h"
#include "UIManager.h"
#include "SceneLoader.h"
#include "Structure/GameObject.h"
#include "Structure/Scene.h"
#include "Structure/MainLoop.h"
#include "Components/RigidBody.h"
#include "Components/Animator.h"
#include "ColoredBall.h"
#include <iomanip>
#include <string>
template class JUEGO_API Tapioca::Singleton<BilliardsAdrift::GameManager>;

template<>
BilliardsAdrift::GameManager* Tapioca::Singleton<BilliardsAdrift::GameManager>::instance_ = nullptr;

namespace BilliardsAdrift {

GameManager::GameManager()
    : firstStateName(""), currentStateName(""), currentState(), INIT_TIME(0), INIT_LIFE(0), time(0), life(0), score(0),
      processing(false), actualLevel(1) { }

GameManager::~GameManager() { 
    // HAY QUE ELIMINAR LAS FUNCIONES CREADAS EN EL START
    Tapioca::UIManager::instance()->removeFunction("Play");
    Tapioca::UIManager::instance()->removeFunction("Continue");
    Tapioca::UIManager::instance()->removeFunction("Restart");
    Tapioca::UIManager::instance()->removeFunction("MainMenu");
}

void GameManager::reset() { }

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
    // create();

    return true;
}

void GameManager::start() {
    // Funciones de los botones
    Tapioca::UIManager::instance()->setFunction(
        "Play", [&]() { this->onPlayConfirmed(); });
    Tapioca::UIManager::instance()->setFunction(
        "Continue", [&]() { this->onContinueConffirmed(); });
    Tapioca::UIManager::instance()->setFunction(
        "Restart", [&]() { this->onRestartConffirmed(); });
    Tapioca::UIManager::instance()->setFunction(
        "MainMenu", [&]() { this->onMainMenuConffirmed(); });

    currentStateName = firstStateName;
    if (currentStateName == "MainMenu") currentState = MainMenu;
    else if (currentStateName == "InGame") {
        currentState = InGame;
        onStart();
    }
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
            onGameOver();
#ifdef _DEBUG
            std::cout << "El jugador se ha quedado sin tiempo.\n";
#endif
            pushEvent("ev_GameOver", nullptr);
        }
#endif
        //comprobar que todas las bolas están inmovilizadas
        auto it = balls.begin();

        while (it != balls.end()) {
            Tapioca::RigidBody* rb = (*it)->getComponent<Tapioca::RigidBody>();
            auto v = rb->getVelocity();
            if (std::abs(v.x < 1e-4) && std::abs(v.y < 1e-4) && std::abs(v.z < 1e-4)) {
                //rb->setVelocity(Tapioca::Vector3(0));
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
        changeScene("PauseMenu.lua");
    }
    if (id == "Continue") {
        changeScene("PauseMenu.lua");
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
}

void GameManager::onStart() {
    time = INIT_TIME * 1000;
    score = 0;
    life = INIT_LIFE;
    auto v = object->getScene()->getObjects();
    for (auto& g : v) {
        ColoredBall* ball = g->getComponent<ColoredBall>();
        if (ball != nullptr) {
            balls.insert(g);
            g->getComponent<Tapioca::RigidBody>()->setVelocity(Tapioca::Vector3(0));
        }
    }
}

void GameManager::onGameOver() {
    currentState = GameOver;
    changeScene("EndScreen.lua");
}

void GameManager::onPlayConfirmed() {
    currentState = InGame;
    onStart();
    changeScene("Level" + std::to_string(actualLevel));
    Tapioca::MainLoop::instance()->deleteScene("MainMenu");
}

void GameManager::onContinueConffirmed() {
    actualLevel++;
    std::string str1 = "Level";
    std::string str2 = std::to_string(actualLevel);
    std::string str3 = ".lua";
    std::string result = str1 + str2 + str3;
    changeScene(result);
    start();
}

void GameManager::onRestartConffirmed() {
    std::string str1 = "Level";
    std::string str2 = std::to_string(actualLevel);
    std::string str3 = ".lua";
    std::string result = str1 + str2 + str3;
    Tapioca::MainLoop::instance()->deleteScene("EndScreen.lua");
    changeScene(result);

    start();
}

void GameManager::onMainMenuConffirmed() {

    currentState = MainMenu;
    std::string str1 = "Level";
    std::string str2 = std::to_string(actualLevel);
    std::string str3 = ".lua";
    std::string result = str1 + str2 + str3;
    Tapioca::MainLoop::instance()->deleteScene(result);
    changeScene("MainMenu.lua");
}

void GameManager::onWin() { }

// Igual hay pasarle el nombre de la escena al motor y que el motor se encargue de cargarla, pero COMO?
void GameManager::changeScene(std::string const& scene) const { Tapioca::SceneLoader::instance()->loadScene(scene); }

void GameManager::changeScore(int s) { score += s; }

void GameManager::changeLife(int l) { life += l; }

void GameManager::changeTime(uint64_t t) { time += t * 1000; }

void GameManager::loseLife() {
    if (life > 0) {
        life--;
    }
    else {
#ifdef _DEBUG
        std::cout << "El jugador se ha quedado sin vidas.\n";
#endif
        pushEvent("ev_GameOver", nullptr);
    }
}
}