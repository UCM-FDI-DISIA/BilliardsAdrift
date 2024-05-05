scene = {
    {
        components = {
            GameManager = {
                firstStateName = "MainMenu",
                initLives = 3,
                initTime = 9999.0
            }
        }
    },
    PickSound = {
        components = {
            AudioSourceComponent = {
                sourcepath = "assets/audio/pick.mp3"
            }
        }
    },
    ExplosiveSound = {
        components = {
            AudioSourceComponent = {
                sourcepath = "assets/audio/explosion.mp3"
            }
        }
    }
    ,
    InGameMusic= {
        components = {
            AudioSourceComponent = {
                isLooping=true,
                sourcepath = "assets/audio/Suspicious_Pool_Loop.mp3"
            }
        }
    }

    
}