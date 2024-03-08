#pragma once
#include <string>
#include "Structure/Component.h"

namespace BilliardsAdrift {
class TAPIOCA_API EjemploComponent : public Tapioca::Component {
private:
    int a;
    float b;
    bool c;
    std::string d;

public:
    COMPONENT_ID("EjemploComponent")

    EjemploComponent();
    ~EjemploComponent() { }
    bool initComponent(const CompMap& variables) override;
};
}
