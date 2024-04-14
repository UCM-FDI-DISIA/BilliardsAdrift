#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"
#include "Utilities/Vector2.h"
#include "Utilities/Vector3.h"

namespace Tapioca {
class RigidBody;
}

namespace BilliardsAdrift {
class JUEGO_API Accelerator : public Tapioca::Component {
private:
    Tapioca::RigidBody* rb;

    float speedFactor; //lo multiplica con su velocidad original 

public:
    COMPONENT_ID("Accelerator");

    Accelerator();
    ~Accelerator() { }
    bool initComponent(const CompMap& variables) override;
    void start() override;
    void handleEvent(std::string const& id, void* info);
};
}