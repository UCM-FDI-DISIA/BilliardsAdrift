#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class AudioSourceComponent;
}

class JUEGO_API ColoredBall : public Tapioca::Component {
private:
    std::string ballId;
    Tapioca::AudioSourceComponent* audio;

public:
    COMPONENT_ID("ColoredBall");

    ColoredBall();
    void start() override;
    bool initComponent(const CompMap& variables) override;
    inline std::string getID() const { return ballId; }
    void handleEvent(std::string const& id, void* info) override;
};