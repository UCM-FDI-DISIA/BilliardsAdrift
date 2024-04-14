#pragma once
#include <Structure/Component.h>
#include "gameDefs.h"

class JUEGO_API ColoredHole : public Tapioca::Component {
private:
    std::string ballId;

public:
    COMPONENT_ID("ColoredHole");

    ColoredHole();
    bool initComponent(const CompMap& variables) override;
    void handleEvent(std::string const& id, void* info) override;
};