#pragma once
#include <Structure/Component.h>
#include "gameDefs.h"

class JUEGO_API WhiteBallComponent : public Tapioca::Component {
private:
    bool hit;
    bool collided;

public:
    COMPONENT_ID("WhiteBallComponent");

    WhiteBallComponent();
    bool initComponent(const CompMap& variables) override;
    void handleEvent(std::string const& id, void* info) override;
};