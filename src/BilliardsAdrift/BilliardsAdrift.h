#pragma once
#include "gameDefs.h"
#include "componentDefs.h"
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
/*
* @brief Devuelve las funciones del juego
* @param gameFunctions Array de funciones
* @param maxFunctions Tamanio del array
* @return Numero de funciones
*/
JUEGO_API int getFunctions(Function* gameFunctions, int maxFunctions);
}
