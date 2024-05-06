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
                sourcepath = "pick.mp3"
            }
        }
    },
    ExplosiveSound = {
        components = {
            AudioSourceComponent = {
                sourcepath = "explosion.mp3"
            }
        }
    }
    ,
    InGameMusic= {
        components = {
            AudioSourceComponent = {
                islooping=true,
                sourcepath = "Suspicious_Pool_Loop.mp3"
            }
           
        }
    },
    MainMenuMusic={
        components={

            AudioSourceComponent = {
                islooping=true,
                ispaused=false,
                sourcepath = "BilliardsMainMenu.wav"
            }


        }

    }

    
}