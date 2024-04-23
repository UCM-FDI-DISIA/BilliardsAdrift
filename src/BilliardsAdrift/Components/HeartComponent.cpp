#include "HeartComponent.h"
#include "GameManager.h"
#include "Structure/GameObject.h"

HeartComponent::HeartComponent() : gameMng(nullptr) { }

HeartComponent::~HeartComponent() { gameMng = nullptr; }

void HeartComponent::start() { gameMng = GameManager::instance(); }

void HeartComponent::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* ball = (Tapioca::GameObject*)info;
        if (ball->getHandler() == "BallPlayer") {
            gameMng->setLife(gameMng->getLife() + 1);
            object->die();
        }
    }
}
