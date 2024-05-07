#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"
#include "Utilities/Vector2.h"
#include "Utilities/Vector3.h"
#include "WindowManager.h"

namespace Tapioca {
class Transform;
class RigidBody;
class GameObject;
class MeshRenderer;
class InputManager;
class ProgressBar;
class Line;
class AudioSourceComponent;
}

/**
* @brief Componente que controla el palo de billar
*/
class JUEGO_API CueController : public Tapioca::Component {
private:
    Tapioca::Transform* tr;                    // Transform del palo
    Tapioca::Transform* ballTr;                // Transform de la bola
    Tapioca::RigidBody* ballRb;                // RigidBody de la bola
    Tapioca::GameObject* ball;                 // Objeto Bola
    Tapioca::Transform* trayectoryTransform;   // Transform de la trayectoria
    Tapioca::MeshRenderer* trayectoryMesh;     // Mesh de la trayectoria
    Tapioca::MeshRenderer* mesh;               // Mesh del palo
    Tapioca::InputManager* inputMng;           // Puntero al InputManager
    Tapioca::AudioSourceComponent* audio;      // Efecto de sonido del palo
    Tapioca::Vector2 mouseLastPosition;        // Posicion del raton en el ultimo frame
    Tapioca::Vector3 ballDistanceOffset;       // Offset de la bola

    int64_t impulseTime;   // Tiempo de impulso en milisegundos

    float powerFactor;    // Incremento de fuerza para tirar la bola
    float maxPower;       // Fuerza maxima para tirar la bola
    float moveFactor;     // Factor de movimiento del palo
    float rotateFactor;   // Factor de movimiento del palo hacia atras

    float actualPower;            // Fuerza acumulada para tirar la bola
    Tapioca::Vector3 moveSpeed;   // Velocidad de movimiento del palo
    bool hitting;                 // Indica si se esta golpeando la bola
    bool canMove;                 // Indica si se puede mover el palo
    Tapioca::Vector3 trayectoryScale;

    Tapioca::WindowManager* windowMng;   // Gestor de ventanas
    Tapioca::GameObject* powerBar;       // Barra de fuerza
    Tapioca::ProgressBar* powerBarPB;    // Componente de la barra de progreso de la barra de fuerza

    /**
    * @brief Actualiza la posicion del palo
    */
    void updatePosition();
    /**
    * @brief Actualiza la rotacion del palo
    */
    void updateRotation();
    /**
    * @brief Incrementa la fuerza del golpe
    */
    void increasePower();
    /**
    * @brief Golpea la bola
    */
    void hit();
    /**
    * @brief Resetea la posicion del palo, la fuerza, la trayectoria, la barra de fuerza
    */
    void resetCue();
    /**
    * @brief Resetea la trayectoria
    */
    void resetTrayectory();
    /**
    * @brief Sigue la bola
    */
    void followBall();
    /**
    * @brief Traduce un vector local a un vector global
    */
    Tapioca::Vector3 translateToWorld(const Tapioca::Vector3& direction);

    void updatePowerBar(float power = 0);

public:
    COMPONENT_ID("CueController");

    /**
    * @brief Constructor por defecto
    */
    CueController();
    /**
    * @brief Destructor por defecto
    */
    ~CueController();

    /**
    * @brief Metodo que se usa para recibir los parametros iniciales y guardarlos.
    * No garantiza que todos los componentes iniciales esten creados
    * @param variables unordered_map con los parametros iniciales
    * @return Devuelve true si se ha inicializado correctamente, false en caso contrario
    */
    bool initComponent(const CompMap& variables) override;
    /**
    * @brief Coge referencia de los componentes necesarios
    */
    void start() override;
    /**
    * @brief Seguimiento de la bola o golpeo de la bola
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
