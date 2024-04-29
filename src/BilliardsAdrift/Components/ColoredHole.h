#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class AudioSourceComponent;
}
class JUEGO_API ColoredHole : public Tapioca::Component {
private:
    std::string ballId;
    Tapioca::AudioSourceComponent* audio;

public:
    COMPONENT_ID("ColoredHole");

    ColoredHole();
    bool initComponent(const CompMap& variables) override;
    void start() override;
    void handleEvent(std::string const& id, void* info) override;
};