#pragma once
#include "ComponentBuilder.h"
#include "Component.h"

namespace TapiocaGame {
    class ComponentFactory : public Tapioca::ComponentBuilder {
    public:
        Tapioca::Component* createComponent() override;
    };
}