#include "BilliardsAdrift.h"

#include "Structure/FactoryManager.h"
#include "Structure/BasicBuilder.h"
#include "SceneManager.h"
#include "GraphicsEngine.h"
#include "Viewport.h"
#include "Structure/ComponentBuilder.h"
#include "EjemploComponentFactory.h"
#include "header/CueControllerComponentFactory.h"

void init() {
    name();
    addComponentFactories();
    Tapioca::SceneManager::instance()->loadScene("BilliardsAdrift.lua");

    // PRUEBA (deja memory leaks)
    auto graphics = Tapioca::GraphicsEngine::instance();
    auto nodeCamera = graphics->createNode(Tapioca::Vector3(20.0f, 0.0f, 20.0f));
    auto camera = graphics->createCamera(nodeCamera, "Hola");
    auto viewport = graphics->createViewport(camera, 1);
    viewport->setBackground(Tapioca::Vector3(0.925f, 0.698f, 0.941f));
    auto node = graphics->createNode();
    auto light = graphics->createLightDirectional(node, Tapioca::Vector3(0.0f, -1.0f, -1.0f));
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
    //factMngr->addFactory("GameManager", new Tapioca::BasicBuilder());
}
