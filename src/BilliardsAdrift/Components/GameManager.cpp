#include "GameManager.h"
#include <sstream>
#include <iomanip>
#include <functional>
#include "SceneLoader.h"
#include "Structure/MainLoop.h"
#include "LuaManager.h"
#include "Structure/Scene.h"
#include "Structure/GameObject.h"
#include "Components/AudioSourceComponent.h"
#include "Structure/Component.h"
#include "Components/RigidBody.h"
#include "Components/Animator.h"
#include "Components/MeshRenderer.h"
#include "Components/Transform.h"
#include "Components/Text.h"
#include "ColoredBall.h"

#include "PhysicsManager.h"
#include "checkML.h"

template class JUEGO_API Tapioca::Singleton<GameManager>;
template<>
GameManager* Tapioca::Singleton<GameManager>::instance_ = nullptr;

GameManager::GameManager()
    : sceneLoader(nullptr), mainLoop(nullptr), luaManager(nullptr), firstStateName(""), currentStateName(""),
      currentState(), INIT_TIME(0), INIT_LIFE(0), time(0), life(0), score(0), processing(false), actualLevel(1),
      timerText(nullptr), timerTextComponent(nullptr) { }

GameManager::~GameManager() {
    sceneLoader = nullptr;
    mainLoop = nullptr;
    luaManager = nullptr;
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
    //Tapioca::PhysicsManager::instance()->activateDebug(true);
    sceneLoader = Tapioca::SceneLoader::instance();
    mainLoop = Tapioca::MainLoop::instance();
    luaManager = Tapioca::LuaManager::instance();
    registerLuaFunctions();
    updateCurrentState(firstStateName);
    changeScene(firstStateName);
    audios= object->getComponents<Tapioca::AudioSourceComponent>();
}

void GameManager::updateCurrentState(const std::string name) {
    currentStateName = name;
    if (currentStateName == "MainMenu") currentState = MainMenu;
    else if (currentStateName == "LoseScreen") {
        pushEvent("ev_GameOver", nullptr);
        currentState = Lose;
    }
    else if (currentStateName == "PauseMenu") {
        pushEvent("ev_Pause", nullptr);
        currentState = Pause;
    }
    else if (currentStateName == "Level1" || currentStateName == "Level2") {
        pushEvent("ev_onStart", nullptr, true, true);
        currentState = InGame;
    }
}

void GameManager::registerLuaFunctions() {
    std::function<void()> playFunction = [&]() { onPlayConfirmed(); };
    std::function<void()> mainMenuFunction = [&]() { onMainMenuConfirmed(); };
    std::function<void()> resumeFunction = [&]() { onResumeConfirmed(); };
    std::function<void()> continueFunction = [&]() { onContinueConfirmed(); };
    std::function<void()> restartFunction = [&]() { onRestartConfirmed(); };
    luaManager->addLuaFunction("Play", playFunction);
    luaManager->addLuaFunction("MainMenu", mainMenuFunction);
    luaManager->addLuaFunction("Resume", resumeFunction);
    luaManager->addLuaFunction("Continue", continueFunction);
    luaManager->addLuaFunction("Restart", restartFunction);
}

