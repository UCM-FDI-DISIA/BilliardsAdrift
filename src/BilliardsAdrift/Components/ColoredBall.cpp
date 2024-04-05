#include "ColoredBall.h"

ColoredBall::ColoredBall() : ballId("") { }

bool ColoredBall::initComponent(const CompMap& variables) {
    bool fine = setValueFromMap(ballId, "ballId", variables);
    if (!fine) {
#ifdef _DEBUG
        std::cerr << "[ERROR] ColoredBall: No se pudo inicializar ballId. Se necesita esta variable.\n";
#endif
        return false;
    }

    return true;
}
