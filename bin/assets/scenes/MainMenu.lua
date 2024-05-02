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
                positionY = WINDOW_HEIGHT / 2-50,
                scaleX = 172.0, 
                scaleY = 60.0
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
                positionY = WINDOW_HEIGHT / 2+20,
                scaleX = 172.0, 
                scaleY = 60.0
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
                positionY = WINDOW_HEIGHT / 2+90,
                scaleX = 172.0, 
                scaleY = 60.0
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
                positionY = WINDOW_HEIGHT / 2+160,
                scaleX = 172.0, 
                scaleY = 60.0
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