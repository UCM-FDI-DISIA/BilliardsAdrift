#pragma once
#include "Structure/ComponentBuilder.h"
#include "Structure/Component.h"
#include "gameDefs.h"

namespace BilliardsAdrift {
class JUEGO_API EjemploComponentFactory : public Tapioca::ComponentBuilder {
public:
    Tapioca::Component* createComponent() override;
};
}