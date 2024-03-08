#include "EjemploComponent.h"

namespace BilliardsAdrift {

EjemploComponent::EjemploComponent() : a(0), b(0), c(0), d("") { }

bool EjemploComponent::initComponent(const CompMap& variables) {
    return setValueFromMap(a, "a", variables) && 
           setValueFromMap(b, "b", variables) && 
           setValueFromMap(c, "c", variables) &&
           setValueFromMap(d, "d", variables);
}
}
