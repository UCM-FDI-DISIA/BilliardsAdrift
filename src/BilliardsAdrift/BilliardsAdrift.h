#pragma once
#include "gameDefs.h"

extern "C" {
/**
* @brief Punto de entrada del juego
*/
JUEGO_API bool init();
/**
* @brief Nombre del juego
*/
JUEGO_API void name();
/**
* @brief Anade las factorias de componentes del juego
*/
JUEGO_API void addComponentFactories();
}
