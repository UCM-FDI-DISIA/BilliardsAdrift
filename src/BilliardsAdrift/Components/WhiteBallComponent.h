#pragma once
#include <Structure/Component.h>
#include "gameDefs.h"
#include "Utilities/Vector3.h"

namespace Tapioca {
class MainLoop;
}

class JUEGO_API WhiteBallComponent : public Tapioca::Component {
private:
    bool hit;
    bool collided;
    Tapioca::Vector3 iniBallPos;
    Tapioca::MainLoop* mainLoop;

public:
    COMPONENT_ID("WhiteBallComponent");

    WhiteBallComponent();
    bool initComponent(const CompMap& variables) override;
    void handleEvent(std::string const& id, void* info) override;
};