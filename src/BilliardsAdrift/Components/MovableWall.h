#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"
#include "Utilities/Vector2.h"
#include "Utilities/Vector3.h"

namespace Tapioca {
class RigidBody;
class Transform;
}

class JUEGO_API MovableWall : public Tapioca::Component {
private:
    Tapioca::RigidBody* rb;   // RigidBody del objeto
    Tapioca::Transform* tr;   // Transform del objeto

    Tapioca::Vector2 origin;      // Posicion inicial
    Tapioca::Vector2 dest;        // Posicion final
    Tapioca::Vector2 direction;   // Direccion de movimiento

    float speed;   // Velocidad de movimiento

public:
    COMPONENT_ID("MovableWall");

    MovableWall();
    ~MovableWall();
    bool initComponent(const CompMap& variables) override;
    void start() override;
    void update(const uint64_t deltaTime) override;
};
