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
#include "Components/Image.h"
#include "checkML.h"

GameManager::GameManager()
    : sceneLoader(nullptr), mainLoop(nullptr), luaManager(nullptr), firstStateName(""), currentStateName(""),
      currentState(), currentLevelScene(nullptr), INIT_TIME(0), INIT_LIFE(0), time(0), life(0), score(0),
      processing(false), playerBall(nullptr), actualLevel(1), maxLevels(2), livesText(nullptr),
      livesTextComponent(nullptr), timerText(nullptr), timerTextComponent(nullptr), sceneLoaded(false),
      milkAnimator(nullptr), teaAnimator(nullptr) { }

GameManager::~GameManager() {
    sceneLoader = nullptr;
    mainLoop = nullptr;
    luaManager = nullptr;
    currentLevelScene = nullptr;
    livesText = nullptr;
    livesTextComponent = nullptr;
    timerText = nullptr;
    timerTextComponent = nullptr;
}

bool GameManager::initComponent(const CompMap& variables) {
    if (!setValueFromMap(firstStateName, "firstStateName", variables)) {
        Tapioca::logError("GameManager: no se pudo inicializar firstSceneName.");
        return false;
    }

    if (!setValueFromMap(INIT_LIFE, "initLives", variables)) {
        Tapioca::logError("GameManager: no se pudo inicializar INIT_LIFE.");
        return false;
    }

    if (!setValueFromMap(INIT_TIME, "initTime", variables)) {
        Tapioca::logError("GameManager: no se pudo inicializar INIT_TIME.");
        return false;
    }

    return true;
}

void GameManager::start() {
    sceneLoader = Tapioca::SceneLoader::instance();
    mainLoop = Tapioca::MainLoop::instance();
    luaManager = Tapioca::LuaManager::instance();
    registerLuaFunctions();
    updateCurrentState(firstStateName);
    changeScene(firstStateName);
    audios = std::vector<Tapioca::AudioSourceComponent*>(Sounds_MAX);
    Tapioca::GameObject* aux = object->getScene()->getHandler("PickSound");
    if (aux != nullptr) audios[PickSound] = aux->getComponent<Tapioca::AudioSourceComponent>();
    aux = object->getScene()->getHandler("ExplosiveSound");
    if (aux != nullptr) audios[ExplosionSound] = aux->getComponent<Tapioca::AudioSourceComponent>();
    aux = object->getScene()->getHandler("MainMenuMusic");
    if (aux != nullptr) audios[MainMenuMusic] = aux->getComponent<Tapioca::AudioSourceComponent>();
    aux = object->getScene()->getHandler("InGameMusic");
    if (aux != nullptr) audios[InGameMusic] = aux->getComponent<Tapioca::AudioSourceComponent>();
    aux = object->getScene()->getHandler("GameOverMenuMusic");
    if (aux != nullptr) audios[GameOverMenuMusic] = aux->getComponent<Tapioca::AudioSourceComponent>();
    aux = object->getScene()->getHandler("WinMenuMusic");
    if (aux != nullptr) audios[WinMenuMusic] = aux->getComponent<Tapioca::AudioSourceComponent>();
}

void GameManager::updateCurrentState(const std::string name) {
    currentStateName = name;
    if (currentStateName == "MainMenu") currentState = MainMenu;
    else if (currentStateName == "LoseScreen") {
        currentState = Lose;
        pushEvent("ev_GameOver", nullptr, true, true);
    }
    else if (currentStateName == "WinScreen") {
        currentState = Win;
        pushEvent("ev_GameOver", nullptr, true, true);
    }
    else if (currentStateName == "PauseMenu")
        currentState = Pause;
    else if (currentStateName == "Level1" || currentStateName == "Level2")
        currentState = InGame;
    else if (currentStateName == "RulesMenu")
        currentState = Rules;
    else if (currentStateName == "ControlsMenu")
        currentState = Controls;
}

void GameManager::clearLevel() {
    sceneLoaded = false;
    balls.clear();
    mainLoop->deleteScene(getActualLevelName());
}

void GameManager::playMilkTeaAnims() {
    milkAnimator->playAnim("Idle");
    milkAnimator->setPlaying(milkAnimator->getPlaying());
    teaAnimator->playAnim("Idle");
    teaAnimator->setPlaying(teaAnimator->getPlaying());
}

