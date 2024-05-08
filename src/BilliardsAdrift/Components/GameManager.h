#pragma once
#pragma once
#include "Structure/Component.h"
#include "Utilities/Singleton.h"
#include <string>
#include <unordered_set>
#include "Structure/ComponentBuilder.h"
#include "gameDefs.h"

namespace Tapioca {
class SceneLoader;
class Scene;
class MainLoop;
class LuaManager;
class GameObject;
class Text;
class Image;
class AudioSourceComponent;
class Animator;
}

/**
* @brief Clase que gestiona el juego
*/
class JUEGO_API GameManager : public Tapioca::Component, public Tapioca::Singleton<GameManager> {
private:
    friend Singleton<GameManager>;

    /**
    * @brief Estados del juego
    */
    enum State { MainMenu, InGame, GameOver, Pause, Lose, Win, Rules, Controls };
    enum Sounds { PickSound, ExplosionSound, InGameMusic, MainMenuMusic, Sounds_MAX };

    Tapioca::SceneLoader* sceneLoader;   // Puntero al cargador de escenas
    Tapioca::MainLoop* mainLoop;         // Puntero al bucle principal
    Tapioca::LuaManager* luaManager;     // Puntero al gestor de Lua

    std::string firstStateName;          // Nombre del primer estado del juego al iniciar
    std::string currentStateName;        // Nombre del estado actual
    State currentState;                  // Estado actual
    Tapioca::Scene* currentLevelScene;   // Escena de nivel actual

    int INIT_LIFE;       // Vida inicial
    int64_t INIT_TIME;   // Tiempo inicial

    int score;         // Puntuacion actual
    int life;          // Vida actual
    int64_t time;      // Tiempo actual
    int actualLevel;   // Nivel actual
    int maxLevels;     // Numero maximo de niveles

    Tapioca::GameObject* livesText;      // Objeto de las vidas
    Tapioca::Text* livesTextComponent;   // Componente de texto de las vidas
    Tapioca::GameObject* timerText;      // Texto del temporizador
    Tapioca::Text* timerTextComponent;   // Componente de texto del temporizador
    Tapioca::Animator* milkAnimator;     // Animador de Milk
    Tapioca::Animator* teaAnimator;      // Animador de Tea

    Tapioca::GameObject* playerBall;
    std::unordered_set<Tapioca::GameObject*> balls;   // Bolas en la escena
    bool processing;                                  // Indica si los objetos se estan procesando/moviendo
    bool sceneLoaded;                                 // Indica si la escena ha sido cargada

    std::vector<Tapioca::AudioSourceComponent*> audios;   // Sonidos del juego

    /**
    * @brief Cambia la escena
    * @param scene nombre de la escena
    */
    void changeScene(std::string const& scene);

    /**
    * @brief Avanza al siguiente nivel
    */
    void goToNextLevel();

    /**
    * @brief Cambia el estado del juego a InGame inicializando los valores
    */
    void onPlay();

    /**
    * @brief Cambia el estado del juego a Pause
    */
    void onPause();

    /**
    * @brief Cambia el estado del juego a InGame
    */
    void onResume();

    /**
    * @brief Inicializa los valores como la vida, tiempo, puntuacion,
    * coge la referencia a las bolas en balls e inicializa su velocidad a 0
    */
    void startGame();

    /**
    * @brief Cambia de escena dependiendo de si se ha ganado o perdido
    */
    void gameOver();

    /**
    * @brief Cambia de escena dependiendo de si estaba en pausa o no
    */
    void pause();

    /**
    * @brief Actualiza el texto del temporizador
    */
    void updateTimerText(int precision = 0);

    /**
    * @brief Actualiza el numero de vidas
    */
    void updateLives();

    /**
    * @brief Cuando se ha pulsado el boton de jugar desde MainMenu
    */
    void onPlayConfirmed();
    /**
    * @brief Cuando se ha pulsado el boton de resume desde PauseMenu
    */
    void onResumeConfirmed();
    /**
    * @brief Cuando se ha pulsado el boton de continuar desde EndScreen
    */
    void onContinueConfirmed();
    /**
    * @brief Cuando se ha pulsado el boton de reiniciar desde EndScreen
    */
    void onRestartConfirmed();
    /**
    * @brief Cuando se ha pulsado el boton de back desde Rules o Controls
    */
    void onBackConfirmed();
    /**
    * @brief Cuando se ha pulsado el boton de rules desde MainMenu
    */
    void onRulesConfirmed();
    /**
    * @brief Cuando se ha pulsado el boton de controls desde MainMenu
    */
    void onControlsConfirmed();
    /*
    * @brief Cuando se ha pulsado el boton de ir al MainMenu desde EndScreen
    */
    void onMainMenuConfirmed();

