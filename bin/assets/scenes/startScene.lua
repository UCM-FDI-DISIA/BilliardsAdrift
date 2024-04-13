scene = {
    {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = 30.0,
                positionZ = 0.0,
                scaleX = 1.0,
                scaleY = 1.0,
                scaleZ = 1.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 90.0
            },
            CameraComponent = {
                zOrder = -1, -- Cuando se arregle lo de cargar las escenas después de haber recorrido todas las entidades, se podrá cambiar a 0
                bgColorR = 0.0,
                bgColorG = 0.8,
                bgColorB = 0.0,
                targetToLookX = 0.0,
                targetToLookY = 0.0,
                targetToLookZ = 0.0
            }
        }
    },
    madeWithText={
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 20,
                positionZ = 0.0,
                scaleX = 0.0,
                scaleY = 0.0,
                scaleZ = 0.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            Text = {
                name = "madeWithText",
                text = "made with",
                textFontName = "AGENCYB.TTF"
            }
        }
    },
    StartText={
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2,
                positionZ = 0.0,
                scaleX = 0.0,
                scaleY = 0.0,
                scaleZ = 0.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            Text = {
                name = "StartText",
                text = "Tapioca Engine",
                textSize = 36.0,
                textFontName = "AGENCYB.TTF"
            }
        }
    }
}