void GameManager::registerLuaFunctions() {
    std::function<void()> playFunction = [&]() { onPlayConfirmed(); };
    std::function<void()> mainMenuFunction = [&]() { onMainMenuConfirmed(); };
    std::function<void()> resumeFunction = [&]() { onResumeConfirmed(); };
    std::function<void()> continueFunction = [&]() { onContinueConfirmed(); };
    std::function<void()> restartFunction = [&]() { onRestartConfirmed(); };
    std::function<void()> controlsFunction = [&]() { onControlsConfirmed(); };
    std::function<void()> rulesFunction = [&]() { onRulesConfirmed(); };
    std::function<void()> backFunction = [&]() { onBackConfirmed(); };
    luaManager->addLuaFunction("Play", playFunction);
    luaManager->addLuaFunction("MainMenu", mainMenuFunction);
    luaManager->addLuaFunction("Resume", resumeFunction);
    luaManager->addLuaFunction("Continue", continueFunction);
    luaManager->addLuaFunction("Restart", restartFunction);
    luaManager->addLuaFunction("Controls", controlsFunction);
    luaManager->addLuaFunction("Rules", rulesFunction);
    luaManager->addLuaFunction("Back", backFunction);
}

void GameManager::update(const uint64_t deltaTime) {
    if (currentState == InGame && sceneLoaded) {
        changeTime(-((float)deltaTime));
        updateTimerText();

        if (time <= 0) updateCurrentState("LoseScreen");
        else {
            // Comprueba que todas las bolas estan inmovilizadas
            auto it = balls.begin();
            while (it != balls.end()) {
                Tapioca::RigidBody* rb = (*it)->getComponent<Tapioca::RigidBody>();
                if (rb != nullptr) {
                    auto v = rb->getVelocity();
                    auto f = rb->getTotalForce();
                    if (v.magnitude() < 1e-2 && f.magnitude() < 1e-2) {
                        rb->setVelocity(Tapioca::Vector3(0));
                        if ((*it)->getHandler() == "BallPlayer" && processing)
                            Tapioca::logInfo("BOLA PARADA??????????\n");
                        ++it;
                    }
                    else {
                        pushEvent("ev_ballMoved", nullptr, true);
                        processing = true;
                        break;
                    }
                }
            }
            //si todas las bolas estan paradas y la bola se estaba moviendo
            if (it == balls.end() && processing) {
                processing = false;
                pushEvent("ev_endProcessing", nullptr, true);
            }
        }
    }
}

void GameManager::handleEvent(std::string const& id, void* info) {
    if (id == "ev_onPlay") 
        onPlay();
    else if (id == "ev_Pause")
        pause();
    else if (id == "ev_onPause")
        onPause();
    else if (id == "ev_onResume")
        onResume();
    else if (id == "loadBalls") {
        auto v = mainLoop->getScene(getActualLevelName())->getObjects();
        for (auto& g : v) {
            ColoredBall* ball = g->getComponent<ColoredBall>();
            if (ball != nullptr) {
                balls.insert(g);
                Tapioca::RigidBody* grb = g->getComponent<Tapioca::RigidBody>();
                if (grb != nullptr) grb->setVelocity(Tapioca::Vector3(0));
                if (g->getHandler() == "BallPlayer") playerBall = g;
            }
        }
        sceneLoaded = true;
    }
    else if (id == "ev_Start")
        startGame();
    else if (id == "BallShot") {
        Tapioca::GameObject* b = ((Tapioca::GameObject*)info);
        balls.erase(b);
        if (balls.size() == 1 && currentState != Lose) updateCurrentState("WinScreen");
    }
    else if (id == "ev_GameOver")
        gameOver();
    else if (id == "BallShotWrongColor") {
        Tapioca::GameObject* b = ((Tapioca::GameObject*)info);
        balls.erase(b);
        loseLife();
        if (balls.size() == 1 && currentState != Lose) updateCurrentState("WinScreen");
    }
    else if (id == "whiteBallHasHit") {
        bool hit = *((bool*)info);
        if (!hit) loseLife();
    }
    else if (id == "blackBallIn") {
        Tapioca::GameObject* b = ((Tapioca::GameObject*)info);
        balls.erase(b);
        if (balls.size() != 1) {
            Tapioca::logInfo("Se ha metido la bola negra demasiado pronto.\n");
            updateCurrentState("LoseScreen");
        }
    }
    else if (id == "whiteBallIn") {
        if (balls.size() == 0) updateCurrentState("LoseScreen");
        else loseLife();
    }
    else if (id == "ev_pickUp")
        if (audios[PickSound] != nullptr) audios[PickSound]->playOnce();
        else if (id == "ev_explosion")
            if (audios[ExplosionSound] != nullptr) audios[ExplosionSound]->playOnce();
}

