#include "CueController.h"
#include <math.h>

#include "InputManager.h"
#include "Components/RigidBody.h"
#include "Components/Transform.h"
#include "Structure/GameObject.h"
#include "Structure/BasicBuilder.h"
#include <cmath>

namespace BilliardsAdrift {
template class JUEGO_API Tapioca::BasicBuilder<BilliardsAdrift::CueController>;

CueController::CueController()
    : inputMng(nullptr), rb(nullptr), tr(nullptr), actualPower(0), moveFactor(0), powerFactor(0) { }

bool CueController::initComponent(const CompMap& variables) {
    rb = nullptr;
    tr = nullptr;
    inputMng = nullptr;
    mouseLastPosition = Tapioca::Vector2(0, 0);
    actualPower = 0;

    bool powerFactorSet = setValueFromMap(powerFactor, "powerFactor", variables);
    if (!powerFactorSet) {
#ifdef _DEBUG
        std::cerr << "Error: CueController: no se pudo inicializar powerFactor.\n";
#endif
        return false;
    }
    bool moveFactorSet = setValueFromMap(moveFactor, "moveFactor", variables);
    if (!moveFactorSet) {
#ifdef _DEBUG
        std::cerr << "Error: CueController: no se pudo inicializar moveFactor.\n";
#endif
        return false;
    }

    return true;
}

void CueController::start() {
  //  rb = object->getComponent<Tapioca::RigidBody>();
    tr = object->getComponent<Tapioca::Transform>();
    inputMng = Tapioca::InputManager::instance();

  /*  rb->setGravity(0);
    rb->setTensor(Tapioca::Vector3(0, 10000, 0));*/
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
    tr->rotate(Tapioca::Vector3(0, 1, 0) * (inputMng->getMousePos().first - mouseLastPosition.x) * 0.2f);
   // tr->getParent()->rotate(Tapioca::Vector3(0, 1, 0) * (inputMng->getMousePos().first - mouseLastPosition.x) * 0.1f);
  //  std::cout <<rb->getMovementType() << "\n";
}

void CueController::increasePower() {
    tr->translate(tr->forward() * (- moveFactor));
    actualPower += powerFactor;
#ifdef _DEBUG
   // std::cout << "IncreasePower: " << actualPower << "\n";
#endif
}

void CueController::hit() {
   // // std::cout << "AAAAAAAAAA "<< tr->forward().x << " " << tr->forward().y << " " << tr->forward().z << "\n";
  // rb->setVelocity(tr->forward() * 100000);
    tr->translate(tr->forward() * (actualPower));
    actualPower = 0;
}
}