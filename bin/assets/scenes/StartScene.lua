scene = {
    {
        components = {
            CameraComponent = {
                bgColorR = 0.0,
                bgColorG = 0.5,
                bgColorB = 0.0
            },
            SplashScreenComponent = {
                changeTime = 2000,
                splashScene = "StartScene",
                mainScene = "GameManager"
            }
        }
    },
    madeWithText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 40
            },
            Text = {
                text = "made with",
                textSize = 32.0,
                textFontName = "AGENCYB.TTF"
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
                text = "Tapioca Engine",
                textSize = 72.0,
                textFontName = "AGENCYB.TTF"
            }
        }
    }
}
  