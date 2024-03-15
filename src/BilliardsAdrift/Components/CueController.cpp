#include "CueController.h"
#include <math.h>

#include "InputManager.h"
#include "Components/RigidBody.h"
#include "Components/Transform.h"
#include "Structure/GameObject.h"
#include "Structure/BasicBuilder.h"

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
    rb = object->getComponent<Tapioca::RigidBody>();
    tr = object->getComponent<Tapioca::Transform>();
    inputMng = Tapioca::InputManager::instance();
}

void CueController::update(const uint64_t deltaTime) {
    updatePosition();
    updateRotation();
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
#ifdef _DEBUG
    //std::cout << "mouse: " << mouseLastPosition.x << "\n";
#endif
}
void CueController::updateRotation() {
    float opposite = inputMng->getMousePos().first - mouseLastPosition.x;
    float adjacent = inputMng->getMousePos().second - mouseLastPosition.y;
    tr->setRotation(Tapioca::Vector3(atan2(opposite, adjacent), 0, 0));
}

void CueController::increasePower() {
    tr->setPosition(tr->forward() - moveFactor);
    actualPower += powerFactor;
#ifdef _DEBUG
    std::cout << "IncreasePower: " << actualPower << "\n";
#endif
}

void CueController::hit() {
    rb->addImpulse(tr->forward() * actualPower);
    actualPower = 0;
}
}