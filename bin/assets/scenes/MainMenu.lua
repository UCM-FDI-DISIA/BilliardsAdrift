scene = {
    TitleText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 150
            },
            Text = {
                text = "Billiards Adrift",
                textSize = 75.0,
                textFontName = "06126_BRITANIC.ttf",
                textColorR = 0.0,
                textColorG = 0.0,
                textColorB = 0.0
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
                onClickId = "Play",
                imagePathNormal = "buttons/play1.png",
                imagePathHover = "buttons/play2.png",
                imagePathActive = "buttons/play3.png",
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
                onClickId = "Quit",
                imagePathNormal = "buttons/quit1.png",
                imagePathHover = "buttons/quit2.png",
                imagePathActive = "buttons/quit3.png",
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
                imagePath = "menuBackground.png"
            }
        }
    }
}