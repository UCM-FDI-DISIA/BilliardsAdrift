#include "WallComponent.h"
#include "Structure/GameObject.h"
#include "Components/AudioSourceComponent.h"
#include "ColoredBall.h"
WallComponent::WallComponent() { }

void WallComponent::start() { audio = object->getComponent<Tapioca::AudioSourceComponent>(); }

void WallComponent::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* obj = (Tapioca::GameObject*)info;
        ColoredBall* ball = obj->getComponent<ColoredBall>();
        if (ball != nullptr) {
            audio->playOnce();
        }
    }
}
