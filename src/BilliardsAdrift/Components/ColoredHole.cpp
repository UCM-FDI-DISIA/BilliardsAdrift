#include "ColoredHole.h"
#include <Structure/GameObject.h>
#include <Structure/Scene.h>
#include "ColoredBall.h"
#include "Components/AudioSourceComponent.h"
ColoredHole::ColoredHole() : ballId("") { }

bool ColoredHole::initComponent(const CompMap& variables) {
    if (!setValueFromMap(ballId, "ballId", variables)) {
        Tapioca::logError("ColoredHole: No se pudo inicializar ballId. Se necesita esta variable.");
        return false;
    }
    return true;
}

void ColoredHole::start() { audio = object->getComponent<Tapioca::AudioSourceComponent>(); }

void ColoredHole::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* obj = (Tapioca::GameObject*)info;
        ColoredBall* ball = obj->getComponent<ColoredBall>();

        if (ball != nullptr) {
            audio->playOnce();
            if (ball->getID() == ballId) {
                Tapioca::logInfo(
                    ("ColoredHole: La bola con ID \"" + std::string(ballId) + "\" ha entrado en su agujero.").c_str());
                pushEvent("BallShot", info, true);
                obj->die();
            }
            else if (ball->getID() == "white") {
                pushEvent("whiteBallIn", info, true);
            }
            else if (ball->getID() != ballId && ball->getID() != "black" && ball->getID() != "white") {
                Tapioca::logInfo(("ColoredHole: La bola con ID \"" + std::string(ball->getID()) +
                                  "\" ha entrado en el agujero" + std::string(ballId) + ".")
                                     .c_str());
                pushEvent("BallShotWrongColor", info, true);
                obj->die();
            }
        }
    }
}
