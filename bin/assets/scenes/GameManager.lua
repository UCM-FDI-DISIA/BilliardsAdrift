scene = {
    {
        components = {
            GameManager = {
                firstStateName = "MainMenu",
                initLife = 3,
                initTime = 9999.0
            }
        }
    },
    PickSound={
        components = {
            AudioSourceComponent={
                sourcepath="assets/audio/pick.mp3"
            }
        }
    },
    ExplosiveSound={
        components = {
            AudioSourceComponent={
                sourcepath="assets/audio/explosion.mp3"
            }
        }
    }


}