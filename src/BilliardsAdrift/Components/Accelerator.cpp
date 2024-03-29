#include "Accelerator.h"
#include <math.h>
#include "Components/RigidBody.h"
#include "Structure/GameObject.h"
#include "Structure/BasicBuilder.h"
#include "Structure/Game.h"

#include <string>

namespace BilliardsAdrift {
template class JUEGO_API Tapioca::BasicBuilder<BilliardsAdrift::Accelerator>;

Accelerator::Accelerator() : rb(nullptr), speedFactor(0) { }

bool Accelerator::initComponent(const CompMap& variables) {

    bool speedSet = setValueFromMap(speedFactor, "speedFactor", variables);
    if (!speedSet) {
#ifdef _DEBUG
        std::cerr << "Error: Accelerator: no se pudo inicializar speedFactor.\n";
#endif
        return false;
    }

    return true;
}

void Accelerator::start() { rb = object->getComponent<Tapioca::RigidBody>(); }

void Accelerator::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* ball = (Tapioca::GameObject*)info;
        std::string s = "Ball";
        if (strstr(ball->getHandler().c_str(), s.c_str())) {
            Tapioca::RigidBody* rb = ball->getComponent<Tapioca::RigidBody>();
            Tapioca::Vector3 v = rb->getVelocity();
            rb->setVelocity(Tapioca::Vector3(v.x * speedFactor, v.y, v.z * speedFactor));
        }
    }
}
}