#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

class GameManager;

/**
* @brief Componente que representa un corazon y aumenta la vida del jugador al cogerlo
*/
class JUEGO_API HeartComponent : public Tapioca::Component {
private:
    static const int LIFE_TO_ADD = 1;   // Vida que se anade al coger el corazon

    GameManager* gameMngr;   // Puntero al GameManager

public:
    COMPONENT_ID("HeartComponent");

    /**
    * @brief Constructor por defecto
    */
    HeartComponent();

    /**
    * @brief Destructor por defecto
    */
    ~HeartComponent();

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
