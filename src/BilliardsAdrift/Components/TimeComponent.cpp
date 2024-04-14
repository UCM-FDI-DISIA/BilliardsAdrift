#include "TimeComponent.h"

#include "Structure/BasicBuilder.h"
#include "Components/RigidBody.h"
#include "Components/Transform.h"
#include "Structure/GameObject.h"
#include "GameManager.h"

namespace BilliardsAdrift {
TimeComponent::TimeComponent() : manager(nullptr) { }

TimeComponent::~TimeComponent() { }

bool TimeComponent::initComponent(const CompMap& variables) {
    return true;
}

void TimeComponent::start() { manager = GameManager::instance(); }

void TimeComponent::update(const uint64_t deltaTime) { }

void TimeComponent::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* ball = (Tapioca::GameObject*)info;
        if (ball->getHandler() == "BallPlayer") {
            manager->changeTime(TIME_ADDED);
            object->die();
        }
    }
}
}