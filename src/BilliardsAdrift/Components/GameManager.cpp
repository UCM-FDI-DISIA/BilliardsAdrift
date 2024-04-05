#include "GameManager.h"
#include "SceneManager.h"


#include <iomanip>

template class JUEGO_API Tapioca::Singleton<BilliardsAdrift::GameManager>;

template<>
BilliardsAdrift::GameManager* Tapioca::Singleton<BilliardsAdrift::GameManager>::instance_ = nullptr;

namespace BilliardsAdrift {

GameManager::GameManager() : INIT_TIME(0), INIT_LIFE(0), time(0), life(0), state(MainMenu), score(0) { }

bool initComponent(const CompMap& variables) { return false; }

bool GameManager::initComponent(const CompMap& variables) {

    bool initLifeSet = setValueFromMap(INIT_LIFE, "initLife", variables);
    if (!initLifeSet) {
#ifdef _DEBUG
        std::cerr << "Error: GameManager: no se pudo inicializar INIT_LIFE.\n";
#endif
        return false;
    }
    float timeAux;
    bool initTimeSet = setValueFromMap(timeAux, "initTime", variables);
    if (!initTimeSet) {
#ifdef _DEBUG
        std::cerr << "Error: GameManager: no se pudo inicializar INIT_TIME.\n";
#endif
        return false;
    }
    INIT_TIME = (long long int)timeAux;
    // create();
    onStart();

    return true;
}

void GameManager::start() { state = InGame; }

void GameManager::update(const uint64_t deltaTime) {
    if (state == InGame) {
        time -= deltaTime;
#ifdef _DEBUG
        //std::cout << std::fixed << std::setprecision(2) << time / 1000. << "\n";
#endif
        if (time <= 0) {
            state = Pause;
            changeScene("PauseMenu.lua");
#ifdef _DEBUG 
            std::cout << "El jugador se ha quedado sin tiempo.\n";
#endif
            pushEvent("ev_GameOver", nullptr);
        }
    }
}

void GameManager::handleEvent(std::string const& id, void* info) {
    if (id == "ev_Pause") {
        changeScene("PauseMenu.lua");
    }
    if (id == "ev_GameOver") {
        onGameOver();
    }
}

void GameManager::onStart() {
    time = INIT_TIME * 1000;
    score = 0;
    life = INIT_LIFE;
}

void GameManager::onGameOver() { }

void GameManager::onWin() { }

int GameManager::getScore() { return score; }

int GameManager::getLife() { return life; }

uint64_t GameManager::getTime() { return (uint64_t)(time / 1000.f); }

bool GameManager::changeScene(std::string const& scene) const {
    return Tapioca::SceneManager::instance()->loadScene(scene);
}

void GameManager::setScore(const int s) { score = s; }

void GameManager::setLife(const int l) { life = l; }

void GameManager::setTime(uint64_t t) { time = t * 1000; }

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