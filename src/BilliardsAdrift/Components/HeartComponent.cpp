#include "HeartComponent.h"
#include "GameManager.h"
#include "Structure/GameObject.h"

HeartComponent::HeartComponent() : gameMngr(nullptr) { }

HeartComponent::~HeartComponent() { gameMngr = nullptr; }

void HeartComponent::start() { gameMngr = GameManager::instance(); }

void HeartComponent::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* ball = (Tapioca::GameObject*)info;
        if (ball->getHandler() == "BallPlayer") {
            if (gameMngr != nullptr) gameMngr->setLife(gameMngr->getLife() + LIFE_TO_ADD);
            pushEvent("ev_pickUp", nullptr);
            object->die();
        }
    }
}
