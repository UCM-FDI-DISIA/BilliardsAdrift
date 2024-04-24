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
                textFontName = "06126_BRITANIC.ttf",
                textSize = 75.0
            }
        }
    },
    PlayButton = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2,
                scaleX = 200.0,
                scaleY = 70.0
            },
            ImageTextButton = {
                name = "PlayButton",
                onClickId = "Play",
                imagePathNormal = "textures/buttons/play1.png",
                imagePathHover = "textures/buttons/play2.png",
                imagePathActive = "textures/buttons/play3.png",
                normalColorA = 0.0,
                hoverColorA = 0.0,
                activeColorA = 0.0
            }
        }
    },
    QuitButton = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT * 2 / 3,
                scaleX = 200.0,
                scaleY = 70.0
            },
            ImageTextButton = {
                name = "QuitButton",
                onClickId = "Quit",
                imagePathNormal = "textures/buttons/quit1.png",
                imagePathHover = "textures/buttons/quit2.png",
                imagePathActive = "textures/buttons/quit3.png",
                normalColorA = 0.0,
                hoverColorA = 0.0,
                activeColorA = 0.0
            }
        }
    },
    BackgroundImage = { 
        zIndex = 1,
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2,
                scaleX = WINDOW_WIDTH,
                scaleY = WINDOW_HEIGHT
            },
            Image = {
                name = "mainMenuBackground",
                imagePath = "textures/menuBackground.png"
            }
        }
    }
}