#include "HeartComponent.h"

#include "Structure/BasicBuilder.h"
#include "Components/RigidBody.h"
#include "Components/Transform.h"

namespace BilliardsAdrift {
template class JUEGO_API Tapioca::BasicBuilder<BilliardsAdrift::HeartComponent>;

HeartComponent::HeartComponent() : rb(nullptr), tr(nullptr) { }

HeartComponent ::~HeartComponent() { }

bool HeartComponent::initComponent(const CompMap& variables) {
    rb = nullptr;
    tr = nullptr;

    /*bool activeSet = setValueFromMap(active, "active", variables);
    if (!activeSet) {
#ifdef _DEBUG
        std::cerr << "Error: CueController: no se pudo inicializar active.\n";
#endif
        return false;
    }*/
    return true;
}

void HeartComponent::start() { }

void HeartComponent::update(const uint64_t deltaTime) { }

void HeartComponent::handleEvent(std::string const& id, void* info) {
    if (id == "onCollisionEnter") {

    }
}
}