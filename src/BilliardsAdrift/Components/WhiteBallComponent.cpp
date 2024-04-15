#include "WhiteBallComponent.h"
#include "ColoredBall.h"
#include "Structure/GameObject.h"
WhiteBallComponent::WhiteBallComponent() : collided(false), hit(false) { }

bool WhiteBallComponent::initComponent(const CompMap& variables) { return true; }

void WhiteBallComponent::handleEvent(std::string const& id, void* info) {
    if (hit && id == "onCollisionEnter") {
        Tapioca::GameObject* obj = (Tapioca::GameObject*)info;
        ColoredBall* ball = obj->getComponent<ColoredBall>();
        if (ball != nullptr) {
            collided = true;
        }
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
}
