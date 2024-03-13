#pragma once
#include "Structure/ComponentBuilder.h"
#include "Structure/Component.h"
#include "../gameDefs.h"

namespace BilliardsAdrift {
class JUEGO_API CueControllerComponentFactory : public Tapioca::ComponentBuilder {
public:
    Tapioca::Component* createComponent() override;
};
}
