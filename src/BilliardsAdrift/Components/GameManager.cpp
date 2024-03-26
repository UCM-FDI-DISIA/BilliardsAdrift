#include "GameManager.h"
#include "SceneManager.h"


template class JUEGO_API Tapioca::Singleton<BilliardsAdrift::GameManager>;

template<>
BilliardsAdrift::GameManager* Tapioca::Singleton<BilliardsAdrift::GameManager>::instance_ = nullptr;

namespace BilliardsAdrift {

template class JUEGO_API Tapioca::BasicBuilder<BilliardsAdrift::GameManager>;

GameManager::GameManager() { }

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
    INIT_TIME = timeAux;
    // create();
    onStart();

    return true;
}

void GameManager::start() { }

void GameManager::update(const uint64_t deltaTime) { }

void GameManager::handleEvent(std::string const& id, void* info) { 
    if (id == "ev_Pause") {
        changeScene("PauseMenu.lua");
    }
}

void GameManager::onStart() {

}

void GameManager::onGameOver() { }

void GameManager::onWin() { }

int GameManager::getScore() { return score; }

int GameManager::getLife() { return life; }

uint64_t GameManager::getTime() { return time; }

bool GameManager::changeScene(std::string const& scene) const {
    return Tapioca::SceneManager::instance()->loadScene(scene);
}

void GameManager::setScore(const int s) { score = s; }

void GameManager::setLife(const int l) { life = l; }

void GameManager::setTime(uint64_t t) { time = t; }

void GameManager::changeScore(int s) { score += s; }

void GameManager::changeLife(int l) { life += l; }

void GameManager::changeTime(uint64_t t) { time += t; }

}