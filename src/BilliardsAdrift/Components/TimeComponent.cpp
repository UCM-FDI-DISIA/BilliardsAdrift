#include "TimeComponent.h"
#include "GameManager.h"
#include "Structure/GameObject.h"

TimeComponent::TimeComponent() : gameMng(nullptr) { }

TimeComponent::~TimeComponent() { gameMng = nullptr; }

void TimeComponent::start() { gameMng = GameManager::instance(); }

void TimeComponent::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* ball = (Tapioca::GameObject*)info;
        if (ball->getHandler() == "BallPlayer") {
            gameMng->changeTime(TIME_ADDED);
            object->die();
        }
    }
}
