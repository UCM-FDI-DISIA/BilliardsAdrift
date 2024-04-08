#include "ColoredBall.h"

ColoredBall::ColoredBall() : ballId("") { }

bool ColoredBall::initComponent(const CompMap& variables) {
    if (!setValueFromMap(ballId, "ballId", variables)) {
        Tapioca::logError("ColoredBall: No se pudo inicializar ballId. Se necesita esta variable.");
        return false;
    }

    return true;
}
