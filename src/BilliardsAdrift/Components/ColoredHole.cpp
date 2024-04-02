#include "ColoredHole.h"
#include <Structure/GameObject.h>
#include <Structure/Scene.h>

ColoredHole::ColoredHole() : ballName(""), ball(nullptr) { }

bool ColoredHole::initComponent(const CompMap& variables) {
    bool fine = setValueFromMap(ballName, "ballName", variables);
    if (!fine) {
#ifdef _DEBUG
        std::cerr << "[ERROR] ColoredHole: No se pudo inicializar ballName. Se necesita esta variable.\n";
#endif
        return false;
    }

    return true;
}

void ColoredHole::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        if (info == ball) {
#ifdef _DEBUG
            std::cerr << "ColoredHole: La bola " << ballName << " ha entrado en su agujero.\n";
#endif
            ball->die();
        }
    }
}

void ColoredHole::start() {
    ball = object->getScene()->getHandler(ballName);
    if (ball == nullptr) {
#ifdef _DEBUG
        std::cerr << "[ERROR] ColoredHole: No se ha encontrado la bola con la id " << ballName << ".\n";
#endif
        alive = false;
    }
}
