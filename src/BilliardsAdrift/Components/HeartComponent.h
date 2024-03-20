#pragma once
#include "../gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class RigidBody;
class Transform;
}

namespace BilliardsAdrift {
class GameManager;

class JUEGO_API HeartComponent : public Tapioca::Component {
private:
    Tapioca::RigidBody* rb;
    Tapioca::Transform* tr;
    GameManager* gameM;

    //bool active;

public:
    COMPONENT_ID("HeartComponent");
    
    HeartComponent();
    ~HeartComponent();
    bool initComponent(const CompMap& variables) override;
    void start() override;
    void update(const uint64_t deltaTime) override;
    void handleEvent(std::string const& id, void* info) override;
};
}
