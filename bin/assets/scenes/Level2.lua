scene = {
    {
        components = {
            Transform = {
                positionY = 63.0,
                rotationZ = 90.0
            },
            CameraComponent = {
                bgColorR = 0.925,
                bgColorG = 0.698,
                bgColorB = 0.941,
                targetToLookX = 0.0,
                targetToLookY = 0.0,
                targetToLookZ = 0.0
            },
            
            LightDirComp = {
                directionX = 0.0,
                directionY = -1.0,
                directionZ = 0.0,
                mainLight = true,
                colorR = 0.6,
                colorG = 0.6,
                colorB = 1.0,
                colorA = 1.0,
                powerScale = 0.35
            },  
        }
    },

    LightSpot = {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = 100.0,
                positionZ = 0.0,
                scaleX = 0.0,
                scaleY = 0.0,
                scaleZ = 0.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            LightSpotComp = {
                directionX = 0.0,
                directionY = -1.0,
                directionZ = 0.0,
                mainLight = true,
                colorR = 1.0,
                colorG = 0.9,
                colorB = 0.5,
                colorA = 1.0,
                powerScale = 60.0,
                attenuationFactor = 1.0,
                falloff = 0.5,
                innerAngle = 500,
                outerAngle = 1500
            }
        }
    },

    -- HUD
    LivesText = {
        components = {
            Transform = {
                positionX = 100.0,
                positionY = 50.0
            },
            Text = {
                text = "Lives: 0",
                textSize = 40.0,
                textFontName = "AGENCYB.TTF"
            }
        }
    },
    TimerText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = 50.0
            },
            Text = {
                text = "Timer",
                textSize = 40.0,
                textFontName = "AGENCYB.TTF",
            }
        }
    },
    PowerBar = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 5,
                positionY = WINDOW_HEIGHT - 60,
                scaleX = 400.0
            },
            ProgressBar = { }
        }
    },
    
    Cue = {
        components = { },
        children = {
            CueContainer = {
                components = {
                    Transform = {
                        positionX = 0.0,
                        positionY = 0.0,
                        positionZ = -8.0, --offset
                        scaleX = 10.0,
                        scaleY = 10.0,
                        scaleZ = 10.0,
                        rotationX = 0.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    }, 
                    MeshRenderer = {
                        meshName = "models/CueStick/CueStick.mesh",
                    },
                    CueController = {
                        powerFactor = 10.0,
                        maxPower = 100.0,
                        moveBackwardFactor = 0.5,
                        rotateFactor = 0.3,
                        impulseTime = 0.5,
                    },
                    
                    AudioSourceComponent={
                        sourcepath = "assets/audio/hitBall.mp3"
                    }
                }
            },
            Trayectory = {
                components = {
                    Transform = {
                        positionX = 0.0,
                        positionY = 0.0,
                        positionZ = 1.0, --offset
                        scaleX = 0.003,  
                        scaleY = 0.003,
                        scaleZ = 0.000,
                        rotationX = 0.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    }, 
                    MeshRenderer = {
                        meshName = "models/cube.mesh",
                        materialName = "white"
                    }
                }
            }
        }
    },
    BallPlayer = {
        components = {
            Transform = {
                positionX = 10.0,
                positionY = 8.0,
                positionZ = 0.0,
                scaleX = 0.7,
                scaleY = 0.7,
                scaleZ = 0.7,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball1/Ball1.mesh",
                materialName = "white"
            },
            RigidBody = {    
                colShape = 1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.43,
                colliderScaleY = 1.43,
                colliderScaleZ = 1.43,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "white"
            },
            AudioSourceComponent={
                sourcepath="assets/audio/hitBall.mp3"
            },
            WhiteBallComponent = { 

            }
        }
    },

    MovableWall1 = {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = 8.2,
                positionZ = -8.0,
                scaleX = 1.0,
                scaleY = 1.0,
                scaleZ = 4.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            MeshRenderer = {
                meshName = "models/cube2.mesh",
                materialName = "floor"
            },
            RigidBody = {    
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
                isTrigger = false,
                movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 0.0,
                friction = 1.0,
                damping = 0.0,
                bounciness = 0.5
            },
            MovableWall = {    
                speed = 0.01,
                destX = 0.0,
                destZ = 8.0
            },
            WallComponent = { },
            AudioSourceComponent={
                sourcepath="assets/audio/hitWall.mp3"
            }
        }
    },
  
    Table = {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = 0.0,
                positionZ = 0.0,
                scaleX = 0.1,
                scaleY = 0.1,
                scaleZ = 0.1,
                rotationX = -90.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            MeshRenderer = {
                meshName = "models/Table2/Table.mesh"
            },
            RigidBody = {    
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 300.0,
                colliderScaleY = 150.0,
                colliderScaleZ = 68.5,
                isTrigger = false,
                movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 0.0,
                friction = 0.5,
                damping = 0.0,
                bounciness = 1.0
            }
        },
        children = {
            Wall1 = {
                components = {
                    Transform = {
                        positionX = -300.0,
                        positionY = 0.0,
                        positionZ = 60.0,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX = 250.0,
                        colliderScaleY = 700.0,
                        colliderScaleZ = 2700.0,
                        isTrigger = false,
                        movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass = 0.0,
                        friction = 0.5,
                        damping = 0.0,
                        bounciness = 1.0
                    },
                    WallComponent = { },
                    AudioSourceComponent={
                        sourcepath="assets/audio/hitWall.mp3"
                    }
                }
            },
            Wall2 = {
                components = {
                    Transform = {
                        positionX = 300.0,
                        positionY = 0.0,
                        positionZ = 60.0,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX = 250.0,
                        colliderScaleY = 700.0,
                        colliderScaleZ = 2700.0,
                        isTrigger = false,
                        movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass = 0.0,
                        friction = 1.0,
                        damping = 0.0,
                        bounciness = 1.0
                    },
                    WallComponent = { },
                    AudioSourceComponent={
                        sourcepath="assets/audio/hitWall.mp3"
                    }
                }
            },
            Wall3 = {
                components = {
                    Transform = {
                        positionX = 0.0,
                        positionY = 155.0,
                        positionZ = 60.0,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX = 6000.0,
                        colliderScaleY = 800.0,
                        colliderScaleZ = 200.0,
                        isTrigger = false,
                        movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass = 0.0,
                        friction = 1.0,
                        damping = 0.0,
                        bounciness = 1.0
                    },
                    WallComponent = { },
                    AudioSourceComponent={
                        sourcepath="assets/audio/hitWall.mp3"
                    }
                }
            },
            Wall4 = {
                components = {
                    Transform = {
                        positionX = 0.0,
                        positionY = -155.0,
                        positionZ = 60.0,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX = 6000.0,
                        colliderScaleY = 800.0,
                        colliderScaleZ = 200.0,
                        isTrigger = false,
                        movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass = 0.0,
                        friction = 1.0,
                        damping = 0.0,
                        bounciness = 1.0
                    },
                    WallComponent = { },
                    AudioSourceComponent={
                        sourcepath="assets/audio/hitWall.mp3"
                    }
                }
            }
        }
    },
    BallYellow = {
        components = {
            Transform = {
                positionX = -19.9,
                positionY = 8.2,
                positionZ = -7.0,
                scaleX = 0.7,
                scaleY = 0.7,
                scaleZ = 0.7,
                rotationX = 180.0,
                rotationY = 0.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball1/Ball1.mesh"
            },
            RigidBody = {    
                colShape = 1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.43,
                colliderScaleY = 1.43,
                colliderScaleZ = 1.43,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "yellow"
            } ,
            AudioSourceComponent={
                sourcepath = "assets/audio/hitBall.mp3"
            }
        }
    },
    BallBlue = {
        components = {
            Transform = {
                positionX = 17.2,
                positionY = 8.2,
                positionZ = -3.0,
                scaleX = 0.7,
                scaleY = 0.7,
                scaleZ = 0.7,
                rotationX = 180.0,
                rotationY = 0.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball2/Ball2.mesh"
            },
            RigidBody = {    
                colShape = 1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.43,
                colliderScaleY = 1.43,
                colliderScaleZ = 1.43,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "blue"
            } ,
            AudioSourceComponent={
                sourcepath="assets/audio/hitBall.mp3"
            }
        }
    },
    BallRed = {
        components = {
            Transform = {
                positionX = -24.0,
                positionY = 8.2,
                positionZ = 6.0,
                scaleX = 0.7,
                scaleY = 0.7,
                scaleZ = 0.7,
                rotationX = 180.0,
                rotationY = 0.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball3/Ball3.mesh"
            },
            RigidBody = {    
                colShape = 1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.43,
                colliderScaleY = 1.43,
                colliderScaleZ = 1.43,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "red"
            } ,
            AudioSourceComponent={
                sourcepath="assets/audio/hitBall.mp3"
            }
        }
    },
    BallPurple = {
        components = {
            Transform = {
                positionX = 8.1,
                positionY = 8.2,
                positionZ = 2.3,
                scaleX = 0.7,
                scaleY = 0.7,
                scaleZ = 0.7,
                rotationX = 180.0,
                rotationY = 0.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball4/Ball4.mesh"
            },
            RigidBody = {    
                colShape = 1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.43,
                colliderScaleY = 1.43,
                colliderScaleZ = 1.43,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "purple"
            } ,
            AudioSourceComponent={
                sourcepath="assets/audio/hitBall.mp3"
            }
        }
    },
    BallOrange = {
        components = {
            Transform = {
                positionX = -11.6,
                positionY = 8.2,
                positionZ = 5.9,
                scaleX = 0.7,
                scaleY = 0.7,
                scaleZ = 0.7,
                rotationX = 180.0,
                rotationY = 0.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball5/Ball5.mesh"
            },
            RigidBody = {    
                colShape = 1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.43,
                colliderScaleY = 1.43,
                colliderScaleZ = 1.43,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "orange"
            } ,
            AudioSourceComponent={
                sourcepath="assets/audio/hitBall.mp3"
            }
        }
    },
    BallGreen = {
        components = {
            Transform = {
                positionX = 6.9,
                positionY = 8.2,
                positionZ = -8.2,
                scaleX = 0.7,
                scaleY = 0.7,
                scaleZ = 0.7,
                rotationX = 180.0,
                rotationY = 0.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball6/Ball6.mesh"
            },
            RigidBody = {    
                colShape = 1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.43,
                colliderScaleY = 1.43,
                colliderScaleZ = 1.43,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "green"
            } ,
            AudioSourceComponent={
                sourcepath="assets/audio/hitBall.mp3"
            }
        }
    },
    BallBlack = {
        components = {
            Transform = {
                positionX = 22.5,
                positionY = 8.2,
                positionZ = 9.0,
                scaleX = 0.7,
                scaleY = 0.7,
                scaleZ = 0.7,
                rotationX = 180.0,
                rotationY = 0.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball8/Ball8.mesh"
            },
            RigidBody = {    
                colShape = 1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.43,
                colliderScaleY = 1.43,
                colliderScaleZ = 1.43,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "black"
            } ,
            AudioSourceComponent={
                sourcepath="assets/audio/hitBall.mp3"
            }
        }
    },
    Heart1 = {
        components = {
            Transform = {
                positionX = -14.4,
                positionY = 8.2,
                positionZ = -9.7,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 180.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/heart/heart.mesh",
                materialName = "heart"
            },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
                isTrigger = true,
                movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 1.0,
                damping = 0.4,
                bounciness = 0.5
            },
            HeartComponent = { }
        }
    },
    Heart2 = {
        components = {
            Transform = {
                positionX = 14.4,
                positionY = 8.2,
                positionZ = 8.4,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 180.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/heart/heart.mesh",
                materialName = "heart"
            },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
                isTrigger = true,
                movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 1.0,
                damping = 0.4,
                bounciness = 0.5
            },
            HeartComponent = { }
        }
    },
    Clock = { 
        components = {
            Transform = {
                positionX = -16.0,
                positionY = 8.2,
                positionZ = 2.0,
                scaleX = 1.2,
                scaleY = 1.2,
                scaleZ = 1.2,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/Clock/Clock.mesh"
            },
            RigidBody = {    
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 0.83,
                colliderScaleY = 0.83,
                colliderScaleZ = 0.83,
                isTrigger = true,
                movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 1.0,
                damping = 0.4,
                bounciness = 0.5
            },
            ClockComponent = { },
            AudioSourceComponent={
                sourcepath="assets/audio/pick.mp3"
            }
        }
    },
    Accelerator1 = {
        components = {
            Transform = {
                positionX = -22.7,
                positionY = 7.0,
                positionZ = 11.0,
                scaleX = 9.0,
                scaleY = 9.0,
                scaleZ = 9.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            RigidBody = {    
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 0.11,
                colliderScaleY = 0.11,
                colliderScaleZ = 0.11,
                isTrigger = true,
                movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 0.0,
                friction = 0.0,
                damping = 0.0,
                bounciness = 0.0
            },
            Accelerator = {    
                speedFactor = 5.0,
            },
            PlaneComponent = {  
                materialName = "lighting",
                upX = 0.0,
                upY = 0.0,
                upZ = -1.0,
                rkNormalX = 0.0,
                rkNormalY = 1.0,
                rkNormalZ = 0.0,
                width = 3.0,
                height = 3.0,
            }
        }
    },
    Accelerator2 = {
        components = {
            Transform = {
                positionX = 22.9,
                positionY = 7.0,
                positionZ = -10.2,
                scaleX = 9.0,
                scaleY = 9.0,
                scaleZ = 9.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            RigidBody = {    
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 0.11,
                colliderScaleY = 0.11,
                colliderScaleZ = 0.11,
                isTrigger = true,
                movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 0.0,
                friction = 0.0,
                damping = 0.0,
                bounciness = 0.0
            },
            Accelerator = {    
                speedFactor = 5.0,
            },
            PlaneComponent = {  
                materialName = "lighting",
                upX = 0.0,
                upY = 0.0,
                upZ = -1.0,
                rkNormalX = 0.0,
                rkNormalY = 1.0,
                rkNormalZ = 0.0,
                width = 3.0,
                height = 3.0,
            }
        }
    },
    --DECORACIONES
    Floor = {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = -10.0,
                positionZ = 0.0,
                scaleX = 200.0,
                scaleY = 200.0,
                scaleZ = 200.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            PlaneComponent = {  
                materialName = "floor",
                upX = 0.0,
                upY = 0.0,
                upZ = -1.0,
                rkNormalX = 0.0,
                rkNormalY = 1.0,
                rkNormalZ = 0.0,
                width = 200.0,
                height = 200.0,
            }
        }
    },
    Tabouret1 = {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = -8.0,
                positionZ = -23.0,
                scaleX = 5.0,
                scaleY = 5.0,
                scaleZ = 5.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/tabouret/tabouret.mesh",
            }
          }
    },
    Tabouret2 = {
        components = {
            Transform = {
                positionX = -25.0,
                positionY = -8.0,
                positionZ = -23.0,
                scaleX = 5.0,
                scaleY = 5.0,
                scaleZ = 5.0,
                rotationX = 0.0,
                rotationY = 60.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/tabouret/tabouret.mesh",
            }
          }
    },
    Tabouret3 = {
        components = {
            Transform = {
                positionX = 25.0,
                positionY = -8.0,
                positionZ = -23.0,
                scaleX = 5.0,
                scaleY = 5.0,
                scaleZ = 5.0,
                rotationX = 0.0,
                rotationY = -60.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/tabouret/tabouret.mesh",
            }
        }
    },
    HoleYellow = {
        components = {
            Transform = {
                positionX = 28.5,
                positionY = 7.5,
                positionZ = 15.0,
                scaleX = 0.6,
                scaleY = 0.6,
                scaleZ = 0.6,
                rotationX = -90.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            ColoredHole = {
                ballId = "yellow"
            },
            RigidBody = {
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.67,
                colliderScaleY = 1.67,
                colliderScaleZ = 1.67,
                isTrigger = true,
                movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 1.0,
                damping = 0.4,
                bounciness = 0.5
            },
            PlaneComponent = {  
                materialName = "yellowHoleImage",
                upX = 0.0,
                upY = 0.0,
                upZ = -1.0,
                rkNormalX = 0.0,
                rkNormalY = 1.0,
                rkNormalZ = 0.0,
                width = 3.0,
                height = 3.0,
            },        
            AudioSourceComponent={
                sourcepath="assets/audio/hole.mp3"
            }
        }
    },
    HoleOrange = {
        components = {
            Transform = {
                positionX = 28.5,
                positionY = 7.5,
                positionZ = -15.0,
                scaleX = 0.6,
                scaleY = 0.6,
                scaleZ = 0.6,
                rotationX = -90.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            ColoredHole = {
                ballId = "orange"
            },
            RigidBody = {
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.67,
                colliderScaleY = 1.67,
                colliderScaleZ = 1.67,
                isTrigger = true,
                movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 1.0,
                damping = 0.4,
                bounciness = 0.5
            },
            PlaneComponent = {  
                materialName="orangeHoleImage",
                upX = 0.0,
                upY = 0.0,
                upZ = -1.0,
                rkNormalX = 0.0,
                rkNormalY = 1.0,
                rkNormalZ = 0.0,
                width = 3.0,
                height = 3.0,
            },        
            AudioSourceComponent={
                sourcepath="assets/audio/hole.mp3"
            }
        }
    },
    HoleGreen = {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = 7.5,
                positionZ = 15.0,
                scaleX = 0.6,
                scaleY = 0.6,
                scaleZ = 0.6,
                rotationX = -90.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            ColoredHole = {
                ballId = "green"
            },
            RigidBody = {
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.67,
                colliderScaleY = 1.67,
                colliderScaleZ = 1.67,
                isTrigger = true,
                movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 1.0,
                damping = 0.4,
                bounciness = 0.5
            },
            PlaneComponent = {  
                materialName = "greenHoleImage",
                upX = 0.0,
                upY = 0.0,
                upZ = -1.0,
                rkNormalX = 0.0,
                rkNormalY = 1.0,
                rkNormalZ = 0.0,
                width = 3.0,
                height = 3.0,
            },        
            AudioSourceComponent={
                sourcepath="assets/audio/hole.mp3"
            }
        }
    },
    HoleRed = {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = 7.5,
                positionZ = -15.0,
                scaleX = 0.6,
                scaleY = 0.6,
                scaleZ = 0.6,
                rotationX = -90.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            ColoredHole = {
                ballId = "red"
            },
            RigidBody = {
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.67,
                colliderScaleY = 1.67,
                colliderScaleZ = 1.67,
                isTrigger = true,
                movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 3.0,
                friction = 2.0,
                damping = 0.4,
                bounciness = 0.5
            },
            PlaneComponent = {  
                materialName="redHoleImage",
                upX = 0.0,
                upY = 0.0,
                upZ = -1.0,
                rkNormalX = 0.0,
                rkNormalY = 1.0,
                rkNormalZ = 0.0,
                width = 3.0,
                height = 3.0,
            },        
            AudioSourceComponent={
                sourcepath="assets/audio/hole.mp3"
            }
        }
    },
    HoleBlue = {
        components = {
            Transform = {
                positionX = -28.5,
                positionY = 7.5,
                positionZ = 15.0,
                scaleX = 0.6,
                scaleY = 0.6,
                scaleZ = 0.6,
                rotationX = -90.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            ColoredHole = {
                ballId = "blue"
            },
            RigidBody = {
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.67,
                colliderScaleY = 1.67,
                colliderScaleZ = 1.67,
                isTrigger = true,
                movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 3.0,
                friction = 2.0,
                damping = 0.4,
                bounciness = 0.5
            },
            PlaneComponent = {  
                materialName="blueHoleImage",
                upX = 0.0,
                upY = 0.0,
                upZ = -1.0,
                rkNormalX = 0.0,
                rkNormalY = 1.0,
                rkNormalZ = 0.0,
                width = 3.0,
                height = 3.0,
            },        
            AudioSourceComponent={
                sourcepath="assets/audio/hole.mp3"
            }
        }
    },
    HolePurple = {
        components = {
            Transform = {
                positionX = -28.5,
                positionY = 7.5,
                positionZ = -15.0,
                scaleX = 0.6,
                scaleY = 0.6,
                scaleZ = 0.6,
                rotationX = -90.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            ColoredHole = {
                ballId = "purple"
            },
            RigidBody = {
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.67,
                colliderScaleY = 1.67,
                colliderScaleZ = 1.67,
                isTrigger = true,
                movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 3.0,
                friction = 2.0,
                damping = 0.4,
                bounciness = 0.5
            },
            PlaneComponent = {  
                materialName="purpleHoleImage",
                upX = 0.0,
                upY = 0.0,
                upZ = -1.0,
                rkNormalX = 0.0,
                rkNormalY = 1.0,
                rkNormalZ = 0.0,
                width = 3.0,
                height = 3.0,
            },        
            AudioSourceComponent={
                sourcepath="assets/audio/hole.mp3"
            }
        }
    },
    MilkTea = {
        components = {
            Transform = {
                positionX = -29.0,
                positionY = 12.2,
                positionZ = 0.0,
                scaleX = 0.5,
                scaleY = 0.5,
                scaleZ = 0.5,
                rotationX = -45.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/cat/Cat.mesh",
                --materialName = "white"
            },
            Animator = { }
        }
    },
    Bomb = {
        components = {
            Transform = {
                positionX = -4.5,
                positionY = 8.2,
                positionZ = 0.0,
                scaleX = 1.2,
                scaleY = 1.2,
                scaleZ = 1.2,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/Bomb/Bomb.mesh",
                --materialName = "white"
            },
            RigidBody = {    
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.5,
                isTrigger = true,
                movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 1.0,
                damping = 0.4,
                bounciness = 0.0
            },
            ExplosiveComponent = { 
                force = 50.0
            }
        }
    }
}