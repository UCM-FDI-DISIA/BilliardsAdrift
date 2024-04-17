#include "BilliardsAdrift.h"

#include "WindowManager.h"
#include "Structure/MainLoop.h"
#include "SceneLoader.h"
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
#include "Components/WhiteBallComponent.h"

void init() { addComponentFactories(); }

void addComponentFactories() {
    Tapioca::logInfo("Anadiendo las factorias del juego");

    Tapioca::FactoryManager* factMngr = Tapioca::FactoryManager::instance();
    factMngr->addBuilder(new BilliardsAdrift::GameManagerBuilder());
    factMngr->addBuilder(new Tapioca::BasicBuilder<BilliardsAdrift::CueController>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<BilliardsAdrift::HeartComponent>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<BilliardsAdrift::MovableWall>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<BilliardsAdrift::Accelerator>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<BilliardsAdrift::ExplosiveComponent>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<ColoredHole>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<ColoredBall>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<WhiteBallComponent>());
}

std::string getWindowName() { return "Billiards Adrift"; }

std::string getInitScene() { return "GameManager.lua"; }
