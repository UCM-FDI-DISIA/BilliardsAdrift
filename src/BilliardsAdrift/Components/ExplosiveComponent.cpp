#include "ExplosiveComponent.h"
#include "Structure/GameObject.h"
#include "Components/RigidBody.h"
#include "Components/MeshRenderer.h"
#include "Components/Transform.h"
#include "Utilities/Vector3.h"
#include "Components/AudioSourceComponent.h"
ExplosiveComponent::ExplosiveComponent() : force(1.0f), duration(0.1f), lifeTime(duration), gO(nullptr) { }

ExplosiveComponent::~ExplosiveComponent() { gO = nullptr; }

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
            pushEvent("ev_explosion", nullptr);
            object->getComponent<Tapioca::MeshRenderer>()->setVisible(false);
        }
    }
}

void ExplosiveComponent::explode(const uint64_t deltaTime) {
    Tapioca::RigidBody* rb = gO->getComponent<Tapioca::RigidBody>();
    Tapioca::Transform* tr = gO->getComponent<Tapioca::Transform>();
    if (fabs(1 / rb->getMass()) < 1e-10 || !active) return;

    Tapioca::Vector3 pos = tr->getPosition();
    Tapioca::Vector3 origin = object->getComponent<Tapioca::Transform>()->getPosition();

    float r = (pos - origin).magnitude();
    if (r < 1e-10) r = 0.1;

    Tapioca::Vector3 expF = (pos - origin) * force / (r * r) * exp(-(deltaTime * 0.001 / duration));
    expF.y = 0.f;

    rb->addImpulse(expF);

    if ((lifeTime -= deltaTime * 0.001) < 0) object->die();
}
