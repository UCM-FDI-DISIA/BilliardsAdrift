#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"
#include "Utilities/Vector3.h"

/**
* @brief Componente de la bola blanca
*/
class JUEGO_API WhiteBallComponent : public Tapioca::Component {
private:
    bool hit;                      // Indica si la bola blanca ha sido golpeada
    bool collided;                 // Indica si la bola blanca ha colisionado con otra bola
    Tapioca::Vector3 iniBallPos;   // Posicion inicial de la bola blanca

public:
    COMPONENT_ID("WhiteBallComponent");

    /**
    * @brief Constructor por defecto
    */
    WhiteBallComponent();

    /**
    * @brief Metodo que se usa para recibir eventos.
    * Se llama nada mas se recibe el evento, si es un evento de ventana se recibe en el pushEvent.
    * @param id Indica el tipo de mensaje
    * @param info Puntero a void para pasar parametros
    */
    void handleEvent(std::string const& id, void* info) override;
};
