#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class RigidBody;
}

class JUEGO_API Accelerator : public Tapioca::Component {
private:
    Tapioca::RigidBody* rb;   // Puntero al rigidbody del objeto
    float speedFactor;        // Multiplicador de velocidad

public:
    COMPONENT_ID("Accelerator");

    Accelerator();
    ~Accelerator();
    bool initComponent(const CompMap& variables) override;
    void start() override;
    void handleEvent(std::string const& id, void* info);
};
