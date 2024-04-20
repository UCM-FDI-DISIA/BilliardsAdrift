scene = {
    {
        components = {
            GameManager = {
                firstStateName = "Level1", -- Cambiar a MainMenu cuando se gestione los callbacks de los botones
                initLife = 3,
                initTime = 9999.0
            }
        }
    },
    {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = 60.0,
                positionZ = 0.0,
                scaleX = 1.0,
                scaleY = 1.0,
                scaleZ = 1.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 90.0
            },
            CameraComponent = {
                zOrder = 0,
                bgColorR = 0.925,
                bgColorG = 0.698,
                bgColorB = 0.941,
                targetToLookX = 0.0,
                targetToLookY = 0.0,
                targetToLookZ = 0.0
            }
        }
    },
}