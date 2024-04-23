#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

class JUEGO_API ColoredBall : public Tapioca::Component {
private:
    std::string ballId;

public:
    COMPONENT_ID("ColoredBall");

    ColoredBall();
    bool initComponent(const CompMap& variables) override;
    inline std::string getID() const { return ballId; }
};