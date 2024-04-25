scene = {
    GameOverText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 150
            },
            Text = {
                text = "You Win",
                textSize = 90.0,
                textFontName = "06126_BRITANIC.TTF",
                textColorR = 0.0,
                textColorG = 0.0,
                textColorB = 0.0
            }
        }
    },
    ContinueImageButton={
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 50,
                scaleX = 200.0,
                scaleY = 70.0
            },
            ImageTextButton = {
                onClickId = "Continue",
                wantText = false,
                imagePathNormal = "textures/buttons/continue1.png",
                imagePathHover = "textures/buttons/continue2.png",
                imagePathActive = "textures/buttons/continue3.png",
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
                positionY = WINDOW_HEIGHT / 2+50,
                scaleX = 200.0,
                scaleY = 70.0,
            },
            ImageTextButton = {
                onClickId = "Restart",
                imagePathNormal = "textures/buttons/restart1.png",
                imagePathHover = "textures/buttons/restart2.png",
                imagePathActive = "textures/buttons/restart3.png",
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
                positionY = WINDOW_HEIGHT / 2 + 150,
                scaleX = 200.0,
                scaleY = 70.0,
            },
            ImageTextButton = {
                onClickId = "MainMenu",
                imagePathNormal = "textures/buttons/mainMenu1.png",
                imagePathHover = "textures/buttons/mainMenu2.png",
                imagePathActive = "textures/buttons/mainMenu3.png",
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
                imagePath = "textures/menuBackground.png"
            }
        }
    }
}