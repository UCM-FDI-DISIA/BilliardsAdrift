scene = {
    TitleText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 250
            },
            Text = {
                text = "Billiards Adrift",
                textSize = 150.0,
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
                positionY = WINDOW_HEIGHT / 2 - 60,
                scaleX = 344.0, 
                scaleY = 120.0
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
    ControlsButton = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 + 80,
                scaleX = 344.0, 
                scaleY = 120.0
            },
            ImageTextButton = {
                onClickId = "Controls",
                imagePathNormal = "buttons/controls1.png",
                imagePathHover = "buttons/controls2.png",
                imagePathActive = "buttons/controls3.png",
                normalColorA = 0.0,
                hoverColorA = 0.0,
                activeColorA = 0.0
            }
        }
    },
    RulesButton = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 + 220,
                scaleX = 344.0, 
                scaleY = 120.0
            },
            ImageTextButton = {
                onClickId = "Rules",
                imagePathNormal = "buttons/rules1.png",
                imagePathHover = "buttons/rules2.png",
                imagePathActive = "buttons/rules3.png",
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
                positionY = WINDOW_HEIGHT / 2 + 360,
                scaleX = 344.0, 
                scaleY = 120.0
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