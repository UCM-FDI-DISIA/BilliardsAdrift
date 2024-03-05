#include "EjemploComponentFactory.h"
#include "EjemploComponent.h"

namespace BilliardsAdrift {
Tapioca::Component* EjemploComponentFactory::createComponent() { return new EjemploComponent(); }
}
