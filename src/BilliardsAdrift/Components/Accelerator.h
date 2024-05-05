#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class RigidBody;
}

/**
* @brief Componente que acelera un objeto en una direccion
*/
class JUEGO_API Accelerator : public Tapioca::Component {
private:
    float speedFactor;        // Multiplicador de velocidad

public:
    COMPONENT_ID("Accelerator");

    /**
    * @brief Constructor por defecto
    */
    Accelerator();

    /**
    * @brief Metodo que se usa para recibir los parametros iniciales y guardarlos.
    * No garantiza que todos los componentes iniciales esten creados
    * @param variables unordered_map con los parametros iniciales
    * @return Devuelve true si se ha inicializado correctamente, false en caso contrario
    */
    bool initComponent(const CompMap& variables) override;
    /**
    * @brief Metodo que se usa para recibir eventos.
    * Se llama nada mas se recibe el evento, si es un evento de ventana se recibe en el pushEvent.
    * @param id Indica el tipo de mensaje
    * @param info Puntero a void para pasar parametros
    */
    void handleEvent(std::string const& id, void* info);
};
