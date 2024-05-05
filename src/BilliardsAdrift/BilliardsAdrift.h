#pragma once
#include "gameDefs.h"
#include "componentDefs.h"
#include <string>

extern "C" {
/**
* @brief Inicializa las factorias de componentes del juego
*/
JUEGO_API void init();
/**
* @brief Anade las factorias de componentes del juego
*/
JUEGO_API void addComponentFactories();
/**
* @brief Devuelve el nombre de la ventana
* @return Nombre de la ventana
*/
JUEGO_API const char* getWindowName();
/**
* @brief Devuelve si el juego se ejecuta en pantalla completa
* @return true si se ejecuta en pantalla completa, false en caso contrario
*/
JUEGO_API bool getFullScreen();
/**
* @brief Establece los valores de la ventana
* @param width Ancho de la ventana
* @param height Alto de la ventana
*/
JUEGO_API void getWindowSize(uint32_t& width, uint32_t& height);
/**
* @brief Devuelve el nombre de la primera escena del juego
* @return Nombre de la primera escena del juego
*/
JUEGO_API const char* getInitScene();
}
