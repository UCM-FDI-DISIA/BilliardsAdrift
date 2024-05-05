#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class GameObject;

}

/**
* @brief Componente que se encarga de aplicar una fuerza de explosion
*/
class JUEGO_API ExplosiveComponent : public Tapioca::Component {
private:
    float force;               // Fuerza de la explosion
    float duration;            // Duracion de la explosion
    float lifeTime;            // Tiempo de vida de la explosion
    Tapioca::GameObject* gO;   // GameObject al que pertenece el componente

    /**
    * @brief Modifica la posicion del objeto en funcion de la fuerza de la explosion
    */
    void explode(const uint64_t deltaTime);

public:
    COMPONENT_ID("ExplosiveComponent");

    /**
    * @brief Constructor por defecto
    */
    ExplosiveComponent();

    /**
    * @brief Destructor por defecto
    */
    ~ExplosiveComponent();

    /**
    * @brief Metodo que se usa para recibir los parametros iniciales y guardarlos.
    * No garantiza que todos los componentes iniciales esten creados
    * @param variables unordered_map con los parametros iniciales
    * @return Devuelve true si se ha inicializado correctamente, false en caso contrario
    */
    bool initComponent(const CompMap& variables) override;
    /**
    * @brief Aplica la fuerza de la explosion
    */
    void update(const uint64_t deltaTime) override;
    /**
    * @brief Metodo que se usa para recibir eventos.
    * Se llama nada mas se recibe el evento, si es un evento de ventana se recibe en el pushEvent.
    * @param id Indica el tipo de mensaje
    * @param info Puntero a void para pasar parametros
    */
    void handleEvent(std::string const& id, void* info) override;
};
