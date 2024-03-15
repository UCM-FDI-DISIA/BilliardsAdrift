#pragma once
#include "Structure/Component.h"
#include "Utilities/Singleton.h"
#include "Structure/BasicBuilder.h"
#include "../gameDefs.h"

namespace BilliardsAdrift {
class JUEGO_API GameManager : public Tapioca::Component {

private:
    //al inicializarse
    int INIT_LIFE;
    uint64_t INIT_TIME;
    static GameManager* instance;

    //actuales
    int score;
    int life;
    uint64_t time;

    void onStart();
    void onGameOver();
    void onWin();

public:
    COMPONENT_ID("GameManager");

    GameManager();
    ~GameManager() { }

    GameManager* getInstance() { return instance; }
    bool initComponent(const CompMap& variables) override;
    void start() override;
    void update(const uint64_t deltaTime) override;
    void handleEvent(std::string const& id, void* info) override;

    int getScore();
    int getLife();
    uint64_t getTime();

    //setear valor absoluto de puntuación
    void setScore(int s);
    //setear valor absoluto de vida
    void setLife(int l);
    //setear valor absoluto de tiempo
    void setTime(uint64_t t);

    //incrementar/decrementar x cantidad de puntuación
    void changeScore(int s);
    //incrementar/decrementar x cantidad de vida
    void changeLife(int l);
    //incrementar/decrementar x cantidad de tiempo
    void changeTime(uint64_t t);
};
}