#include "Accelerator.h"
#include <math.h>
#include "Components/RigidBody.h"
#include "Structure/GameObject.h"
#include "Structure/BasicBuilder.h"
#include "Structure/MainLoop.h"

#include <string>

namespace BilliardsAdrift {
Accelerator::Accelerator() : rb(nullptr), speedFactor(0) { }

bool Accelerator::initComponent(const CompMap& variables) {

    if (!setValueFromMap(speedFactor, "speedFactor", variables)) {
        Tapioca::logError("Accelerator: no se pudo inicializar speedFactor.");
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