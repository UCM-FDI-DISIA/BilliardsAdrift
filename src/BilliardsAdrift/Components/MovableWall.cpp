#include "MovableWall.h"
#include <math.h>
#include "Components/RigidBody.h"
#include "Components/Transform.h"
#include "Structure/GameObject.h"
#include "Structure/BasicBuilder.h"
#include "Structure/Game.h"

namespace BilliardsAdrift {
template class JUEGO_API Tapioca::BasicBuilder<BilliardsAdrift::MovableWall>;

MovableWall::MovableWall() : rb(nullptr), tr(nullptr), actualDest(-1, -1), origin(-1, -1), dest(-1, -1), speed(0) { }

bool MovableWall::initComponent(const CompMap& variables) {

    bool speedSet = setValueFromMap(speed, "speed", variables);
    if (!speedSet) {
#ifdef _DEBUG
        std::cerr << "Error: MovableWall: no se pudo inicializar speed.\n";
#endif
        return false;
    }

    bool destSet = setValueFromMap(dest.x, "destX", variables) && setValueFromMap(dest.y, "destZ", variables);
    if (!destSet) {
#ifdef _DEBUG
        std::cerr << "Error: MovableWall: no se pudo inicializar dest.\n";
#endif
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
    else if (v.x > dest.x + 0.5f || v.z > dest.y + 0.5f) direction = origin - dest;

    Tapioca::Vector2 auxD = direction.getNormalized();
    tr->translate(Tapioca::Vector3(auxD.x, 0, auxD.y) * speed * Tapioca::Game::FIXED_DELTA_TIME);
}
}