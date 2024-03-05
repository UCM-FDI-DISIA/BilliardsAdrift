#include "../header/CueController.h"
#include "InputManager.h"
#include "Components/RigidBody.h"
#include "Components/Transform.h"
#include "GameObject.h"
#include "BasicBuilder.h"
#include <math.h>

namespace TapiocaGame {

	bool CueController::initComponent(const CompMap& variables)
	{
		rb = nullptr;
		tr = nullptr;
		inputMng = nullptr;
		mouseLastPosition = Tapioca::Vector2(0, 0);
		actualPower = 0;

		bool powerFactorSet = setValueFromMap(powerFactor, "powerFactor", variables);
		if (!powerFactorSet) {
#ifdef _DEBUG
			std::cerr << "Error: CueController: no se pudo inicializar powerFactor.\n";
#endif
			return false;
		}
		bool moveFactorSet = setValueFromMap(moveFactor, "moveFactor", variables);
		if (!moveFactorSet) {
#ifdef _DEBUG
			std::cerr << "Error: CueController: no se pudo inicializar moveFactor.\n";
#endif
			return false;
		}
		return true;
	}

	void CueController::start()
	{
		rb = parent->getComponent<Tapioca::RigidBody>();
		tr = parent->getComponent<Tapioca::Transform>();
		inputMng = Tapioca::InputManager::instance();
	}

	void CueController::update(const uint64_t deltaTime)
	{
		if (inputMng->eventHappened("ie_mouseButtonRight")) {increasePower();
		}
		else if (inputMng->eventHappened("ie_mouseButtonLeft")) { hit(); }
		updatePosition();
		updateRotation();
	}

	void CueController::updatePosition()
	{
		mouseLastPosition.x = inputMng->getMousePos().first;
		mouseLastPosition.y = inputMng->getMousePos().second;
	}
	void CueController::updateRotation()
	{
		float opposite = inputMng->getMousePos().first - mouseLastPosition.x;
		float adjacent = inputMng->getMousePos().second - mouseLastPosition.y;
		tr->setRotation(Tapioca::Vector3(atan2(opposite, adjacent), 0, 0));
	}

	void CueController::increasePower()
	{
		tr->setPosition(tr->forward() - moveFactor);
		actualPower += powerFactor;
	}

	void CueController::hit()
	{
		rb->addForce(tr->forward() * actualPower);
		actualPower = 0;
	}


}