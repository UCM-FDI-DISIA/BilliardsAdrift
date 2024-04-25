scene = {
    PauseMenuText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 150,
            },
            Text = {
                text = "Game paused",
                textSize = 90.0,
                textFontName = "06126_BRITANIC.TTF",
                textColorR = 0.0,
                textColorG = 0.0,
                textColorB = 0.0
            }
        }
    },
    ResumeImageButton={
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 50,
                scaleX = 200.0,
                scaleY = 70.0
            },
            ImageTextButton = {
                onClickId = "Resume",
                imagePathNormal = "textures/buttons/resume1.png",
                imagePathHover = "textures/buttons/resume2.png",
                imagePathActive = "textures/buttons/resume3.png",
                normalColorA = 0.0,
                hoverColorA = 0.0,
                activeColorA = 0.0
            }
        }
    },
    OptionsImageButton={
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 + 50,
                scaleX = 200.0,
                scaleY = 70.0,
            },
            ImageTextButton = {
                onClickId = "Restart",
                wantText = false,
                imagePathNormal = "textures/buttons/options1.png",
                imagePathHover = "textures/buttons/options2.png",
                imagePathActive = "textures/buttons/options3.png",
                normalColorA = 0.0,
                hoverColorA = 0.0,
                activeColorA = 0.0
            }
        }
    },
    MainMenuImageButton = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 + 150,
                scaleX = 200.0,
                scaleY = 70.0
            },
            ImageTextButton = {
                onClickId = "MainMenu",
                imagePathNormal = "textures/buttons/mainMenu1.png",
                imagePathHover = "textures/buttons/mainMenu2.png",
                imagePathActive = "textures/buttons/mainMenu3.png",
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
                imagePath = "textures/menuBackground.png"
            }
        }
    }
}