    /**
    * @brief Registra funciones
    */
    void registerLuaFunctions();

    /**
    * @brief Actualiza el estado actual del juego
    */
    void updateCurrentState(const std::string name);

    /**
    * @brief Limpia y elimina el nivel actual
    */
    void clearLevel();

    /**
    * @brief Constructor por defecto
    */
    GameManager();

public:
    COMPONENT_ID("GameManager");

    GameManager(GameManager&) = delete;
    GameManager(GameManager&&) = delete;
    GameManager& operator=(GameManager&) = delete;
    GameManager& operator=(GameManager&&) = delete;

    /**
    * @brief Destructor por defecto
    */
    ~GameManager();

    /**
    * @brief Inicializa los valores del juego como la vida inicial, tiempo inicial y el estado inicial
    */
    bool initComponent(const CompMap& variables) override;
    /**
    * @brief Inicializa los punteros a las instancias de SceneLoader y MainLoop e inicializa los valores del juego
    */
    void start() override;
    /**
    * @brief A partir del estado actual, comprueba las condiciones para cambiar de estado o para mandar eventos
    */
    void update(const uint64_t deltaTime) override;
    /**
    * @brief A partir del estado actual, maneja los eventos asociados al estado
    */
    void handleEvent(std::string const& id, void* info) override;

    /**
    * @brief Devuelve la puntuacion
    * @return Puntuacion
    */
    inline int getScore() const { return score; }
    /**
    * @brief Setea el valor absoluto de puntuacion
    * @param s puntuacion
    */
    inline void setScore(const int s) { score = s; }
    /**
    * @brief Incrementa/decrementa s cantidad de puntuaci�n
    * @param s cantidad de puntuaci�n a incrementar/decrementar
    */
    void changeScore(const int s);

    /**
    * @brief Devuelve la vida
    * @return Vida
    */
    inline int getLife() const { return life; }
    /**
    * @brief Setea el valor absoluto de vida
    * @param l vida
    */
    inline void setLife(const int l) { life = l; }
    /**
    * @brief Incrementa/decrementa l cantidad de vida
    * @param l cantidad de vida a incrementar/decrementar
    */
    void changeLife(const int l);
    /**
    * @brief Resta una vida a la vida total del jugador
    */
    void loseLife();
    /**
    * @brief Añade una vida a la vida total del jugador
    */
    void addLife();

    /**
    * @brief Devuelve el tiempo, en segundos
    * @return Tiempo en segundos
    */
    inline float getTime() const { return time / 1000.f; }
    /**
    * @brief Setea el valor absoluto de tiempo
    * @param t tiempo
    */
    inline void setTime(const float t) { time = t * 1000; }
    /**
    * @brief Incrementa/decrementa t cantidad de tiempo
    * @param t cantidad de tiempo a incrementar/decrementar
    */
    void changeTime(const int64_t t);

    /**
    * @brief Devuelve el nivel actual
    * @return Nivel actual
    */
    inline int getActualLevel() const { return actualLevel; }
    /**
    * @brief Setea el nivel actual
    * @param l nivel
    */
    inline void setActualLevel(const int l) { actualLevel = l; }
    /**
    * @brief Incrementa/decrementa l cantidad de nivel
    * @param l cantidad de nivel a incrementar/decrementar
    */
    void changeActualLevel(const int l);
    /**
    * @brief Devuelve el nombre del nivel actual
    * @return Nombre del nivel actual
    */
    std::string getActualLevelName() const;

    /**
    * @brief Devuelve el texto de las vidas
    * @return Texto de las vidas
    */
    std::string getActualLife() const;

    /**
    * @brief Devuelve si se estan procesando los objetos
    * @return Si se estan procesando los objetos
    */
    inline bool isProcessing() const { return processing; }
    /**
    * @brief Setea si se estan procesando los objetos
    * @param p si se estan procesando los objetos
    */
    inline void setProcessing(const bool p) { processing = p; }

    /**
    * @brief Reproduce la animacion de abrir la boca de los gatos
    */
    void playMilkTeaAnims();
};

/**
* @brief Builder de GameManager
*/
class JUEGO_API GameManagerBuilder : public Tapioca::ComponentBuilder {
public:
    GameManagerBuilder() : Tapioca::ComponentBuilder(GameManager::id) { }

    inline Tapioca::Component* createComponent() override { return GameManager::create(); }
};
