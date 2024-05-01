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

/*
* @brief Componente que controla el palo de billar
*/
class JUEGO_API CueController : public Tapioca::Component {
private:
    Tapioca::Transform* tr;
    Tapioca::Transform* ballTr;
    Tapioca::RigidBody* ballRb;
    Tapioca::GameObject* ball;
    Tapioca::MeshRenderer* mesh;
    Tapioca::InputManager* inputMng;
    Tapioca::AudioSourceComponent* audio;
    Tapioca::Vector2 mouseLastPosition;
    Tapioca::Vector3 ballDistanceOffset;

    int64_t impulseTime;   // Tiempo de impulso en milisegundos

    float powerFactor;    // Incremento de fuerza para tirar la bola
    float maxPower;       // Fuerza maxima para tirar la bola
    float moveFactor;     // Factor de movimiento del palo
    float rotateFactor;   // Factor de movimiento del palo hacia atras

    float actualPower;            // Fuerza acumulada para tirar la bola
    Tapioca::Vector3 moveSpeed;   // Velocidad de movimiento del palo
    bool hitting;                 // Indica si se esta golpeando la bola
    bool canMove;                 // Indica si se puede mover el palo

    void updatePosition();
    void updateRotation();
    void increasePower();
    void hit();
    void resetCue();
    void followBall();
    Tapioca::Vector3 translateToWorld(const Tapioca::Vector3& direction);

    Tapioca::WindowManager* windowMng;   // Gestor de ventanas
    Tapioca::GameObject* powerBar;       // Barra de fuerza
    Tapioca::ProgressBar* powerBarPB;    // Componente de la barra de progreso de la barra de fuerza
    void updatePowerBar(float power = 0);

public:
    COMPONENT_ID("CueController");

    CueController();
    ~CueController();
    bool initComponent(const CompMap& variables) override;
    void start() override;
    void update(const uint64_t deltaTime) override;
    void handleEvent(std::string const& id, void* info) override;
};
