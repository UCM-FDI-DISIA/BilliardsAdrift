#include "BilliardsAdrift.h"
#include "Structure/FactoryManager.h"
#include "Structure/BasicBuilder.h"

#include "Components/CueController.h"
#include "Components/GameManager.h"
#include "Components/HeartComponent.h"
#include "Components/MovableWall.h"
#include "Components/WallComponent.h"
#include "Components/Accelerator.h"
#include "Components/ExplosiveComponent.h"
#include "Components/ColoredHole.h"
#include "Components/ColoredBall.h"
#include "Components/WhiteBallComponent.h"
#include "Components/ClockComponent.h"

void init() { addComponentFactories(); }

void addComponentFactories() {
    Tapioca::logInfo("Anadiendo las factorias del juego");

    Tapioca::FactoryManager* factMngr = Tapioca::FactoryManager::instance();
    factMngr->addBuilder(new GameManagerBuilder());
    factMngr->addBuilder(new Tapioca::BasicBuilder<CueController>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<HeartComponent>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<MovableWall>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<Accelerator>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<ExplosiveComponent>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<ColoredHole>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<ColoredBall>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<WhiteBallComponent>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<WallComponent>());
    factMngr->addBuilder(new Tapioca::BasicBuilder<ClockComponent>());
}

std::string getWindowName() { return "Billiards Adrift"; }

bool getFullScreen() { return true; }

void getWindowSize(uint32_t& width, uint32_t& height) {
    width = 600;
    height = 600;
}

std::string getInitScene() { return "StartScene.lua"; }
