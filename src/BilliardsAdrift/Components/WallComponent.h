#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class AudioSourceComponent;
}

/**
* @brief Componente que representa una pared y reproduce un sonido al colisionar con ella
*/
class JUEGO_API WallComponent : public Tapioca::Component {
protected:
    Tapioca::AudioSourceComponent* audio;  // Puntero al componente de audio

public:
    COMPONENT_ID("WallComponent");

    /**
    * @brief Constructor por defecto
    */
    WallComponent();

    /**
    * @brief Coge referencia al componente de audio
    */
    void start() override;
    /**
    * @brief Metodo que se usa para recibir eventos.
    * Se llama nada mas se recibe el evento, si es un evento de ventana se recibe en el pushEvent.
    * @param id Indica el tipo de mensaje
    * @param info Puntero a void para pasar parametros
    */
    void handleEvent(std::string const& id, void* info) override;
};
