#include "BilliardsAdrift.h"

#include "SceneManager.h"
#include "Structure/FactoryManager.h"
#include "Structure/BasicBuilder.h"

// TODO: PRUEBA
#include "GraphicsManager.h"
#include "Viewport.h"

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
    /*auto nodeCamera = graphics->createNode(Tapioca::Vector3(20.0f, 0.0f, 20.0f));
    auto camera = graphics->createCamera(nodeCamera, "Hola");
    auto viewport = graphics->createViewport(camera, 1);
    viewport->setBackground(Tapioca::Vector3(0.925f, 0.698f, 0.941f));*/
    auto node = graphics->createNode();
    auto light = graphics->createLightDirectional(node, Tapioca::Vector3(0.0f, -1.0f, -1.0f));
    
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
    factMngr->addFactory("GameManager", new BilliardsAdrift::GameManagerBuilder());
    factMngr->addFactory("CueController", new Tapioca::BasicBuilder<BilliardsAdrift::CueController>());
    factMngr->addFactory("HeartComponent", new Tapioca::BasicBuilder<BilliardsAdrift::HeartComponent>());
    factMngr->addFactory("MovableWall", new Tapioca::BasicBuilder<BilliardsAdrift::MovableWall>());
    factMngr->addFactory("Accelerator", new Tapioca::BasicBuilder<BilliardsAdrift::Accelerator>());
    factMngr->addFactory("ExplosiveComponent", new Tapioca::BasicBuilder<BilliardsAdrift::ExplosiveComponent>());
}
