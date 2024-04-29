#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class AudioSourceComponent;
}
class JUEGO_API WallComponent : public Tapioca::Component {
private:
    Tapioca::AudioSourceComponent* audio;

public:
    COMPONENT_ID("WallComponent");

    WallComponent();
    void start() override;
    void handleEvent(std::string const& id, void* info) override;
};