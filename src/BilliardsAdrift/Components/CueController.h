#pragma once
#include "../gameDefs.h"
#include "Structure/Component.h"
#include "Utilities/Vector2.h"
#include "Utilities/Vector3.h"

namespace Tapioca {
class InputManager;

class Transform;
class GameObject;
class RigidBody;
}

namespace BilliardsAdrift {
class JUEGO_API CueController : public Tapioca::Component {
private:
    Tapioca::Transform* tr;
    Tapioca::Transform* ballTr;
    Tapioca::RigidBody* ballRb;
    Tapioca::GameObject* ball;
    // Tapioca::MeshRenderer* meshComp;
    Tapioca::InputManager* inputMng;
    Tapioca::Vector2 mouseLastPosition;
    Tapioca::Vector3 ballDistanceOffset;
    float powerFactor;   //incremento de fuerza para tirar la bola
    float moveFactor;    //factor de movimiento del palo
    float rotateFactor;   //factor de movimiento del palo hacia atr�s
    float impulseFactor;   //factor de movimiento del palo hacia delante (impulso)
    
    float actualPower;   //fuerza acumulada para tirar la bola

    void updatePosition();
    void updateRotation();
    void increasePower();
    void hit();

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