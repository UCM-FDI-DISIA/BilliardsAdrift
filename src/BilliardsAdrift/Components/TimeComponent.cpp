#include "TimeComponent.h"
#include "GameManager.h"
#include "Structure/GameObject.h"

TimeComponent::TimeComponent() : gameMngr(nullptr) { }

TimeComponent::~TimeComponent() { gameMngr = nullptr; }

void TimeComponent::start() { gameMngr = GameManager::instance(); }

void TimeComponent::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* ball = (Tapioca::GameObject*)info;
        if (ball->getHandler() == "BallPlayer") {
            if (gameMngr != nullptr) gameMngr->changeTime(TIME_ADDED);
            object->die();
        }
    }
}
