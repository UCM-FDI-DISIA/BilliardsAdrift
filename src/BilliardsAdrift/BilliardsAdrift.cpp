#include "BilliardsAdrift.h"

#include "SceneManager.h"
#include "Structure/FactoryManager.h"
#include "Structure/BasicBuilder.h"

// TODO: PRUEBA
#include "GraphicsManager.h"
#include "LightDirectional.h"

#include "Components/CueController.h"
#include "Components/GameManager.h"
#include "Components/HeartComponent.h"
#include "Components/MovableWall.h"
#include "Components/Accelerator.h"
#include "Components/ExplosiveComponent.h"

bool init() {
    name();
    addComponentFactories();

    // PRUEBA (deja memory leaks)
    auto graphics = Tapioca::GraphicsManager::instance();
    auto node = graphics->createNode();
    auto light = graphics->createLightDirectional(node, Tapioca::Vector3(0.0f, -1.0f, -1.0f));
    light->produceShadows(true);

    return Tapioca::SceneManager::instance()->loadScene("BilliardsAdrift.lua");
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
    //factMngr->addFactory("GameManager", new Tapioca::BasicBuilder<BilliardsAdrift::GameManager>());
    factMngr->addFactory(new BilliardsAdrift::GameManagerBuilder());
    factMngr->addFactory(new Tapioca::BasicBuilder<BilliardsAdrift::CueController>());
    factMngr->addFactory(new Tapioca::BasicBuilder<BilliardsAdrift::HeartComponent>());
    factMngr->addFactory(new Tapioca::BasicBuilder<BilliardsAdrift::MovableWall>());
    factMngr->addFactory(new Tapioca::BasicBuilder<BilliardsAdrift::Accelerator>());
    factMngr->addFactory(new Tapioca::BasicBuilder<BilliardsAdrift::ExplosiveComponent>());
}
