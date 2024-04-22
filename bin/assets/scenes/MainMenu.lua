scene = {
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
            Button = {
                name = "PlayButton",
                text = "Play",
                onClickId = "play"
            }
        }
    },
    TemporalText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 + 100
            },
            Text = {
                name = "TemporalText",
                text = "ESTO ES TEMPORAL :)",
                textSize = 20.0
            }
        }
    },
    BackgroundImage = { 
        zIndex = 1,
        components = {
            Transform = {
                scaleX = 1500.0, -- WINDOW_WIDTH
                scaleY = 1000.0 -- WINDOW_HEIGHT
            },
            Image = {
                name = "mainMenuBackground",
                imagePath = "textures/menuBackground.png"
            }
        }
    }
}