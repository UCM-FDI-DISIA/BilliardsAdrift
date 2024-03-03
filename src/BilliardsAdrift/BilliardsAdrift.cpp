#include "BilliardsAdrift.h"
#include "Structure/ComponentBuilder.h"
#include "header/ComponentFactory.h"
#include "defs.h"

JUEGO_API void function(const char* var)
{
    std::cout << "I love BilliardsAdrift" << var << "<3\n";
}

JUEGO_API FactoryInfo** getComponentFactories(int& count) {
    count = NUM_FACTORIES;
    FactoryInfo** factories = new FactoryInfo * [NUM_FACTORIES];
    factories[0] = new FactoryInfo();
    factories[0]->name = "CueController";
    factories[0]->builder = new TapiocaGame::ComponentFactory();

    return factories;
}
