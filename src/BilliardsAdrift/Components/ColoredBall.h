#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"

namespace Tapioca {
class AudioSourceComponent;
}

/**
* @brief Componente que representa una bola de color
*/
class JUEGO_API ColoredBall : public Tapioca::Component {
private:
    // warning C4251 'ColoredBall::ballId' :
    // class 'std::basic_string<char,std::char_traits<char>,std::allocator<char>>' necesita tener una interfaz DLL
    // para que la utilicen los clientes de class 'ColoredBall'
#ifdef _MSC_VER
#pragma warning(disable : 4251)
#endif
    std::string ballId;   // Color de la bola
#ifdef _MSC_VER
#pragma warning(default : 4251)
#endif

    Tapioca::AudioSourceComponent* audio; // Efecto de sonido de la bola

public:
    COMPONENT_ID("ColoredBall");

    /**
    * @brief Constructor por defecto
    */
    ColoredBall();

    /**
    * @brief Metodo que se usa para recibir los parametros iniciales y guardarlos.
    * No garantiza que todos los componentes iniciales esten creados
    * @param variables unordered_map con los parametros iniciales
    * @return Devuelve true si se ha inicializado correctamente, false en caso contrario
    */
    bool initComponent(const CompMap& variables) override;
    /**
    * @brief Coge el componente AudioSourceComponent del objeto
    */
    void start() override;
    /**
    * @brief Metodo que se usa para recibir eventos.
    * Se llama nada mas se recibe el evento, si es un evento de ventana se recibe en el pushEvent.
    * @param id Indica el tipo de mensaje
    * @param info Puntero a void para pasar parametros
    */
    void handleEvent(std::string const& id, void* info) override;

    /**
    * @brief Devuelve el color de la bola
    * @return Color de la bola
    */
    inline std::string getID() const { return ballId; }
};