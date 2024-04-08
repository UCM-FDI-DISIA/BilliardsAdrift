#include "CueController.h"
#include <math.h>

#include "InputManager.h"
#include "Components/RigidBody.h"
#include "Components/Transform.h"
#include "Components/MeshRenderer.h"
#include "Structure/GameObject.h"
#include "Structure/BasicBuilder.h"
#include "Structure/Scene.h"
#include "Utilities/Quaternion.h"
#include <cmath>

namespace BilliardsAdrift {
CueController::CueController()
    : inputMng(nullptr), ballRb(nullptr), ballTr(nullptr), ball(nullptr), tr(nullptr), actualPower(0), moveFactor(0),
      powerFactor(0), hitting(false), moveSpeed(0) { }

bool CueController::initComponent(const CompMap& variables) {

    mouseLastPosition = Tapioca::Vector2(0, 0);
    actualPower = 0;

    if (!setValueFromMap(powerFactor, "powerFactor", variables)) {
        Tapioca::logError("CueController: no se pudo inicializar powerFactor.");
        return false;
    }

    if (!setValueFromMap(moveFactor, "moveBackwardFactor", variables)) {
        Tapioca::logError("CueController: no se pudo inicializar moveFactor.");
        return false;
    }

    if (!setValueFromMap(rotateFactor, "rotateFactor", variables)) {
        Tapioca::logError("CueController: no se pudo inicializar rotateFactor.");
        return false;
    }

    float impulse;
    if (!setValueFromMap(impulse, "impulseTime", variables)) {
        Tapioca::logError("CueController: no se pudo inicializar impulseTime.");
        return false;
    }
    impulseTime = impulse * 1000;

    if (!setValueFromMap(impulseFactor, "impulseFactor", variables)) {
        Tapioca::logError("CueController: no se pudo inicializar impulseFactor.");
        return false;
    }

    return true;
}

void CueController::start() {
    //  rb = object->getComponent<Tapioca::RigidBody>();
    tr = object->getComponent<Tapioca::Transform>();
    ballDistanceOffset = tr->getGlobalPosition();
    inputMng = Tapioca::InputManager::instance();
    ball = object->getScene()->getHandler("BallPlayer");
    ballTr = ball->getComponent<Tapioca::Transform>();
    ballRb = ball->getComponent<Tapioca::RigidBody>();
    mesh = object->getComponent<Tapioca::MeshRenderer>();
    tr->getParent()->setPosition(ballTr->getGlobalPosition());
    tr->setPosition(ballDistanceOffset);
}

void CueController::update(const uint64_t deltaTime) {
    if (hitting) {
        tr->translate(translateToWorld(moveSpeed) * deltaTime);
        Tapioca::Vector3 distance =
            tr->getRotationPosition() + tr->getParent()->forward() * 6.f - ballTr->getGlobalPosition();
        distance.y = 0;
#ifdef _DEBUG
        //   std::cout << distance.magnitude() << "\n";
#endif
        if (distance.magnitude() <= 2.f) {

            hit();
        }
    }
    else {
        updateRotation();
        updatePosition();
    }
}

void CueController::handleEvent(std::string const& id, void* info) {
    if (id == "ev_MouseButtonDownRight") {
        increasePower();
    }
    else if (id == "ev_MouseButtonDownLeft") {
        hitting = true;
        moveSpeed = (ballTr->getGlobalPosition() - (tr->getRotationPosition() + tr->getParent()->forward() * 6.f)) /
            impulseTime;
        moveSpeed.y = 0;
    }
    else if (id == "ev_endProcessing") {
        mesh->setVisible(active = true);
        tr->getParent()->setPosition(ballTr->getGlobalPosition());
        tr->setPosition(ballDistanceOffset);
    }
}

void CueController::updatePosition() {
    mouseLastPosition.x = inputMng->getMousePos().first;
    mouseLastPosition.y = inputMng->getMousePos().second;
}

void CueController::updateRotation() {

    Tapioca::Vector3 v =
        Tapioca::Vector3(0, 1, 0) * (inputMng->getMousePos().first - mouseLastPosition.x) * rotateFactor;
#ifdef _DEBUG
    //  std::cout << (inputMng->getMousePos().first - mouseLastPosition.x) * rotateFactor << "\n";
#endif
    tr->getParent()->rotate(v);
    Tapioca::Vector3 u = tr->getRotationPosition();
    Tapioca::logInfo((std::string(u.x) + ' ' + std::string(u.y) + ' ' + std::string(u.z)).c_str());
    //  std::cout << u.x << " " << u.y << " " << u.z << "\n";
    //tr->rotate(v);
    /*  std::cout << v.x << " " << v.y << " " << v.z << "\n";*/
    // tr->getParent()->rotate(Tapioca::Vector3(0, 1, 0) * (inputMng->getMousePos().first - mouseLastPosition.x) * 0.1f);
    //  std::cout <<rb->getMovementType() << "\n";
}

void CueController::increasePower() {
    tr->translate(translateToWorld(tr->forward()) * (-moveFactor));
    Tapioca::Vector3 v = tr->getParent()->forward();
    // std::cout << v.x << " " << v.y << " " << v.z << "\n";
    actualPower += powerFactor;
#ifdef _DEBUG
    // std::cout << "IncreasePower: " << actualPower << "\n";
#endif
}

void CueController::hit() {

    hitting = false;
    ballRb->addImpulse(tr->getParent()->forward() * (actualPower));

    mesh->setVisible(active = false);
    pushEvent("ev_Processing", nullptr, true);
    //  rb->addForce(tr->forward() * (actualPower));
    actualPower = 0;
}

Tapioca::Vector3 CueController::translateToWorld(const Tapioca::Vector3& direction) {

    // Obtener la rotaci�n global inversa del objeto hijo
    Tapioca::Quaternion childGlobalRotationInverse = tr->getGlobalRotation().inverse();
    //Aplicar la rotaci�n global inversa al vector direccional respecto al mundo
    Tapioca::Vector3 directionalVectorLocal = childGlobalRotationInverse.rotatePoint(direction);

    // Devolver el vector direccional en el sistema de coordenadas local del objeto hijo
    return directionalVectorLocal;
}

}