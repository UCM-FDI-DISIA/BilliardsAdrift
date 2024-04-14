#pragma once
#include "gameDefs.h"
#include "Structure/Component.h"
#include "Utilities/Vector2.h"
#include "Utilities/Vector3.h"

namespace Tapioca {
class InputManager;

class Transform;
class GameObject;
class RigidBody;
class MeshRenderer;
}

namespace BilliardsAdrift {
class JUEGO_API CueController : public Tapioca::Component {
private:
    Tapioca::Transform* tr;
    Tapioca::Transform* ballTr;
    Tapioca::RigidBody* ballRb;
    Tapioca::GameObject* ball;
    Tapioca::MeshRenderer* mesh;
    // Tapioca::MeshRenderer* meshComp;
    Tapioca::InputManager* inputMng;
    Tapioca::Vector2 mouseLastPosition;
    Tapioca::Vector3 ballDistanceOffset;

    int64_t impulseTime;   //en milisegundos

    float powerFactor;     //incremento de fuerza para tirar la bola
    float moveFactor;      //factor de movimiento del palo
    float rotateFactor;    //factor de movimiento del palo hacia atrás
    float impulseFactor;   //factor de movimiento del palo hacia delante (impulso)

    float actualPower;   //fuerza acumulada para tirar la bola
    Tapioca::Vector3 moveSpeed;
    bool hitting;
    bool canMove;

    void updatePosition();
    void updateRotation();
    void increasePower();
    void hit();
    void resetCue();
    void followBall();
    Tapioca::Vector3 translateToWorld(const Tapioca::Vector3& direction);



public:
    COMPONENT_ID("CueController");

    CueController();
    ~CueController() { }
    bool initComponent(const CompMap& variables) override;
    void start() override;
    void update(const uint64_t deltaTime) override;
    void handleEvent(std::string const& id, void* info) override;
};
}