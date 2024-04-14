scene = {
    {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = 0.0,
                positionZ = 0.0,
                scaleX = 1.0,
                scaleY = 1.0,
                scaleZ = 1.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            CameraComponent = {
                zOrder = 2, -- Cuando se arregle lo del viewport, se podrá cambiar a 0
                bgColorR = 0.0,
                bgColorG = 0.8,
                bgColorB = 0.0,
                targetToLookX = 0.0,
                targetToLookY = 0.0,
                targetToLookZ = 0.0
            }
        }
    },
    ContinueImageButton={
        -- zIndex = 0, -- No importa si es 0
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2-50,
                positionZ = 0.0, -- No importa
                scaleX = 200.0,
                scaleY = 70.0,
                scaleZ = 0.0, -- No importa
                rotationX = 0.0, -- No importa
                rotationY = 0.0, -- No importa
                rotationZ = 0.0 -- No importa
            },
            ImageTextButton = {
                name = "ContinueButton",
                onClickId = "Continue",
                wantText = false,
                imagePathNormal = "textures/buttons/continue1.png",
                imagePathHover = "textures/buttons/continue2.png",
                imagePathActive = "textures/buttons/continue3.png",
                uv0X = 0.0,
                uv0Y = 0.0,
                uv1X = 1.0,
                uv1Y = 1.0,
                imageBgColorR = 0.0,
                imageBgColorG = 0.0,
                imageBgColorB = 0.0,
                imageBgColorA = 0.0,
                imageTintR = 1.0,
                imageTintG = 1.0,
                imageTintB = 1.0,
                imageTintA = 1.0,
                normalColorR = 0.0, -- Con el alpha en 0.0 en todos los estados solo se vera las imagenes del boton
                normalColorG = 0.0,
                normalColorB = 0.0,
                normalColorA = 0.0,
                hoverColorR = 0.0,
                hoverColorG = 0.0,
                hoverColorB = 0.0,
                hoverColorA = 0.0,
                activeColorR = 0.0,
                activeColorG = 0.0,
                activeColorB = 0.0,
                activeColorA = 0.0,
                -- windowFlags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoSavedSettings
            }
        }
    },

    RestartImageButton={
        -- zIndex = 0, -- No importa si es 0
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2+50,
                positionZ = 0.0, -- No importa
                scaleX = 200.0,
                scaleY = 70.0,
                scaleZ = 0.0, -- No importa
                rotationX = 0.0, -- No importa
                rotationY = 0.0, -- No importa
                rotationZ = 0.0 -- No importa
            },
            ImageTextButton = {
                name = "RestartButton",
                onClickId = "Restart",
                wantText = false,
                imagePathNormal = "textures/buttons/restart1.png",
                imagePathHover = "textures/buttons/restart2.png",
                imagePathActive = "textures/buttons/restart3.png",
                uv0X = 0.0,
                uv0Y = 0.0,
                uv1X = 1.0,
                uv1Y = 1.0,
                imageBgColorR = 0.0,
                imageBgColorG = 0.0,
                imageBgColorB = 0.0,
                imageBgColorA = 0.0,
                imageTintR = 1.0,
                imageTintG = 1.0,
                imageTintB = 1.0,
                imageTintA = 1.0,
                normalColorR = 0.0, -- Con el alpha en 0.0 en todos los estados solo se vera las imagenes del boton
                normalColorG = 0.0,
                normalColorB = 0.0,
                normalColorA = 0.0,
                hoverColorR = 0.0,
                hoverColorG = 0.0,
                hoverColorB = 0.0,
                hoverColorA = 0.0,
                activeColorR = 0.0,
                activeColorG = 0.0,
                activeColorB = 0.0,
                activeColorA = 0.0,
                -- windowFlags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoSavedSettings
            }
        }
    },

    MainMenuImageButton={
        -- zIndex = 0, -- No importa si es 0
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = WINDOW_HEIGHT / 2+150,
                positionZ = 0.0, -- No importa
                scaleX = 200.0,
                scaleY = 70.0,
                scaleZ = 0.0, -- No importa
                rotationX = 0.0, -- No importa
                rotationY = 0.0, -- No importa
                rotationZ = 0.0 -- No importa
            },
            ImageTextButton = {
                name = "MainMenuButton",
                onClickId = "MainMenu",
                wantText = false,
                imagePathNormal = "textures/buttons/mainMenu1.png",
                imagePathHover = "textures/buttons/mainMenu2.png",
                imagePathActive = "textures/buttons/mainMenu3.png",
                uv0X = 0.0,
                uv0Y = 0.0,
                uv1X = 1.0,
                uv1Y = 1.0,
                imageBgColorR = 0.0,
                imageBgColorG = 0.0,
                imageBgColorB = 0.0,
                imageBgColorA = 0.0,
                imageTintR = 1.0,
                imageTintG = 1.0,
                imageTintB = 1.0,
                imageTintA = 1.0,
                normalColorR = 0.0, -- Con el alpha en 0.0 en todos los estados solo se vera las imagenes del boton
                normalColorG = 0.0,
                normalColorB = 0.0,
                normalColorA = 0.0,
                hoverColorR = 0.0,
                hoverColorG = 0.0,
                hoverColorB = 0.0,
                hoverColorA = 0.0,
                activeColorR = 0.0,
                activeColorG = 0.0,
                activeColorB = 0.0,
                activeColorA = 0.0,
                -- windowFlags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoSavedSettings
            }
        }
    }


}