#pragma once
#include <iostream>
#include <vector>
#include "Utilities/defs.h"

class ComponentFactory;
class defs;

using namespace Tapioca;
#define JUEGO_API __declspec(dllexport)

extern "C" {
    /*
    * @brief Saluda a una persona
    * @param nombre Nombre de la persona a saludar
    */
    JUEGO_API void function(const char* var);

    //
    JUEGO_API FactoryInfo** getComponentFactories(int& count);
}