void GameManager::changeScene(std::string const& scene) {
    if (sceneLoader != nullptr) {
        Tapioca::Scene* s = sceneLoader->loadScene(scene);
        if (scene == getActualLevelName()) currentLevelScene = s;
    }
    else
        Tapioca::logWarn(("GameManager: No se ha podido cargar la escena " + scene + ".").c_str());
}

void GameManager::goToNextLevel() {
    clearLevel();
    actualLevel++;
    changeScene(getActualLevelName());
    updateCurrentState(getActualLevelName());
    pushEvent("ev_Start", nullptr, true, true);
}

void GameManager::changeScore(int s) {
    score += s;
    if (score <= 0) {
        Tapioca::logInfo("El jugador se ha quedado sin puntuacion.");
        updateCurrentState("LoseScreen");
    }
}

void GameManager::changeLife(int l) {
    life += l;
    if (life <= 0) {
        Tapioca::logInfo("El jugador se ha quedado sin vida.");
        updateCurrentState("LoseScreen");
    }
    updateLives();
}

void GameManager::loseLife() {
    life--;
    if (life <= 0) {
        Tapioca::logInfo("El jugador se ha quedado sin vidas.\n");
        updateCurrentState("LoseScreen");
    }
    updateLives();
}

void GameManager::addLife() {
    life++;
    updateLives();
}

void GameManager::changeTime(float t) {
    time += t;
    updateTimerText();
}

void GameManager::changeActualLevel(int l) { actualLevel += l; }

std::string GameManager::getActualLevelName() const { return "Level" + std::to_string(actualLevel); }

std::string GameManager::getActualLife() const { return "Lives: " + std::to_string(life); }

void GameManager::updateTimerText(int precision) {
    if (timerTextComponent != nullptr) {
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(precision) << getTime();
        timerTextComponent->setText(stream.str());
    }
}

void GameManager::updateLives() {
    if (livesTextComponent != nullptr) livesTextComponent->setText(getActualLife());
}

void GameManager::onPlay() {
    updateCurrentState(getActualLevelName());
    pushEvent("ev_Start", nullptr, true, true);
}

void GameManager::onPause() { updateCurrentState("PauseMenu"); }

void GameManager::onResume() { updateCurrentState(getActualLevelName()); }

void GameManager::startGame() {
    time = INIT_TIME * 1000;
    score = 0;
    life = INIT_LIFE;
    Tapioca::Scene* scene = mainLoop->getScene(currentStateName);
    if (scene != nullptr) {
        Tapioca::GameObject* timerText = scene->getHandler("TimerText");
        if (timerText != nullptr) timerTextComponent = timerText->getComponent<Tapioca::Text>();
        updateTimerText();
        Tapioca::GameObject* livesText = scene->getHandler("LivesText");
        if (livesText != nullptr) livesTextComponent = livesText->getComponent<Tapioca::Text>();
        updateLives();
        milkAnimator = scene->getHandler("Milk")->getComponent<Tapioca::Animator>();
        if (milkAnimator != nullptr) milkAnimator->setLoop(false);
        teaAnimator = scene->getHandler("Tea")->getComponent<Tapioca::Animator>();
        if (teaAnimator != nullptr) teaAnimator->setLoop(false);
        pushEvent("loadBalls", nullptr, true, true);
    }
    if (audios[MainMenuMusic] != nullptr) audios[MainMenuMusic]->pause(true);
    if (audios[InGameMusic] != nullptr) audios[InGameMusic]->playLooped();
    if (audios[GameOverMenuMusic] != nullptr) audios[GameOverMenuMusic]->pause(true);
    if (audios[WinMenuMusic] != nullptr) audios[WinMenuMusic]->pause(true);
}

