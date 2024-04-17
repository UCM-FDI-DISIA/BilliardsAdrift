scene = {
    {
        components = {
            CameraComponent = {
                zOrder = 1, -- Cuando se arregle, se podrá cambiar a 0
                bgColorR = 0.0,
                bgColorG = 0.8,
                bgColorB = 0.0
            }
        }
    },
    TitleText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 150
            },
            Text = {
                name = "BilliardsAdriftText",
                text = "Billiards Adrift",
                textFontName = "HARLOWSI.TTF",
                textSize = 75.0
            }
        }
    },
    PlayButton = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2,
                positionZ = 0.0,
                scaleX = 130.0,
                scaleY = 40.0,
                scaleZ = 1.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            Button = { -- Usar PlayButton component cuando se cree
                name = "PlayButton",
                text = "Play",
            }
        }
    },
    TemporalText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 + 100,
                positionZ = 0.0,
                scaleX = 0.0,
                scaleY = 0.0,
                scaleZ = 0.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            Text = {
                name = "TemporalText",
                text = "ESTO ES TEMPORAL :)",
                textSize = 20.0
            }
        }
    }

    -- Ground={
    --     components={
    --         Transform = {
    --             positionX = 0.0,
    --             positionY = -4.0,
    --             positionZ = 0.0,
    --             scaleX = 0.1,
    --             scaleY = 0.02,
    --             scaleZ = 0.2,
    --             rotationX = 0.0,
    --             rotationY = 0.0,
    --             rotationZ = 0.0
    --         },
    --         MeshRenderer = {
    --             meshName = "models/cube.mesh",
    --             materialName= "green"
    --         },
    --         RigidBody = {    
    --             colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
    --             colliderScaleX=6.0,
    --             colliderScaleY=1.0,
    --             colliderScaleZ=10.0,
    --             isTrigger=false,
    --             movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
    --             mass=0.0,
    --             friction=1.0,
    --             damping=0.0,
    --             bounciness=1.0
    --         }
    --     }
    -- }
}