#pragma once
namespace Tapioca {
	class FactoryManager;
}

#define JUEGO_API __declspec(dllexport)

extern "C" {
/*
* @brief Saluda a una persona
* @param nombre Nombre de la persona a saludar
*/
JUEGO_API void init(Tapioca::FactoryManager* manager);
/**
* @brief Anade las factorias de componentes del juego
*/
JUEGO_API void addComponentFactories(Tapioca::FactoryManager* manager);
}
