#include "WhiteBallComponent.h"
#include "ColoredBall.h"
#include "Structure/GameObject.h"
#include "Components/Transform.h"
#include "Components/RigidBody.h"
#include "Structure/Scene.h"

WhiteBallComponent::WhiteBallComponent() : collided(false), hit(false), iniBallPos(Tapioca::Vector3()) { }

void WhiteBallComponent::handleEvent(std::string const& id, void* info) {
    if (hit && id == "onCollisionEnter") {
        Tapioca::GameObject* obj = (Tapioca::GameObject*)info;
        ColoredBall* ball = obj->getComponent<ColoredBall>();
        if (ball != nullptr) collided = true;
    }
    else if (id == "ev_MouseButtonDownLeft") {
        iniBallPos = object->getComponent<Tapioca::Transform>()->getPosition();
    }
    else if (hit && id == "ev_endProcessing") {
        hit = false;
        pushEvent("whiteBallHasHit", &collided, true);
        collided = false;
    }
    else if (!hit && id == "cueShot") {
        hit = true;
        collided = false;
    }
    else if (id == "whiteBallIn") {
        hit = false;
        object->getComponent<Tapioca::Transform>()->setPosition(iniBallPos);
        Tapioca::RigidBody* aux = object->getComponent<Tapioca::RigidBody>();
        if (aux != nullptr) {
            aux->clearAllForcesAndVelocities();
        }
    }
}
