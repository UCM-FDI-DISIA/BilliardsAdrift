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

template class JUEGO_API Tapioca::Singleton<GameManager>;
template<>
GameManager* Tapioca::Singleton<GameManager>::instance_ = nullptr;

GameManager::GameManager()
    : sceneLoader(nullptr), mainLoop(nullptr), luaManager(nullptr), firstStateName(""), currentStateName(""),
      currentState(), currentLevelScene(nullptr), INIT_TIME(0), INIT_LIFE(0), time(0), life(0), score(0),
      processing(false), actualLevel(1), maxLevels(2), lives(nullptr), timerText(nullptr), timerTextComponent(nullptr),
      sceneLoaded(false) { }

GameManager::~GameManager() {
    sceneLoader = nullptr;
    mainLoop = nullptr;
    luaManager = nullptr;
    currentLevelScene = nullptr;
    lives = nullptr;
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

        if (time <= 0) pushEvent("ev_GameOver", nullptr, true);

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
    if (id == "ev_onPlay") onPlay();
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
                g->getComponent<Tapioca::RigidBody>()->setVelocity(Tapioca::Vector3(0));
            }
        }
        sceneLoaded = true;
    }
    else if (id == "ev_Start")
        startGame();
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

void GameManager::changeScene(std::string const& scene) {
    if (sceneLoader != nullptr) {
        Tapioca::Scene* s = sceneLoader->loadScene(scene);
        if (scene == getActualLevelName()) currentLevelScene = s;
    }
    else
        Tapioca::logWarn(("GameManager: No se ha podido cargar la escena " + scene + ".").c_str());
}

void GameManager::goToNextLevel() {
    sceneLoaded = false;
    mainLoop->deleteScene(getActualLevelName());
    balls.clear();
    actualLevel++;
    changeScene(getActualLevelName());
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
}

void GameManager::loseLife() {
    life--;
    if (life > 0) {
        Tapioca::GameObject* liveToDelete = currentLevelScene->getHandler("Lives" + std::to_string(life));
        if (liveToDelete != nullptr) liveToDelete->die();
    }
    else {
        Tapioca::logInfo("El jugador se ha quedado sin vidas.\n");
        updateCurrentState("LoseScreen");
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

void GameManager::updateLives() {
    if (currentLevelScene == nullptr) {
        Tapioca::logWarn("GameManager: No se ha encontrado la escena actual.");
        return;
    }
    lives = currentLevelScene->getHandler("Lives");
    if (lives == nullptr) {
        Tapioca::logWarn("GameManager: No se ha encontrado el objeto Lives.");
        return;
    }
    Tapioca::Transform* livesTransform = lives->getComponent<Tapioca::Transform>();
    if (livesTransform == nullptr) {
        Tapioca::logWarn("GameManager: No se ha encontrado el componente Transform en Lives.");
        return;
    }
    Tapioca::Image* livesImage = lives->getComponent<Tapioca::Image>();
    if (livesImage == nullptr) {
        Tapioca::logWarn("GameManager: No se ha encontrado el componente Image en Lives.");
        return;
    }
    std::string livesImagePath = "";
    livesImagePath = livesImage->getImagePath();
    for (int i = 1; i < life; ++i) {
        Tapioca::GameObject* life = new Tapioca::GameObject();
        Tapioca::Transform* transform = life->addComponent<Tapioca::Transform>();
        if (transform != nullptr) {
            Tapioca::Vector3 initialPos = livesTransform->getPosition();
            Tapioca::Vector3 initialScale = livesTransform->getScale();
            transform->setPosition(Tapioca::Vector3(initialPos.x + (initialScale.x + 10.0f) * i, initialPos.y, 0.0f));
            transform->setScale(initialScale);
        }
        Tapioca::Image* image = life->addComponent<Tapioca::Image>({{"imagePath", livesImagePath}});
        image->awake();
        image->start();
        currentLevelScene->addObject(life, "Lives" + std::to_string(i));
    }
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
        updateLives();
        pushEvent("loadBalls", nullptr, true, true);
    }
}

void GameManager::gameOver() {
    sceneLoaded = false;
    balls.clear();

    switch (currentState) {
    case Lose:
        mainLoop->deleteScene(getActualLevelName());
        changeScene("LoseScreen");
        break;
    case Win:
        mainLoop->deleteScene(getActualLevelName());
        changeScene("WinScreen");
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
        break;
    case Pause:
        mainLoop->getScene(getActualLevelName())->setActive(true);
        mainLoop->deleteScene("PauseMenu");
        pushEvent("ev_onResume", nullptr, true, true);
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
    switch (currentState) {
    case Lose:
        mainLoop->deleteScene("LoseScreen");
        changeScene(getActualLevelName());
        pushEvent("ev_onPlay", nullptr, true, true);
        break;
    case Win:
        mainLoop->deleteScene("WinScreen");
        changeScene(getActualLevelName());
        pushEvent("ev_onPlay", nullptr, true, true);
        break;
    default: Tapioca::logInfo("Se ha hecho RESTART sin estar en modo Lose ni Win"); break;
    }
}

void GameManager::onMainMenuConfirmed() {
    switch (currentState) {
    case Lose: mainLoop->deleteScene("LoseScreen"); break;
    case Win: mainLoop->deleteScene("WinScreen"); break;
    case Pause: mainLoop->deleteScene("PauseMenu"); break;
    }

    balls.clear();
    sceneLoaded = false;
    mainLoop->deleteScene(getActualLevelName());
    std::string result = "MainMenu";
    changeScene(result);
    updateCurrentState(result);
}
