#include "ColoredBall.h"
#include "Structure/GameObject.h"
#include "Components/AudioSourceComponent.h"

ColoredBall::ColoredBall() : ballId("") { }

bool ColoredBall::initComponent(const CompMap& variables) {
    if (!setValueFromMap(ballId, "ballId", variables)) {
        Tapioca::logError("ColoredBall: No se pudo inicializar ballId. Se necesita esta variable.");
        return false;
    }
    return true;
}

void ColoredBall::start() {
    audio = object->getComponent<Tapioca::AudioSourceComponent>();
}

void ColoredBall::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* obj = (Tapioca::GameObject*)info;
        ColoredBall* ball = obj->getComponent<ColoredBall>();
        if (ball != nullptr) {
            audio->pause(true);
            audio->playOnce();
        }
    }
}