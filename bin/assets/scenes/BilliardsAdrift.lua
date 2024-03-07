scene = {
        Sphere={
            components = {
                EjemploComponent = { -- Prueba de un componente de juego
                    a = 1,
                    b = 2.0,
                    c = true,
                    d = "ejemplo"
                },
                Transform = {
                    positionX = 0.0,
                    positionY = 3.0,
                    positionZ = 0.0,
                    scaleX = 2.0,
                    scaleY = 2.0,
                    scaleZ = 2.0,
                    rotationX = -90.0,
                    rotationY = 0.0,
                    rotationZ = 0.0
                },
                RigidBody = {
                    colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                    colliderScaleX=2.0,
                    colliderScaleY=2.0,
                    colliderScaleZ=2.0,
                    isTrigger=false,
                    movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                    mass=3.0,
                    friction=1.0,
                    damping=0.4,
                    bounciness=0.0
                }
            }
        },
        Ground={
            components={
                Transform = {
                    positionX = 0.0,
                    positionY = -4.0,
                    positionZ = 0.0,
                    scaleX = 2.0,
                    scaleY = 2.0,
                    scaleZ = 2.0,
                    rotationX = 0.0,
                    rotationY = 0.0,
                    rotationZ = 0.0
                },
                RigidBody = {    
                    colShape=2, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                    colliderScaleX=0.0,
                    colliderScaleY=1.0,
                    colliderScaleZ=0.0,
                    isTrigger=false,
                    movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                    mass=0.0,
                    friction=1.0,
                    damping=0.998,
                    bounciness=1.0
                }
            }
        }
    }
