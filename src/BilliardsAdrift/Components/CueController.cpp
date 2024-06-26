#include "CueController.h"
#include <math.h>
#include <cmath>
#include "InputManager.h"
#include "Components/RigidBody.h"
#include "Components/AudioSourceComponent.h"
#include "Components/Transform.h"
#include "Components/MeshRenderer.h"
#include "Structure/GameObject.h"
#include "Structure/BasicBuilder.h"
#include "Structure/Scene.h"
#include "Utilities/Quaternion.h"
#include "Components/ProgressBar.h"
#include "Components/Line.h"

CueController::CueController()
    : tr(nullptr), ballTr(nullptr), ballRb(nullptr), ball(nullptr), mesh(nullptr), inputMng(nullptr),
      mouseLastPosition(Tapioca::Vector2()), ballDistanceOffset(Tapioca::Vector3()), impulseTime(0), powerFactor(0.0f),
      maxPower(100.0f), moveFactor(0.0f), rotateFactor(0.0f), actualPower(0.0f), moveSpeed(0), hitting(false),
      canMove(true), windowMng(nullptr), powerBar(nullptr), powerBarPB(nullptr), audio(nullptr),
      trayectoryTransform(nullptr), trayectoryMesh(nullptr), trayectoryScale(0.0f) { }


CueController::~CueController() {
    tr = nullptr;
    ballTr = nullptr;
    ballRb = nullptr;
    ball = nullptr;
    mesh = nullptr;
    inputMng = nullptr;
    windowMng = nullptr;
    powerBar = nullptr;
    powerBarPB = nullptr;
    audio = nullptr;
    trayectoryTransform = nullptr;
    trayectoryMesh = nullptr;
}

