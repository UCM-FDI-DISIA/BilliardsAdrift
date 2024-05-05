#pragma once
#include "gameDefs.h"
#include "WallComponent.h"
#include "Utilities/Vector2.h"
#include "Utilities/Vector3.h"

namespace Tapioca {
class RigidBody;
class Transform;
}

/**
* @brief Componente que controla una pared movil
*/
class JUEGO_API MovableWall : public WallComponent {
private:
    Tapioca::RigidBody* rb;   // RigidBody del objeto
    Tapioca::Transform* tr;   // Transform del objeto

    Tapioca::Vector2 origin;      // Posicion inicial
    Tapioca::Vector2 dest;        // Posicion final
    Tapioca::Vector2 direction;   // Direccion de movimiento

    float speed;   // Velocidad de movimiento

public:
    COMPONENT_ID("MovableWall");
    
    /**
    * @brief Constructor por defecto
    */
    MovableWall();

    /**
    * @brief Destructor por defecto
    */
    ~MovableWall();

    /**
    * @brief Metodo que se usa para recibir los parametros iniciales y guardarlos.
    * No garantiza que todos los componentes iniciales esten creados
    * @param variables unordered_map con los parametros iniciales
    * @return Devuelve true si se ha inicializado correctamente, false en caso contrario
    */
    bool initComponent(const CompMap& variables) override;
    /**
    * @brief Coge referencia al RigidBody, Transform y AudioSourceComponent del objeto
    */
    void start() override;
    /**
    * @brief Mueve la pared
    */
    void update(const uint64_t deltaTime) override;
};
