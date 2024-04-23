#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

class GameManager;

class JUEGO_API TimeComponent : public Tapioca::Component {
private:
    GameManager* gameMng;
    const float TIME_ADDED = 1.0f;

public:
    COMPONENT_ID("TimeComponent");

    TimeComponent();
    ~TimeComponent();
    void start() override;
    void handleEvent(std::string const& id, void* info) override;
};