bool CueController::initComponent(const CompMap& variables) {
    if (!setValueFromMap(powerFactor, "powerFactor", variables)) {
        Tapioca::logError("CueController: no se pudo inicializar powerFactor.");
        return false;
    }

    if (!setValueFromMap(maxPower, "maxPower", variables)) {
        Tapioca::logError("CueController: no se pudo inicializar maxPower.");
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
    if (!setValueFromMap(impulse, "impulseTime", variables) && impulse > 0) {
        Tapioca::logError("CueController: no se pudo inicializar impulseTime.");
        return false;
    }
    impulseTime = impulse * 1000;

    bool trayectoryScaleSet = setValueFromMap(trayectoryScale.x, "trayectoryScaleX", variables) &&
        setValueFromMap(trayectoryScale.y, "trayectoryScaleY", variables) &&
        setValueFromMap(trayectoryScale.z, "trayectoryScaleZ", variables);
    if (!trayectoryScaleSet) {
        Tapioca::logInfo(
            "PlaneComponent: No se ha definido una normal para el plano, se usara el valor por defecto (0, 0, 1).");
    }

    return true;
}

void CueController::start() {
    tr = object->getComponent<Tapioca::Transform>();

    ball = object->getScene()->getHandler("BallPlayer");
    if (ball != nullptr) {
        ballTr = ball->getComponent<Tapioca::Transform>();
        ballRb = ball->getComponent<Tapioca::RigidBody>();
        if (ballRb != nullptr) ballRb->setVelocity(Tapioca::Vector3(0));
    }
    mesh = object->getComponent<Tapioca::MeshRenderer>();
    ballDistanceOffset = tr->getGlobalPositionWithoutRotation();
    inputMng = Tapioca::InputManager::instance();
    windowMng = Tapioca::WindowManager::instance();
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

    audio = object->getComponent<Tapioca::AudioSourceComponent>();

    Tapioca::GameObject* trayectory = object->getScene()->getHandler("Trayectory");
    if (trayectory != nullptr) {
        trayectoryTransform = trayectory->getComponent<Tapioca::Transform>();
        trayectoryMesh = trayectory->getComponent<Tapioca::MeshRenderer>();
    }
}

void CueController::update(const uint64_t deltaTime) {
    if (hitting) {
        tr->translate(translateToWorld(moveSpeed) * (float)deltaTime);
        if (ball != nullptr) {
            Tapioca::Vector3 distance =
                tr->getGlobalPosition() + tr->getParent()->forward() * 6.f - ballTr->getGlobalPositionWithoutRotation();
            distance.y = 0;
            if (distance.magnitude() <= 3.f) hit();
        }
    }
    else {
        updateRotation();
        updatePosition();
    }
}

void CueController::handleEvent(std::string const& id, void* info) {
    if (id == "ev_MouseButtonDownRight" && canMove) increasePower();

    else if (id == "ev_MouseButtonDownLeft" && actualPower != 0) {
        hitting = true;
        if (ballTr != nullptr)
            moveSpeed = (ballTr->getGlobalPositionWithoutRotation() -
                         (tr->getGlobalPosition() + tr->getParent()->forward() * 6.f)) /
                (float)impulseTime;
        updatePowerBar();
    }
    else if (id == "ev_endProcessing") {
        if (mesh != nullptr) mesh->setVisible(active = true);
        if (trayectoryMesh != nullptr) trayectoryMesh->setVisible(active);
        if (!canMove) {
            canMove = true;
            resetCue();
        }
    }
    else if (id == "ev_ballMoved") {
        if (mesh != nullptr) mesh->setVisible(active = false);
        if (trayectoryMesh != nullptr) trayectoryMesh->setVisible(active);
        if (canMove) {
            canMove = false;
            resetCue();
        }
    }
}

void CueController::updatePosition() {
    mouseLastPosition.x = (float)inputMng->getMousePos().first;
    mouseLastPosition.y = (float)inputMng->getMousePos().second;
    if (!canMove) followBall();
}

void CueController::updateRotation() {
    Tapioca::Vector3 v =
        Tapioca::Vector3(0, 1, 0) * (inputMng->getMousePos().first - mouseLastPosition.x) * rotateFactor;

    tr->getParent()->rotate(v);
    Tapioca::Vector3 u = tr->getGlobalPosition();
}

void CueController::increasePower() {
    if (actualPower < maxPower) {
        tr->translate(translateToWorld(tr->forward()) * (-moveFactor));
        actualPower += powerFactor;
        updatePowerBar(actualPower);
        if (trayectoryTransform != nullptr) {
            trayectoryTransform->setScale(
                Tapioca::Vector3(trayectoryScale.x, trayectoryScale.y, trayectoryScale.z * actualPower));
            trayectoryTransform->translate(translateToWorld(tr->forward()) * (moveFactor));
        }
    }
}

void CueController::hit() {
    if (mesh != nullptr) mesh->setVisible(active = false);
    if (trayectoryMesh != nullptr) trayectoryMesh->setVisible(active);
    hitting = false;
    Tapioca::Vector3 aux = tr->getParent()->forward();
    Tapioca::Vector3 force = aux * (actualPower);
    if (ballRb != nullptr) ballRb->addImpulse(force);
    pushEvent("cueShot", nullptr, true);
    if (audio != nullptr) audio->playOnce();
}

void CueController::resetCue() {
    actualPower = 0;
    followBall();
    resetTrayectory();
    updatePowerBar();
}

void CueController::resetTrayectory() {
    if (trayectoryTransform != nullptr) {
        trayectoryTransform->setScale(Tapioca::Vector3(0.0f, 0.0f, 0.0f));
        trayectoryTransform->setPosition(Tapioca::Vector3(0.0f, 0.0f, 1.0f));
    }
}

void CueController::followBall() {
    if (ball != nullptr) {
        tr->getParent()->setPosition(ballTr->getGlobalPositionWithoutRotation() + Tapioca::Vector3(0, 2, 0));
        tr->setPosition(ballDistanceOffset);
    }
}

Tapioca::Vector3 CueController::translateToWorld(const Tapioca::Vector3& direction) {
    // Obtener la rotacion global inversa del objeto hijo
    Tapioca::Quaternion childGlobalRotationInverse = tr->getGlobalRotation().inverse();
    //Aplicar la rotacion global inversa al vector direccional respecto al mundo
    Tapioca::Vector3 directionalVectorLocal = childGlobalRotationInverse.rotatePoint(direction);
    // Devolver el vector direccional en el sistema de coordenadas local del objeto hijo
    return directionalVectorLocal;
}

void CueController::updatePowerBar(float power) {
    if (powerBarPB != nullptr) {
        powerBarPB->setProgress(power / maxPower);
        if (power < maxPower / 2) powerBarPB->setBarColor(Tapioca::Vector4(0.0f, 1.0f, 0.0f, 1.0f));   // Verde
        else if (power < maxPower / 1.2f)
            powerBarPB->setBarColor(Tapioca::Vector4(1.0f, 1.0f, 0.0f, 1.0f));   // Amarillo
        else
            powerBarPB->setBarColor(Tapioca::Vector4(1.0f, 0.0f, 0.0f, 1.0f));   // Rojo
    }
}
