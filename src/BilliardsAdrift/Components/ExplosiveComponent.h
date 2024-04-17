#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class GameObject;
}

namespace BilliardsAdrift {
class JUEGO_API ExplosiveComponent : public Tapioca::Component {
private:
    float force;
    float duration;
    float lifeTime;
    Tapioca::GameObject* gO; 
    void explode(const uint64_t deltaTime);

public:
    COMPONENT_ID("ExplosiveComponent");

    ExplosiveComponent();
    ~ExplosiveComponent();
    bool initComponent(const CompMap& variables) override;
    void update(const uint64_t deltaTime) override;
    void handleEvent(std::string const& id, void* info) override;
};

}
