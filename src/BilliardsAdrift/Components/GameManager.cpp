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
      timerText(nullptr), timerTextComponent(nullptr), sceneLoaded(false) { }

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
    audios = std::vector<Tapioca::AudioSourceComponent*>(Sounds_MAX);
    audios[PickSound] = object->getScene()->getHandler("PickSound")->getComponent<Tapioca::AudioSourceComponent>();
    audios[ExplosionSound] =
        object->getScene()->getHandler("ExplosiveSound")->getComponent<Tapioca::AudioSourceComponent>();
}

void GameManager::updateCurrentState(const std::string name) {
    currentStateName = name;
    if (currentStateName == "MainMenu") currentState = MainMenu;
    else if (currentStateName == "LoseScreen") {
        currentState = Lose;
        pushEvent("ev_GameOver", nullptr);
    }
    else if (currentStateName == "WinScreen") {
        currentState = Win;
        pushEvent("ev_GameOver", nullptr);
    }
    else if (currentStateName == "PauseMenu") {
        currentState = Pause;
        pushEvent("ev_Pause", nullptr);
    }
    else if (currentStateName == "Level1" || currentStateName == "Level2") {
        currentState = InGame;
        pushEvent("ev_onStart", nullptr, true, true);
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
    if (currentState == InGame && sceneLoaded) {
        changeTime(-(float)(deltaTime) / 1000.f);
        updateTimerText();

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
                processing = true;
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
        sceneLoaded = true;
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
        if (balls.size() == 1 && currentState != Lose) {
            currentState = Win;
            pushEvent("ev_GameOver", nullptr, false, true);
        }
    }
    else if (id == "ev_GameOver") {
        onGameOver();
    }
    else if (id == "BallShotWrongColor") {
        Tapioca::GameObject* b = ((Tapioca::GameObject*)info);
        balls.erase(b);
        loseLife();
        if (balls.size() == 1 && currentState != Lose) {
            currentState = Win;
            pushEvent("ev_GameOver", nullptr, false, true);
        }
    }
    else if (id == "whiteBallHasHit") {
        bool hit = *((bool*)info);
        if (!hit) {
            loseLife();
        }
    }
    else if (id == "blackBallIn") {
        Tapioca::GameObject* b = ((Tapioca::GameObject*)info);
        balls.erase(b);
        if (balls.size() != 1) {
            Tapioca::logInfo("Se ha metido la bola negra demasiado pronto.\n");
            currentState = Lose;
            pushEvent("ev_GameOver", nullptr, false, true);
        }
    }
    else if (id == "whiteBallIn") {
        if (balls.size() == 0) {
            currentState = Lose;
            pushEvent("ev_GameOver", nullptr, false, true);
        }
        else
            loseLife();
    }
    else if (id == "ev_pickUp") {
        audios[PickSound]->playOnce();
    }
    else if (id == "ev_explosion") {
        audios[ExplosionSound]->playOnce();
    }
    else if (id == "ev_debug1") {
        Tapioca::logInfo("A pulsada \n");
        
        goToNextLevel();
    }
    else if (id == "ev_debug2") {
        updateCurrentState("LoseScreen");
    }
    else if (id == "ev_debug3") {
        updateCurrentState("WinScreen");
    }
}

void GameManager::changeScene(std::string const& scene) const {
    if (sceneLoader != nullptr) sceneLoader->loadScene(scene);
    else
        Tapioca::logWarn(("GameManager: No se ha podido cargar la escena " + scene + ".").c_str());
}

void GameManager::goToNextLevel() {
    sceneLoaded = false;
    mainLoop->deleteScene(getActualLevelName());
    balls.clear();
    actualLevel++;
    changeScene(getActualLevelName());
    currentState = InGame;
    pushEvent("ev_onPlay", nullptr, false, true);
}

void GameManager::changeScore(int s) {
    score += s;
    if (score <= 0) {
#ifdef _DEBUG
        std::cout << "El jugador se ha quedado sin puntuacion.\n";
#endif
        currentState = Lose;
        pushEvent("ev_GameOver", nullptr, false, true);
    }
}

void GameManager::changeLife(int l) {
    life += l;
    if (life <= 0) {
#ifdef _DEBUG
        std::cout << "El jugador se ha quedado sin vida.\n";
#endif
        currentState = Lose;
        pushEvent("ev_GameOver", nullptr, false, true);
    }
}

void GameManager::loseLife() {
    if (life > 0) life--;
    else {
        Tapioca::logInfo("El jugador se ha quedado sin vidas.\n");
        currentState = Lose;
        pushEvent("ev_GameOver", nullptr, false, true);
    }
}

void GameManager::changeTime(float t) {
    time += t * 1000;
    if (time <= 0) {
#ifdef _DEBUG
        std::cout << "El jugador se ha quedado sin tiempo.\n";
#endif
        currentState = Lose;
        pushEvent("ev_GameOver", nullptr, false, true);
    }
}

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

void GameManager::onLose() { changeScene("LoseScreen"); }

void GameManager::onGameOver() {
    sceneLoaded = false;
    balls.clear();
    mainLoop->deleteScene(getActualLevelName());

    if (currentState == Lose) {
        pushEvent("ev_Lose", nullptr, false, true);
    }
    else {
        pushEvent("ev_Win", nullptr, false, true);
    }
}

void GameManager::onWin() { changeScene("WinScreen"); }

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

void GameManager::onContinueConfirmed() {
    if (actualLevel < 2) {
        sceneLoaded = false;
        mainLoop->deleteScene(getActualLevelName());
        mainLoop->deleteScene("WinScreen");
        balls.clear();
        goToNextLevel();
    }
    else {
        actualLevel = 1;
        onMainMenuConfirmed();
    }
    
}

void GameManager::onRestartConfirmed() {
    if (currentState == Lose) mainLoop->deleteScene("LoseScreen");
    else if (currentState == Win)
        mainLoop->deleteScene("WinScreen");
    currentState = InGame;
    changeScene(getActualLevelName());
}

void GameManager::onMainMenuConfirmed() {
    if (currentState == Lose) 
        mainLoop->deleteScene("LoseScreen");
    else if (currentState == Win)
        mainLoop->deleteScene("WinScreen");
    else if (currentState == Pause) {
        mainLoop->deleteScene("PauseMenu");
    }

    balls.clear();
    sceneLoaded = false;
    mainLoop->deleteScene(getActualLevelName());
    std::string result = "MainMenu";
    updateCurrentState(result);
    changeScene(result);
}
