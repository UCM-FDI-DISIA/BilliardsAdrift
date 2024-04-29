#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class GameObject;

}

/*
* @brief Componente que se encarga de aplicar una fuerza de explosion
*/
class JUEGO_API ExplosiveComponent : public Tapioca::Component {
private:
    float force;               // Fuerza de la explosion
    float duration;            // Duracion de la explosion
    float lifeTime;            // Tiempo de vida de la explosion
    Tapioca::GameObject* gO;   // GameObject al que pertenece el componente

    void explode(const uint64_t deltaTime);

public:
    COMPONENT_ID("ExplosiveComponent");

    ExplosiveComponent();
    ~ExplosiveComponent();
    bool initComponent(const CompMap& variables) override;
    void update(const uint64_t deltaTime) override;
    void handleEvent(std::string const& id, void* info) override;
};
