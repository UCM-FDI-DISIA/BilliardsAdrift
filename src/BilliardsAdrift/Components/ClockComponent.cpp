#include "ClockComponent.h"
#include "GameManager.h"
#include "Structure/GameObject.h"

ClockComponent::ClockComponent() : gameMng(nullptr) { }

ClockComponent::~ClockComponent() { gameMng = nullptr; }

void ClockComponent::start() { gameMng = GameManager::instance(); }

void ClockComponent::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* ball = (Tapioca::GameObject*)info;
        if (ball->getHandler() == "BallPlayer") {
            gameMng->setTime(gameMng->getTime() + TIME_TO_ADD);
            object->die();
        }
    }
}