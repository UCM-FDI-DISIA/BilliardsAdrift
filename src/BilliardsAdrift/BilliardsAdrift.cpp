#include "BilliardsAdrift.h"

#include "Structure/FactoryManager.h"
#include "SceneManager.h"
#include "Structure/ComponentBuilder.h"
#include "EjemploComponentFactory.h"
#include "header/CueControllerComponentFactory.h"

void init(Tapioca::FactoryManager* factMngr, Tapioca::SceneManager* sceneMngr) {
    name();
    addComponentFactories(factMngr);
    sceneMngr->loadScene("BilliardsAdrift.lua");
}

void name() {
#ifdef _DEBUG
    std::cout << "Billiards Adrift\n";
#endif
}

void addComponentFactories(Tapioca::FactoryManager* factMngr) {
#ifdef _DEBUG
    std::cout << "Anadiendo las factorias del juego\n";
#endif
    //factMngr->addFactory("EjemploComponent", new BilliardsAdrift::EjemploComponentFactory());
    factMngr->addFactory("CueController", new BilliardsAdrift::CueControllerComponentFactory());
}
