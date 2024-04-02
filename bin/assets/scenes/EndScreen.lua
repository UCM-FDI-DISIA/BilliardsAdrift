scene = {
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
                meshName = "models/cube.mesh",
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
}