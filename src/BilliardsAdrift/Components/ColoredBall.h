#pragma once
#include <Structure/Component.h>
#include "gameDefs.h"

class JUEGO_API ColoredBall : public Tapioca::Component {
private:
    std::string ballId;

public:
    COMPONENT_ID("ColoredBall");

    ColoredBall();
    bool initComponent(const CompMap& variables) override;
    std::string getID() const { return ballId; }
};