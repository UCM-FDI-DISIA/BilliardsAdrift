scene = {
    GameOverText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 250
            },
            Text = {
                text = "You Win",
                textSize = 150.0,
                textFontName = "06126_BRITANIC.TTF",
                textColorR = 0.0,
                textColorG = 0.0,
                textColorB = 0.0
            }
        }
    },
    ContinueImageButton = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 30,
                scaleX = 344.0, 
                scaleY = 120.0
            },
            ImageTextButton = {
                onClickId = "Continue",
                wantText = false,
                imagePathNormal = "buttons/continue1.png",
                imagePathHover = "buttons/continue2.png",
                imagePathActive = "buttons/continue3.png",
                normalColorA = 0.0,
                hoverColorA = 0.0,
                activeColorA = 0.0
            }
        }
    },
    RestartImageButton = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 + 110,
                scaleX = 344.0, 
                scaleY = 120.0
            },
            ImageTextButton = {
                onClickId = "Restart",
                imagePathNormal = "buttons/restart1.png",
                imagePathHover = "buttons/restart2.png",
                imagePathActive = "buttons/restart3.png",
                normalColorA = 0.0,
                hoverColorA = 0.0,
                activeColorA = 0.0,
            }
        }
    },
    MainMenuImageButton = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 + 250,
                scaleX = 344.0, 
                scaleY = 120.0
            },
            ImageTextButton = {
                onClickId = "MainMenu",
                imagePathNormal = "buttons/mainMenu1.png",
                imagePathHover = "buttons/mainMenu2.png",
                imagePathActive = "buttons/mainMenu3.png",
                normalColorA = 0.0,
                hoverColorA = 0.0,
                activeColorA = 0.0,
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