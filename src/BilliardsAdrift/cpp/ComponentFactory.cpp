#include "../header/ComponentFactory.h"
#include "../header/CueController.h"

namespace TapiocaGame {

	Tapioca::Component* ComponentFactory::createComponent() { return new CueController(); }

}
