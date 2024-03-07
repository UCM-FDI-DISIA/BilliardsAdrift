#pragma once
#include "defs.h"
namespace Tapioca {
class FactoryManager;
class SceneManager;
}

extern "C" {
/**
* @brief Punto de entrada del juego
*/
JUEGO_API void init(Tapioca::FactoryManager* factMngr, Tapioca::SceneManager* sceneMngr);
/**
* @brief Nombre del juego
*/
JUEGO_API void name();
/**
* @brief Anade las factorias de componentes del juego
*/
JUEGO_API void addComponentFactories(Tapioca::FactoryManager* factMngr);
}
