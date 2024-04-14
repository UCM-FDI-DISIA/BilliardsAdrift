#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"
#include "Utilities/Vector2.h"
#include "Utilities/Vector3.h"

namespace Tapioca {
class RigidBody;
class Transform;
}

namespace BilliardsAdrift {
class JUEGO_API MovableWall : public Tapioca::Component {
private:
    Tapioca::RigidBody* rb;
    Tapioca::Transform* tr;

    Tapioca::Vector2 origin;//posici�n inicial
    Tapioca::Vector2 dest;//posici�n final
    Tapioca::Vector2 direction;

    Tapioca::Vector2 actualDest;

    float speed;

public:
    COMPONENT_ID("MovableWall");

    MovableWall();
    ~MovableWall() { }
    bool initComponent(const CompMap& variables) override;
    void start() override;
    void update(const uint64_t deltaTime) override;
};
}