#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace BilliardsAdrift {
class GameManager;

class JUEGO_API TimeComponent : public Tapioca::Component {
private:
    GameManager* manager;
    static const float TIME_ADDED;

public:
    COMPONENT_ID("TimeComponent");

    TimeComponent();
    ~TimeComponent();
    bool initComponent(const CompMap& variables) override;
    void start() override;
    void update(const uint64_t deltaTime) override;
    void handleEvent(std::string const& id, void* info) override;
};
const float TimeComponent::TIME_ADDED = 1.0f;
}
