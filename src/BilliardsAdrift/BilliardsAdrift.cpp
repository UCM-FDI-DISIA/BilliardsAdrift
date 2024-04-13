#include "BilliardsAdrift.h"

#include "WindowManager.h"
#include "Structure/FactoryManager.h"
#include "Structure/BasicBuilder.h"

#include "Components/CueController.h"
#include "Components/GameManager.h"
#include "Components/HeartComponent.h"
#include "Components/MovableWall.h"
#include "Components/Accelerator.h"
#include "Components/ExplosiveComponent.h"
#include "Components/ColoredHole.h"
#include "Components/ColoredBall.h"

void init() { addComponentFactories(); }

void addComponentFactories() {
#ifdef _DEBUG
    std::cout << "Anadiendo las factorias del juego\n";
#endif
    Tapioca::FactoryManager* factMngr = Tapioca::FactoryManager::instance();
    factMngr->addBuilder(new BilliardsAdrift::GameManagerBuilder());
    factMngr->addBuilder(new Tapioca::BasicBuilder<BilliardsAdrift::CueController>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<BilliardsAdrift::HeartComponent>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<BilliardsAdrift::MovableWall>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<BilliardsAdrift::Accelerator>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<BilliardsAdrift::ExplosiveComponent>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<ColoredHole>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<ColoredBall>());
}

std::string getWindowName() { return "Billiards Adrift"; }

std::string getInitScene() { return "Level1.lua"; }

int getFunctions(Function* gameFunctions, int maxFunctions) {
    if (!gameFunctions) return 0;

    int numFunctions = 0;

    // Comprobar que no supere el numero maximo de funciones
    if ((numFunctions + 1) <= maxFunctions)
        gameFunctions[numFunctions++] = {"Ejemplo1", []() { Tapioca::logInfo("Funcion 1 creada desde el Billiards"); }};
    if ((numFunctions + 1) <= maxFunctions)
        gameFunctions[numFunctions++] = {"Ejemplo2", []() { Tapioca::logInfo("Funcion 2 creada desde el Billiards"); }};
    // ...

    return numFunctions;
}