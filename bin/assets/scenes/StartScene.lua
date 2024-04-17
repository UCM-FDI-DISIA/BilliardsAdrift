scene = {
    {
        components = {
            CameraComponent = { -- Para tener un fondo
                zOrder = -1, -- Cuando se arregle, se podrá cambiar a 0
            },
            SplashScreenComponent = {
                changeTime = 2000,
                gameName = "game"
            }
        }
    },
    madeWithText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 20
            },
            Text = {
                name = "madeWithText",
                text = "made with",
                textFontName = "AGENCYB.TTF",
            }
        }
    },
    TapiocaText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2
            },
            Text = {
                name = "TapiocaText",
                text = "Tapioca Engine",
                textSize = 36.0,
                textFontName = "AGENCYB.TTF",
            }
        }
    }
}
