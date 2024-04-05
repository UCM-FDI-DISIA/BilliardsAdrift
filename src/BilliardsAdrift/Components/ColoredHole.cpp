#include "ColoredHole.h"
#include <Structure/GameObject.h>
#include <Structure/Scene.h>
#include "ColoredBall.h"

ColoredHole::ColoredHole() : ballId("") { }

bool ColoredHole::initComponent(const CompMap& variables) {
    bool fine = setValueFromMap(ballId, "ballId", variables);
    if (!fine) {
#ifdef _DEBUG
        std::cerr << "[ERROR] ColoredHole: No se pudo inicializar ballId. Se necesita esta variable.\n";
#endif
        return false;
    }

    return true;
}

void ColoredHole::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* obj = (Tapioca::GameObject*)info;
        ColoredBall* ball = obj->getComponent<ColoredBall>();
        if (ball != nullptr && ball->getID() == ballId) {
#ifdef _DEBUG
            std::cerr << "ColoredHole: La bola con ID " << ballId << " ha entrado en su agujero.\n";
#endif
            pushEvent("BallShot", info, true);
            obj->die();
        }
    }
}
