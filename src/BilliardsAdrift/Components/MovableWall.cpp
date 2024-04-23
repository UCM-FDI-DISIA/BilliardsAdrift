#include "MovableWall.h"
#include <math.h>
#include "Components/RigidBody.h"
#include "Components/Transform.h"
#include "Structure/GameObject.h"
#include "Structure/MainLoop.h"

MovableWall::MovableWall() : rb(nullptr), tr(nullptr), origin(-1, -1), dest(-1, -1), speed(0) { }

MovableWall::~MovableWall() {
    rb = nullptr;
    tr = nullptr;
}

bool MovableWall::initComponent(const CompMap& variables) {
    if (!setValueFromMap(speed, "speed", variables)) {
        Tapioca::logError("MovableWall: no se pudo inicializar speed.");
        return false;
    }

    bool destSet = setValueFromMap(dest.x, "destX", variables) && setValueFromMap(dest.y, "destZ", variables);
    if (!destSet) {
        Tapioca::logError("MovableWall: no se pudo inicializar dest.");
        return false;
    }
    return true;
}

void MovableWall::start() {
    rb = object->getComponent<Tapioca::RigidBody>();
    tr = object->getComponent<Tapioca::Transform>();
    origin = Tapioca::Vector2(tr->getGlobalPosition().x, tr->getGlobalPosition().z);
    direction = dest - origin;
}

void MovableWall::update(const uint64_t deltaTime) {
    Tapioca::Vector3 v = tr->getGlobalPosition();
    if (v.x < origin.x - 0.5f || v.z < origin.y - 0.5f) direction = dest - origin;
    else if (v.x > dest.x + 0.5f || v.z > dest.y + 0.5f)
        direction = origin - dest;

    Tapioca::Vector2 auxD = direction.getNormalized();
    tr->translate(Tapioca::Vector3(auxD.x, 0, auxD.y) * speed * Tapioca::MainLoop::FIXED_DELTA_TIME);
}
