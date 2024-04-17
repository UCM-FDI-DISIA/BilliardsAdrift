#include "ExplosiveComponent.h"
#include "Structure/BasicBuilder.h"
#include "Components/RigidBody.h"
#include "Structure/GameObject.h"
#include "Components/Transform.h"
#include "Components/MeshRenderer.h"
#include "Utilities/Vector3.h"

namespace BilliardsAdrift {
void ExplosiveComponent::explode(const uint64_t deltaTime) {
    Tapioca::RigidBody* rb = gO->getComponent<Tapioca::RigidBody>();
    Tapioca::Transform* tr = gO->getComponent<Tapioca::Transform>();
    if (fabs(1 / rb->getMass()) < 1e-10 || !active) return;

    Tapioca::Vector3 pos = tr->getPosition();
    Tapioca::Vector3 origin = object->getComponent<Tapioca::Transform>()->getPosition();

#ifdef _DEBUG
    std::cout << "pos: " << pos.x << " " << pos.y << " " << pos.z << '\n';
    std::cout << "origin: " << origin.x << " " << origin.y << " " << origin.z << '\n';
    std::cout << -(deltaTime / duration) << '\n';

#endif   // _DEBUG

    float r = (pos - origin).magnitude();
    if (r < 1e-10) r = 0.1;

    Tapioca::Vector3 expF = (pos - origin) * force / (r * r) * exp(-(deltaTime * 0.001 / duration));
    rb->addImpulse(expF);

#ifdef _DEBUG
    std::cout << expF.x << " " << expF.y << " " << expF.z << '\n';

#endif   // _DEBUG
    if ((lifeTime -= deltaTime * 0.001) < 0) object->die();
}

ExplosiveComponent::ExplosiveComponent() : force(1.f), duration(.1f), lifeTime(duration), gO(nullptr) { }

ExplosiveComponent::~ExplosiveComponent() { }

bool ExplosiveComponent::initComponent(const CompMap& variables) {
    if (!setValueFromMap(force, "force", variables)) {
        Tapioca::logWarn("ExplosiveComponent: No se ha dado valor a force. Se inicializa con valor por defecto 1.");
    }
    return true;
}

void ExplosiveComponent::update(const uint64_t deltaTime) {
    if (gO == nullptr) return;
    
    explode(deltaTime);
}

void ExplosiveComponent::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {
        Tapioca::GameObject* ball = (Tapioca::GameObject*)info;
        if (ball->getHandler() == "BallPlayer") {
            gO = ball;
            object->getComponent<Tapioca::MeshRenderer>()->setVisible(false);
        }
    }
}


}