#include "GameManager.h"
#include "SceneManager.h"
#include "Structure/GameObject.h"
#include "Structure/Scene.h"
#include "Components/RigidBody.h"
#include "Components/Animator.h"

#include <iomanip>

template class JUEGO_API Tapioca::Singleton<BilliardsAdrift::GameManager>;

template<>
BilliardsAdrift::GameManager* Tapioca::Singleton<BilliardsAdrift::GameManager>::instance_ = nullptr;

namespace BilliardsAdrift {

GameManager::GameManager()
    : INIT_TIME(0), INIT_LIFE(0), time(0), life(0), state(MainMenu), score(0), processing(false) { }

bool initComponent(const CompMap& variables) { return false; }

bool GameManager::initComponent(const CompMap& variables) {
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
    state = InGame;
    onStart();
}

void GameManager::update(const uint64_t deltaTime) {
    if (state == InGame) {
        time -= deltaTime;

#ifdef _DEBUG
        //std::cout << std::fixed << std::setprecision(2) << time / 1000. << "\n";
        if (time <= 0) {
            state = Pause;
            changeScene("PauseMenu.lua");
#ifdef _DEBUG
            std::cout << "El jugador se ha quedado sin tiempo.\n";
#endif
            pushEvent("ev_GameOver", nullptr);
        }
#endif
        //comprobar que todas las bolas están inmovilizadas
        if (processing) {
            auto it = balls.begin();

            while (it != balls.end()) {

                auto v = (*it)->getComponent<Tapioca::RigidBody>()->getVelocity();
                if (std::abs(v.x < 1e-3) && std::abs(v.y < 1e-3) && std::abs(v.z < 1e-3)) {
                    ++it;
                }
                else
                    break;
            }
            if (it == balls.end()) {
                processing = false;
                pushEvent("ev_endProcessing", nullptr, true);
            }
        }
    }
}

void GameManager::handleEvent(std::string const& id, void* info) {
    if (id == "ev_Pause") {
        changeScene("PauseMenu.lua");
    }
    else if (id == "ev_Processing") {
        processing = true;
    }
    else if (id == "ev_ToggleAnim") {
        Tapioca::Animator* animator =
            getObject()->getScene()->getHandler("Sinbad")->getComponent<Tapioca::Animator>();

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
}


void GameManager::onStart() {
    time = INIT_TIME * 1000;
    score = 0;
    life = INIT_LIFE;
    auto v = object->getScene()->getObjects();
    for (auto& g : v) {
        std::string s = "Ball";
        if (strstr(g->getHandler().c_str(), s.c_str())) {

            balls.insert(g);
        }
    }
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