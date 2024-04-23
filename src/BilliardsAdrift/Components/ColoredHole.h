#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

class JUEGO_API ColoredHole : public Tapioca::Component {
private:
    std::string ballId;

public:
    COMPONENT_ID("ColoredHole");

    ColoredHole();
    bool initComponent(const CompMap& variables) override;
    void handleEvent(std::string const& id, void* info) override;
};