#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

class GameManager;

/**
* @brief Componente que representa un reloj y aumenta el tiempo del juego al cogerlo por algun objeto
*/
class JUEGO_API ClockComponent : public Tapioca::Component {
private:
    GameManager* gameMngr;            // Puntero al GameManager
    const float TIME_ADDED = 60000.0f;   // Tiempo que se anade al coger el reloj

public:
    COMPONENT_ID("ClockComponent");

    /**
    * @brief Constructor por defecto
    */
    ClockComponent();

    /**
    * @brief Destructor por defecto
    */
    ~ClockComponent();

    /**
    * @brief Coge referencia al GameManager
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
