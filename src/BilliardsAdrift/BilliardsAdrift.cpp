#include "BilliardsAdrift.h"

#include "Structure/FactoryManager.h"
#include "SceneManager.h"
#include "Structure/ComponentBuilder.h"
#include "EjemploComponentFactory.h"
#include "header/CueControllerComponentFactory.h"

void init() {
    name();
    addComponentFactories();
    Tapioca::SceneManager::instance()->loadScene("BilliardsAdrift.lua");
}

void name() {
#ifdef _DEBUG
    std::cout << "Billiards Adrift\n";
#endif
}

void addComponentFactories() {
#ifdef _DEBUG
    std::cout << "Anadiendo las factorias del juego\n";
#endif
    Tapioca::FactoryManager* factMngr = Tapioca::FactoryManager::instance();
    factMngr->addFactory("EjemploComponent", new BilliardsAdrift::EjemploComponentFactory());
    factMngr->addFactory("CueController", new BilliardsAdrift::CueControllerComponentFactory());
}
