#pragma once
#include "gameDefs.h"
#include <string>

extern "C" {
/*
* @brief Inicializa las factorias de componentes del juego
*/
JUEGO_API void init();
/*
* @brief Anade las factorias de componentes del juego
*/
JUEGO_API void addComponentFactories();
/*
* @brief Devuelve el nombre de la ventana
*/
JUEGO_API std::string getWindowName();
/*
* @brief Devuelve el nombre de la primera escena del juego
*/
JUEGO_API std::string getInitScene();
}
