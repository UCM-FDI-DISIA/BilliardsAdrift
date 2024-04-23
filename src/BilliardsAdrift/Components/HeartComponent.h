#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

class GameManager;

class JUEGO_API HeartComponent : public Tapioca::Component {
private:
    GameManager* gameMng; // Puntero al GameManager

public:
    COMPONENT_ID("HeartComponent");
    
    HeartComponent();
    ~HeartComponent();
    void start() override;
    void handleEvent(std::string const& id, void* info) override;
};
