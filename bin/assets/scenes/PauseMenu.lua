scene = {
    PauseMenuText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2 - 150,
            },
            Text = {
                text = "Game paused",
                textSize = 75.0,
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
                positionY = WINDOW_HEIGHT / 2,
                scaleX = 200.0,
                scaleY = 70.0
            },
            ImageTextButton = {
                onClickId = "Resume",
                imagePathNormal = "buttons/resume1.png",
                imagePathHover = "buttons/resume2.png",
                imagePathActive = "buttons/resume3.png",
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
                positionY = WINDOW_HEIGHT * 2 / 3,
                scaleX = 200.0,
                scaleY = 70.0
            },
            ImageTextButton = {
                onClickId = "MainMenu",
                imagePathNormal = "buttons/mainMenu1.png",
                imagePathHover = "buttons/mainMenu2.png",
                imagePathActive = "buttons/mainMenu3.png",
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