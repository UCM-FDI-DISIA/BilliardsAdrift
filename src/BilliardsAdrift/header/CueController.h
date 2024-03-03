#pragma once
#include "Component.h"
#include "Utilities/Vector2.h"
#include "Utilities/Vector3.h"

namespace Tapioca {
	class InputManager;
	class RigidBody;
	class Transform;
	/*template<IsComponent TComp> 
	class BasicBuilder;*/
}

namespace TapiocaGame {
	class CueController : public Tapioca::Component {
	private:
		Tapioca::RigidBody* rb;
		Tapioca::Transform* tr;
		// Tapioca::MeshRenderer* meshComp;
		Tapioca::InputManager* inputMng;
		Tapioca::Vector2 mouseLastPosition;
		float powerFactor; //incremento de fuerza para tirar la bola
		float moveFactor; //factor de movimiento del palo
		float actualPower; //fuerza acumulada para tirar la bola

		void updatePosition();
		void updateRotation();
		void increasePower();
		void hit();
	public:
		COMPONENT_ID("CueController");

		CueController() {};
		~CueController() { }
		bool initComponent(const CompMap& variables) override;
		void start() override;
		void update(const uint64_t deltaTime) override;
		//void handleEvents() override;
	};
}