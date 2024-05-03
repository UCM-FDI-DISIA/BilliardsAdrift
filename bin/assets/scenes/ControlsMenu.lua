scene = {
    BackButton = {
        zIndex = 0,
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT - 100,
                scaleX = 344.0, 
                scaleY = 120.0
            },
            ImageTextButton = {
                onClickId = "Back",
                imagePathNormal = "buttons/back1.png",
                imagePathHover = "buttons/back2.png",
                imagePathActive = "buttons/back3.png",
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
                imagePath = "menuControls.png"
            }
        }
    }
}