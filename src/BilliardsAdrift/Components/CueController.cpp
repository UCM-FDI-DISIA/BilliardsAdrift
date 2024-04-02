#include "CueController.h"
#include <math.h>

#include "InputManager.h"
#include "Components/RigidBody.h"
#include "Components/Transform.h"
#include "Structure/GameObject.h"
#include "Structure/BasicBuilder.h"
#include "Structure/Scene.h"
#include <cmath>

namespace BilliardsAdrift {
CueController::CueController()
    : inputMng(nullptr), ballRb(nullptr), ballTr(nullptr), ball(nullptr), tr(nullptr), actualPower(0), moveFactor(0),
      powerFactor(0) { }

bool CueController::initComponent(const CompMap& variables) {

    mouseLastPosition = Tapioca::Vector2(0, 0);
    actualPower = 0;

    bool powerFactorSet = setValueFromMap(powerFactor, "powerFactor", variables);
    if (!powerFactorSet) {
#ifdef _DEBUG
        std::cerr << "Error: CueController: no se pudo inicializar powerFactor.\n";
#endif
        return false;
    }

    bool moveFactorSet = setValueFromMap(moveFactor, "moveBackwardFactor", variables);
    if (!moveFactorSet) {
#ifdef _DEBUG
        std::cerr << "Error: CueController: no se pudo inicializar moveFactor.\n";
#endif
        return false;
    }

    bool impulseFactorSet = setValueFromMap(impulseFactor, "impulseFactor", variables);
    if (!impulseFactorSet) {
#ifdef _DEBUG
        std::cerr << "Error: CueController: no se pudo inicializar impulseFactor.\n";
#endif
        return false;
    }

    bool rotateFactorSet = setValueFromMap(rotateFactor, "rotateFactor", variables);
    if (!rotateFactorSet) {
#ifdef _DEBUG
        std::cerr << "Error: CueController: no se pudo inicializar rotateFactor.\n";
#endif
        return false;
    }

    bool ballDistanceOffsetSet = setValueFromMap(ballDistanceOffset.x, "ballDistanceOffsetX", variables) &&
        setValueFromMap(ballDistanceOffset.y, "ballDistanceOffsetY", variables) &&
        setValueFromMap(ballDistanceOffset.z, "ballDistanceOffsetZ", variables);
    if (!ballDistanceOffsetSet) {
#ifdef _DEBUG
        std::cerr << "Error: CueController: no se pudo inicializar ballDistanceOffset.\n";
#endif
        return false;
    }

    return true;
}

void CueController::start() {
    //  rb = object->getComponent<Tapioca::RigidBody>();
    tr = object->getComponent<Tapioca::Transform>();
    inputMng = Tapioca::InputManager::instance();
    ball = object->getScene()->getHandler("BallPlayer");
    ballTr = ball->getComponent<Tapioca::Transform>();
    ballRb = ball->getComponent<Tapioca::RigidBody>();
    tr->setPosition(ballTr->getGlobalPosition() + Tapioca::Vector3(0, 0, 2));
    /*  rb->setTensor(Tapioca::Vector3(0, 1, 0));
    rb->setGravity(0);*/
}

void CueController::update(const uint64_t deltaTime) {
    updateRotation();
    updatePosition();
}

void CueController::handleEvent(std::string const& id, void* info) {
    if (id == "ev_MouseButtonDownRight") {
        increasePower();
    }
    else if (id == "ev_MouseButtonDownLeft") {
        hit();
    }
}

void CueController::updatePosition() {
    mouseLastPosition.x = inputMng->getMousePos().first;
    mouseLastPosition.y = inputMng->getMousePos().second;
}
void CueController::updateRotation() {
    tr->getRotation();
    Tapioca::Vector3 v =
        Tapioca::Vector3(0, 1, 0) * (inputMng->getMousePos().first - mouseLastPosition.x) * rotateFactor;
    tr->rotate(v);
    std::cout << v.x << " " << v.y << " " << v.z << "\n";
    // tr->getParent()->rotate(Tapioca::Vector3(0, 1, 0) * (inputMng->getMousePos().first - mouseLastPosition.x) * 0.1f);
    //  std::cout <<rb->getMovementType() << "\n";
}

void CueController::increasePower() {
    tr->translate(tr->forward() * (-moveFactor));
    actualPower += powerFactor;
#ifdef _DEBUG
    // std::cout << "IncreasePower: " << actualPower << "\n";
#endif
}

void CueController::hit() {
    // // std::cout << "AAAAAAAAAA "<< tr->forward().x << " " << tr->forward().y << " " << tr->forward().z << "\n";
    // rb->setVelocity(tr->forward() * 100000);
    tr->translate(tr->forward() * (actualPower)*impulseFactor);
    ballRb->addImpulse(tr->forward() * (actualPower));
    //  rb->addForce(tr->forward() * (actualPower));
    actualPower = 0;
}
}