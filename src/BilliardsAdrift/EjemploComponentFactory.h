#pragma once
#include "Structure/ComponentBuilder.h"
#include "Structure/Component.h"

namespace BilliardsAdrift {
class TAPIOCA_API EjemploComponentFactory : public Tapioca::ComponentBuilder {
public:
    Tapioca::Component* createComponent() override;
};
}