scene = {
        Ball8={
            components={
            Transform = {
                positionX = 0.0,
                positionY = 0.0,
                positionZ = 5.0,
                scaleX = 0.1,
                scaleY = 0.1,
                scaleZ = 0.1,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "meshes/sphere.mesh",
                materialName= "ball8"
                --     }--]]--
            -- + componentes 
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
                bounciness=1.0
            }
            }
        -- + entidades
     }, 
     Cue={
        components={
        Transform = {
            positionX = 0.0,
            positionY = 0.0,
            positionZ = 0.0,
            scaleX = 0.01,
            scaleY = 0.01,
            scaleZ = 0.01,
            rotationX = 0.0,
            rotationY = 0.0,
            rotationZ = 0.0
        }, 
        MeshRenderer = {
            meshName = "meshes/cube.mesh",
            materialName= "ball8"
        },
        RigidBody = {    
            colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
            colliderScaleX=0.5,
            colliderScaleY=0.5,
            colliderScaleZ=5.0,
            isTrigger=false,
            movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
            mass=3.0,
            friction=1.0,
            damping=0.4,
            bounciness=0.0
        },
        CueController = {    
            powerFactor=20.0,
            moveFactor=1.0
        }
        }
    -- + entidades
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
                    colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                    colliderScaleX=10.0,
                    colliderScaleY=1.0,
                    colliderScaleZ=10.0,
                    isTrigger=false,
                    movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                    mass=0.0,
                    friction=1.0,
                    damping=0.0,
                    bounciness=1.0
                }
            }
        }
    }
