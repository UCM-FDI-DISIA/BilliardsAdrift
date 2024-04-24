#include "CueController.h"
#include <math.h>
#include <cmath>
#include "InputManager.h"
#include "Components/RigidBody.h"
#include "Components/Transform.h"
#include "Components/MeshRenderer.h"
#include "Structure/GameObject.h"
#include "Structure/BasicBuilder.h"
#include "Structure/Scene.h"
#include "Utilities/Quaternion.h"
#include "Components/ProgressBar.h"

CueController::CueController()
    : tr(nullptr), ballTr(nullptr), ballRb(nullptr), ball(nullptr), mesh(nullptr), inputMng(nullptr),
      mouseLastPosition(Tapioca::Vector2()), ballDistanceOffset(Tapioca::Vector3()), impulseTime(0), powerFactor(0.0f),
      moveFactor(0.0f), rotateFactor(0.0f), impulseFactor(0.0f), actualPower(0.0f), moveSpeed(0), hitting(false),
      canMove(true), powerBar(nullptr) { }

CueController::~CueController() {
    tr = nullptr;
    ballTr = nullptr;
    ballRb = nullptr;
    ball = nullptr;
    mesh = nullptr;
    inputMng = nullptr;
    powerBar = nullptr;
}

bool CueController::initComponent(const CompMap& variables) {
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
    tr = object->getComponent<Tapioca::Transform>();

    ball = object->getScene()->getHandler("BallPlayer");
    ballTr = ball->getComponent<Tapioca::Transform>();
    ballRb = ball->getComponent<Tapioca::RigidBody>();
    ballRb->setVelocity(Tapioca::Vector3(0));
    mesh = object->getComponent<Tapioca::MeshRenderer>();
    ballDistanceOffset = tr->getGlobalPositionWithoutRotation();
    inputMng = Tapioca::InputManager::instance();
    powerBar = object->getScene()->getHandler("PowerBar");
    if (powerBar != nullptr) {
        powerBarPB = powerBar->getComponent<Tapioca::ProgressBar>();
        if (powerBarPB != nullptr) {
            powerBarPB->setProgress(0);
            powerBarPB->setBarColor(Tapioca::Vector4(0.0f, 1.0f, 0.0f, 1.0f));
        }
        else
            Tapioca::logError("CueController: no se pudo encontrar el componente ProgressBar.");
    }
    else
        Tapioca::logError("CueController: no se pudo encontrar el powerBar.");

    followBall();
}

void CueController::update(const uint64_t deltaTime) {
    if (hitting) {
        tr->translate(translateToWorld(moveSpeed) * deltaTime);
        Tapioca::Vector3 distance =
            tr->getGlobalPosition() + tr->getParent()->forward() * 6.f - ballTr->getGlobalPositionWithoutRotation();
        distance.y = 0;
        if (distance.magnitude() <= 3.f) hit();
    }
    else {
        updateRotation();
        updatePosition();
    }
}

void CueController::handleEvent(std::string const& id, void* info) {
    if (id == "ev_MouseButtonDownRight") increasePower();

    else if (id == "ev_MouseButtonDownLeft" && actualPower != 0) {
        hitting = true;
        moveSpeed = (ballTr->getGlobalPositionWithoutRotation() -
                     (tr->getGlobalPosition() + tr->getParent()->forward() * 6.f)) /
            impulseTime;
        moveSpeed.y = 0;
    }
    else if (id == "ev_endProcessing") {
        mesh->setVisible(active = true);
        if (!canMove) {
            canMove = true;
            resetCue();
        }
    }
    else if (id == "ev_ballMoved") {
        mesh->setVisible(active = false);
        if (canMove) {
            canMove = false;
            resetCue();
        }
    }
}

void CueController::updatePosition() {
    mouseLastPosition.x = inputMng->getMousePos().first;
    mouseLastPosition.y = inputMng->getMousePos().second;
    if (!canMove) {
        followBall();
    }
}

void CueController::updateRotation() {
    Tapioca::Vector3 v =
        Tapioca::Vector3(0, 1, 0) * (inputMng->getMousePos().first - mouseLastPosition.x) * rotateFactor;

    tr->getParent()->rotate(v);
    Tapioca::Vector3 u = tr->getGlobalPosition();
}

void CueController::increasePower() {
    if (actualPower < 6000) {
        tr->translate(translateToWorld(tr->forward()) * (-moveFactor));
        Tapioca::Vector3 v = tr->getParent()->forward();
        actualPower += powerFactor;
        updatePowerBar();
    }
}

void CueController::hit() {
    mesh->setVisible(active = false);
    hitting = false;
    ballRb->addForce(tr->getParent()->forward() * (actualPower));
    pushEvent("cueShot", nullptr, true);
}

void CueController::resetCue() {
    actualPower = 0;
    followBall();
    updatePowerBar();
}

void CueController::followBall() {
    tr->getParent()->setPosition(ballTr->getGlobalPositionWithoutRotation() + Tapioca::Vector3(0, 2, 0));
    tr->setPosition(ballDistanceOffset);
}

Tapioca::Vector3 CueController::translateToWorld(const Tapioca::Vector3& direction) {
    // Obtener la rotacion global inversa del objeto hijo
    Tapioca::Quaternion childGlobalRotationInverse = tr->getGlobalRotation().inverse();
    //Aplicar la rotacion global inversa al vector direccional respecto al mundo
    Tapioca::Vector3 directionalVectorLocal = childGlobalRotationInverse.rotatePoint(direction);
    // Devolver el vector direccional en el sistema de coordenadas local del objeto hijo
    return directionalVectorLocal;
}

void CueController::updatePowerBar() {
    if (powerBarPB != nullptr) {
        powerBarPB->setProgress(actualPower / 6000);
        if (actualPower < 3000)
			powerBarPB->setBarColor(Tapioca::Vector4(0.0f, 1.0f, 0.0f, 1.0f)); // Verde
		else if (actualPower < 5000)
			powerBarPB->setBarColor(Tapioca::Vector4(1.0f, 1.0f, 0.0f, 1.0f)); // Amarillo
		else
			powerBarPB->setBarColor(Tapioca::Vector4(1.0f, 0.0f, 0.0f, 1.0f)); // Rojo
    }
}