void GameManager::gameOver() {
    clearLevel();
    if (audios[InGameMusic] != nullptr) audios[InGameMusic]->pause(true);

    switch (currentState) {
    case Lose:
        changeScene("LoseScreen");
        if (audios[GameOverMenuMusic] != nullptr) audios[GameOverMenuMusic]->playLooped();
        if (audios[WinMenuMusic] != nullptr) audios[WinMenuMusic]->pause(true);
        break;
    case Win:
        changeScene("WinScreen");
        if (audios[WinMenuMusic] != nullptr) audios[WinMenuMusic]->playLooped();
        if (audios[GameOverMenuMusic] != nullptr) audios[GameOverMenuMusic]->pause(true);
        break;
    default: Tapioca::logInfo("Se ha hecho GAMEOVER sin estar en modo Lose ni Win"); break;
    }
}

void GameManager::pause() {
    switch (currentState) {
    case InGame:
        mainLoop->getScene(getActualLevelName())->setActive(false);
        changeScene("PauseMenu");
        pushEvent("ev_onPause", nullptr, true, true);
        if (audios[InGameMusic] != nullptr) audios[InGameMusic]->pause(true);
        if (audios[GameOverMenuMusic] != nullptr) audios[GameOverMenuMusic]->pause(true);
        if (audios[WinMenuMusic] != nullptr) audios[WinMenuMusic]->pause(true);
        break;
    case Pause:
        mainLoop->getScene(getActualLevelName())->setActive(true);
        mainLoop->deleteScene("PauseMenu");
        pushEvent("ev_onResume", nullptr, true, true);
        if (audios[InGameMusic] != nullptr) audios[InGameMusic]->pause(false);
        if (audios[GameOverMenuMusic] != nullptr) audios[GameOverMenuMusic]->pause(true);
        if (audios[WinMenuMusic] != nullptr) audios[WinMenuMusic]->pause(true);
        break;
    default: Tapioca::logInfo("Se ha hecho PAUSE sin estar en modo InGame ni Pause"); break;
    }
}

void GameManager::onPlayConfirmed() {
    changeScene(getActualLevelName());
    mainLoop->deleteScene("MainMenu");
    pushEvent("ev_onPlay", nullptr, true, true);
}

void GameManager::onResumeConfirmed() { pause(); }

void GameManager::onContinueConfirmed() {
    if (actualLevel < maxLevels) {
        mainLoop->deleteScene("WinScreen");
        goToNextLevel();
    }
    else {
        actualLevel = 1;
        onMainMenuConfirmed();
    }
}

void GameManager::onRestartConfirmed() {
    switch (currentState) {
    case Lose: mainLoop->deleteScene("LoseScreen"); break;
    case Win: mainLoop->deleteScene("WinScreen"); break;
    default: Tapioca::logInfo("Se ha hecho RESTART sin estar en modo Lose ni Win"); break;
    }
    changeScene(getActualLevelName());
    pushEvent("ev_onPlay", nullptr, true, true);
}

void GameManager::onBackConfirmed() {
    switch (currentState) {
    case Rules: mainLoop->deleteScene("RulesMenu"); break;
    case Controls: mainLoop->deleteScene("ControlsMenu"); break;
    }
    std::string result = "MainMenu";
    changeScene(result);
    updateCurrentState(result);
    audios[MainMenuMusic]->pause(false);
    audios[GameOverMenuMusic]->pause(true);
    audios[WinMenuMusic]->pause(true);
}

void GameManager::onRulesConfirmed() {
    mainLoop->deleteScene("MainMenu");
    changeScene("RulesMenu");
    updateCurrentState("RulesMenu");
}

void GameManager::onControlsConfirmed() {
    mainLoop->deleteScene("MainMenu");
    changeScene("ControlsMenu");
    updateCurrentState("ControlsMenu");
}

void GameManager::onMainMenuConfirmed() {
    switch (currentState) {
    case Lose: mainLoop->deleteScene("LoseScreen"); break;
    case Win: mainLoop->deleteScene("WinScreen"); break;
    case Pause: mainLoop->deleteScene("PauseMenu"); break;
    }

    clearLevel();
    std::string result = "MainMenu";
    changeScene(result);
    updateCurrentState(result);
    audios[MainMenuMusic]->playLooped();
    audios[GameOverMenuMusic]->pause(true);
    audios[WinMenuMusic]->pause(true);
}
