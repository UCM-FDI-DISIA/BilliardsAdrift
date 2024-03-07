#include "../header/CueControllerComponentFactory.h"
#include "../header/CueController.h"


namespace BilliardsAdrift {

	Tapioca::Component* CueControllerComponentFactory::createComponent() { return new CueController(); }

}
