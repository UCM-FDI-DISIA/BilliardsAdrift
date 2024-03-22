scene = {
    Sinbad={
        components={
            Transform = {
                positionX = 0.0,
                positionY = 0.0,
                positionZ = -8.0,
                scaleX = 0.6,
                scaleY = 0.6,
                scaleZ = 0.6,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "Sinbad.mesh",
            },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=1.0,
                colliderScaleY=1.0,
                colliderScaleZ=1.0,
                isTrigger=false,
                movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            },
            Animator = {
                playbackSpeed=0.001
            }
        }
    },
    Cue={
        components={
            Transform = {
                positionX = 0.0,
                positionY = 0.0,
                positionZ = 0.0,
                scaleX = 10.0,
                scaleY = 10.0,
                scaleZ = 10.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "CueStick/CueStick.mesh",
            },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.3,
                colliderScaleY=0.3,
                colliderScaleZ=5.0,
                isTrigger=false,
                movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=10.0,
                friction=1.0,
                damping=0.4,
                bounciness=0.0
            },
            CueController = {    
                powerFactor=20.0,
                moveFactor=1.0
            }
        }
    },
    Ground={
        components={
            Transform = {
                positionX = 0.0,
                positionY = -4.0,
                positionZ = 0.0,
                scaleX = 0.1,
                scaleY = 0.02,
                scaleZ = 0.2,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            MeshRenderer = {
                meshName = "meshes/cube.mesh",
                materialName= "green"
            },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=6.0,
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
    },
    Ball1={
        components={
            Transform = {
                positionX = 0.0,
                positionY = 5.0,
                positionZ = 6.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "Ball1/Ball1.mesh"
            },
            RigidBody = {    
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=1.0,
                colliderScaleY=1.0,
                colliderScaleZ=1.0,
                isTrigger=false,
                movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            }
        }
    }
}