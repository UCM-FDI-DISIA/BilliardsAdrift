#include "ClockComponent.h"
#include "GameManager.h"
#include "Structure/GameObject.h"

ClockComponent::ClockComponent() : gameMngr(nullptr) { }

ClockComponent::~ClockComponent() { gameMngr = nullptr; }

void ClockComponent::start() { gameMngr = GameManager::instance(); }

void ClockComponent::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* ball = (Tapioca::GameObject*)info;
        if (ball->getHandler() == "BallPlayer") {
            if (gameMngr != nullptr) gameMngr->changeTime(TIME_ADDED);
            pushEvent("ev_pickUp", nullptr);
            object->die();
        }
    }
}
