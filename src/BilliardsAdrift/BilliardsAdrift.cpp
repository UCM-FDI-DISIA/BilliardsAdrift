#include "BilliardsAdrift.h"

#include "WindowManager.h"
#include "SceneManager.h"
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

void init() {
    addComponentFactories();
}

void addComponentFactories() {
#ifdef _DEBUG
    std::cout << "Anadiendo las factorias del juego\n";
#endif
    Tapioca::FactoryManager* factMngr = Tapioca::FactoryManager::instance();
    factMngr->addFactory(new BilliardsAdrift::GameManagerBuilder());
    factMngr->addFactory(new Tapioca::BasicBuilder<BilliardsAdrift::CueController>());
    factMngr->addFactory(new Tapioca::BasicBuilder<BilliardsAdrift::HeartComponent>());
    factMngr->addFactory(new Tapioca::BasicBuilder<BilliardsAdrift::MovableWall>());
    factMngr->addFactory(new Tapioca::BasicBuilder<BilliardsAdrift::Accelerator>());
    factMngr->addFactory(new Tapioca::BasicBuilder<BilliardsAdrift::ExplosiveComponent>());
    factMngr->addFactory(new Tapioca::BasicBuilder<ColoredHole>());
    factMngr->addFactory(new Tapioca::BasicBuilder<ColoredBall>());
}

std::string getWindowName() { return "Billiards Adrift"; }

std::string getInitScene() { return "BilliardsAdrift.lua"; }
