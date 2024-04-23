#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"
#include "Utilities/Vector3.h"

class JUEGO_API WhiteBallComponent : public Tapioca::Component {
private:
    bool hit;                      // Indica si la bola blanca ha sido golpeada
    bool collided;                 // Indica si la bola blanca ha colisionado con otra bola
    Tapioca::Vector3 iniBallPos;   // Posicion inicial de la bola blanca

public:
    COMPONENT_ID("WhiteBallComponent");

    WhiteBallComponent();
    void handleEvent(std::string const& id, void* info) override;
};
