#pragma once
#include "Structure/Component.h"
#include "Utilities/Singleton.h"
#include "Structure/ComponentBuilder.h"
#include "gameDefs.h"
#include <string>
#include <unordered_set>
#include "Structure/BasicBuilder.h"

namespace Tapioca {
class GameObject;
class MainLoop;
class SceneLoader;
}

namespace BilliardsAdrift {
class JUEGO_API GameManager : public Tapioca::Component, public Tapioca::Singleton<GameManager> {
private:
    friend Singleton<GameManager>;

    Tapioca::SceneLoader* sceneLoader;
    Tapioca::MainLoop* mainLoop;

    enum State { MainMenu, InGame, GameOver, Pause };

    std::string firstStateName;
    std::string currentStateName;
    State currentState;

    //al inicializarse
    int INIT_LIFE;
    int64_t INIT_TIME;

    //actuales
    int score;
    int life;
    int64_t time;

    int actualLevel;

    std::unordered_set<Tapioca::GameObject*> balls;

    bool processing;   //tras golpear el palo

    void reset();

    void onStart();
    void onGameOver();
   
    void onWin();

    GameManager();
public:
    COMPONENT_ID("GameManager");

    GameManager(GameManager&) = delete;
    GameManager(GameManager&&) = delete;
    GameManager& operator=(GameManager&) = delete;
    GameManager& operator=(GameManager&&) = delete;
    ~GameManager();

    bool initComponent(const CompMap& variables) override;
    void start() override;
    void update(const uint64_t deltaTime) override;
    void handleEvent(std::string const& id, void* info) override;

    inline int getScore() const { return score; }
    inline int getLife() const {  return life; }
    inline float getTime() const { return time / 1000.f; }

    /*
    * @brief Cambia la escena
    * @param scene nombre de la escena
    */
    void changeScene(std::string const& scene) const;

    /*
    * @brief Setea el valor absoluto de puntuacion
    * @param s puntuacion
    */
    inline void setScore(const int s) { score = s; }
    /*
    * @brief Setea el valor absoluto de vida
    * @param l vida
    */
    inline void setLife(const int l) { life = l; }
    /*
    * @brief Setea el valor absoluto de tiempo
    * @param t tiempo
    */
    inline void setTime(const float t) { time = t * 1000; }

    /*
    * @brief Incrementa/decrementa s cantidad de puntuaci�n
    * @param s cantidad de puntuaci�n a incrementar/decrementar
    */
    void changeScore(const int s);
    /*
    * @brief Incrementa/decrementa l cantidad de vida
    * @param l cantidad de vida a incrementar/decrementar
    */
    void changeLife(const int l);
    /*
    * @brief Incrementa/decrementa t cantidad de tiempo
    * @param t cantidad de tiempo a incrementar/decrementar
    */
    void changeTime(const float t);

    /*
    * @brief Resta una vida a la vida total del jugador
    */
    void loseLife();
    
    /*
    * @brief Cuando se ha pulsado el boton de jugar
    */
    void onPlayConfirmed();

    void pause();
    void onContinueConffirmed();
    void onRestartConffirmed();
    void onMainMenuConffirmed();
};

class JUEGO_API GameManagerBuilder : public Tapioca::ComponentBuilder {
public:
    GameManagerBuilder() : Tapioca::ComponentBuilder(GameManager::id) { }

    inline Tapioca::Component* createComponent() override { return GameManager::create(); }
};
}