void GameManager::update(const uint64_t deltaTime) {
    if (currentState == InGame) {
        time -= deltaTime;
        updateTimerText();

        if (time <= 0) {
#ifdef _DEBUG
            std::cout << "El jugador se ha quedado sin tiempo.\n";
#endif
            //currentState = Lose;
            //pushEvent("ev_GameOver", nullptr);
        }

        // Comprueba que todas las bolas estan inmovilizadas
        auto it = balls.begin();
        while (it != balls.end()) {
            Tapioca::RigidBody* rb = (*it)->getComponent<Tapioca::RigidBody>();
            auto v = rb->getVelocity();
            auto f = rb->getTotalForce();
            if (std::abs(v.x < 1e-3) && std::abs(v.y < 1e-3) && std::abs(v.z < 1e-3) && std::abs(f.x < 1e-3) &&
                std::abs(f.y < 1e-3) && std::abs(f.z < 1e-3)) {
                rb->setVelocity(Tapioca::Vector3(0));
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
    if (id == "ev_Play") {
        onPlay();
    }
    else if (id == "ev_Pause") {
        onPause();
    }
    else if (id == "loadBalls") {
        auto v = mainLoop->getScene(getActualLevelName())->getObjects();
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
    else if (id == "ev_onStart") {
        onStart();
    }
    else if (id == "ev_Processing") {
        processing = true;
    }
    else if (id == "ev_ToggleAnim") {
        Tapioca::Animator* animator = mainLoop->getScene("Level" + std::to_string(actualLevel))
                                          ->getHandler("MilkTea")
                                          ->getComponent<Tapioca::Animator>();
        animator->playAnim("Idle");
        animator->setPlaying(animator->getPlaying());
    }
    else if (id == "BallShot") {
        Tapioca::GameObject* b = ((Tapioca::GameObject*)info);
        Tapioca::Animator* animator = mainLoop->getScene("Level" + std::to_string(actualLevel))
                                          ->getHandler("MilkTea")
                                          ->getComponent<Tapioca::Animator>();
        animator->playAnim("Idle");
        animator->setPlaying(animator->getPlaying());

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
        }
    }
    else if (id == "whiteBallIn") {
        if (balls.size() == 0) onGameOver();
        else
            loseLife();
    }
    else if (id == "ev_pickUp") {
        audios[0]->playOnce();
    }
    else if (id == "ev_explosion") {
       // audios[1]->playOnce();
    }
}

void GameManager::changeScene(std::string const& scene) const {
    if (sceneLoader != nullptr) sceneLoader->loadScene(scene);
    else
        Tapioca::logWarn(("GameManager: No se ha podido cargar la escena " + scene + ".").c_str());
}

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

void GameManager::updateTimerText(int precision) {
    if (timerTextComponent != nullptr) {
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(precision) << getTime();
        timerTextComponent->setText(stream.str());
    }
}

void GameManager::onReset() { }

void GameManager::onPlay() { updateCurrentState(getActualLevelName()); }

void GameManager::onStart() {
    time = INIT_TIME * 1000;
    score = 0;
    life = INIT_LIFE;
    timerText = mainLoop->getScene(currentStateName)->getHandler("TimerText");
    if (timerText != nullptr) timerTextComponent = timerText->getComponent<Tapioca::Text>();
    updateTimerText();

    pushEvent("loadBalls", nullptr, true, true);
}

void GameManager::onLose() { }

void GameManager::onGameOver() {
    if (currentState == Lose) {
        pushEvent("ev_Lose", nullptr, false, true);
        changeScene("LoseScreen");
    }
    else {
        pushEvent("ev_Win", nullptr, false, true);
        changeScene("WinScreen");
    }
}

void GameManager::onWin() { }

void GameManager::onPause() {
    if (currentState == InGame) {
        currentState = Pause;
        mainLoop->getScene(getActualLevelName())->setActive(false);
        changeScene("PauseMenu");
    }
    else if (currentState == Pause) {
        currentState = InGame;
        mainLoop->getScene(getActualLevelName())->setActive(true);
        mainLoop->deleteScene("PauseMenu");
    }
}

void GameManager::onPlayConfirmed() {
    changeScene(getActualLevelName());
    mainLoop->deleteScene("MainMenu");
    pushEvent("ev_Play", nullptr, true, true);

    //PRUEBA NO BORRAR
    //currentState = Lose;
    //pushEvent("ev_GameOver", nullptr, true, true);
}

void GameManager::onResumeConfirmed() { onPause(); }

void GameManager::onContinueConfirmed() { goToNextLevel(); }

void GameManager::onRestartConfirmed() {
    if (currentState == Lose) mainLoop->deleteScene("LoseScreen");
    else if (currentState == Win)
        mainLoop->deleteScene("WinScreen");
    changeScene(getActualLevelName());
}

void GameManager::onMainMenuConfirmed() {
    if (currentState == Lose) mainLoop->deleteScene("LoseScreen");
    else if (currentState == Win)
        mainLoop->deleteScene("WinScreen");
    else if (currentState == Pause) {
        mainLoop->deleteScene("PauseMenu");
    }

    mainLoop->deleteScene(getActualLevelName());
    std::string result = "MainMenu";
    updateCurrentState(result);
    changeScene(result);
}
