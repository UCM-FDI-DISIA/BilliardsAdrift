#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

class GameManager;

class JUEGO_API ClockComponent : public Tapioca::Component {

    static const int TIME_TO_ADD = 20;

private:
    GameManager* gameMng;   // Puntero al GameManager 
    
public:
    COMPONENT_ID("ClockComponent");

    ClockComponent();
    ~ClockComponent();
    void start() override;
    void handleEvent(std::string const& id, void* info) override;
};
