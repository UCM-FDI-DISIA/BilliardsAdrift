scene = {
    {
        components = {
            -- Transform = {
            --     positionX = 80.0,
            --     positionY = 20.0,
            --     positionZ = 80.0,
            --     scaleX = 1.0,
            --     scaleY = 1.0,
            --     scaleZ = 1.0,
            --     rotationX = 0.0,
            --     rotationY = 0.0,
            --     rotationZ = 0.0
            -- },
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
                positionY = 100.0
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

    TimerText = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = 10.0
            },
            Text = {
                name = "TimerText",
                text = "Timer",
                textSize = 20.0,
                textFontName = "AGENCYB.TTF"
            }
        }
    },
    PowerBar = {
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 5,
                positionY = WINDOW_HEIGHT - 50,
                scaleX = 200.0
            },
            ProgressBar = {
                name = "PowerBar",
                barColorR = 0.0,
                barColorG = 1.0,
                barColorB = 0.0,
                barColorA = 1.0
            }
        }
    },
    
    Cue = {
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
            }
        },
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
                        powerFactor = 600.0,
                        moveBackwardFactor = 0.5,
                        rotateFactor = 0.3,
                        impulseTime = 0.5,
                        impulseFactor = 0.05
                    }
                }
            }
        }
    },
    BallPlayer = {
        components = {
            Transform = {
                positionX = 0.0,
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
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
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
            WhiteBallComponent = {

            }
        }
    },

    MovableWall1 = {
        components = {
            Transform = {
                positionX = 12.2,
                positionY = 8.2,
                positionZ = -2.5,
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
                destX = 12.2,
                destZ = 8.0,
                --destX = 8.0,
                --destZ = -2.0
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
                colliderScaleX = 15.0,
                colliderScaleY = 5.0,
                colliderScaleZ = 2.65,
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
                        positionX = -290.0,
                        positionY = 6.0,
                        positionZ = 0.0,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX = 1.0,
                        colliderScaleY = 4.0,
                        colliderScaleZ = 17.0,
                        isTrigger = false,
                        movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass = 0.0,
                        friction = 0.5,
                        damping = 0.0,
                        bounciness = 1.0
                    }
                }
            },
            Wall2 = {
                components = {
                    Transform = {
                        positionX = 290.0,
                        positionY = 6.0,
                        positionZ = 0.0,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX = 1.0,
                        colliderScaleY = 4.0,
                        colliderScaleZ = 17.0,
                        isTrigger = false,
                        movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass = 0.0,
                        friction = 1.0,
                        damping = 0.0,
                        bounciness = 1.0
                    }
                }
            },
            Wall3 = {
                components = {
                    Transform = {
                        positionX = 0.0,
                        positionY = 160.0,
                        positionZ = -16.5,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX = 30.0,
                        colliderScaleY = 4.0,
                        colliderScaleZ = 1.0,
                        isTrigger = false,
                        movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass = 0.0,
                        friction = 1.0,
                        damping = 0.0,
                        bounciness = 1.0
                    }
                }
            },
            Wall4 = {
                components = {
                    Transform = {
                        positionX = 0.0,
                        positionY = -160.0,
                        positionZ = 16.5,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX = 30.0,
                        colliderScaleY = 4.0,
                        colliderScaleZ = 1.0,
                        isTrigger = false,
                        movementType = 2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass = 0.0,
                        friction = 1.0,
                        damping = 0.0,
                        bounciness = 1.0
                    }
                }
            }
        }
    },
    BallYellow = {
        components = {
            Transform = {
                positionX = 5.5,
                positionY = 8.2,
                positionZ = 5.4,
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
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "yellow"
            }
        }
    },
    BallBlue = {
        components = {
            Transform = {
                positionX = -22.5,
                positionY = 8.2,
                positionZ = -8.7,
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
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "blue"
            }
        }
    },
    BallRed = {
        components = {
            Transform = {
                positionX = -6.5,
                positionY = 8.2,
                positionZ = 9.5,
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
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
                isTrigger = false, 
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "red"
            }
        }
    },
    BallPurple = {
        components = {
            Transform = {
                positionX = -1.1,
                positionY = 8.2,
                positionZ = -5.8,
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
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "purple"
            }
        }
    },
    BallOrange = {
        components = {
            Transform = {
                positionX = -19.1,
                positionY = 8.2,
                positionZ = 3.3,
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
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "orange"
            }
        }
    },
    BallGreen = {
        components = {
            Transform = {
                positionX = 19.4,
                positionY = 8.2,
                positionZ = -1.0,
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
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 2.0,
                friction = 0.5,
                damping = 0.4,
                bounciness = 1.0
            },
            ColoredBall = {
                ballId = "green"
            }
        }
    },
    BallBlack = {
        components = {
            Transform = {
                positionX = 6.6,
                positionY = 8.2,
                positionZ = -11.4,
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
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
                isTrigger = false,
                movementType = 0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass = 3.0,
                friction = 2.0,
                damping = 0.4,
                bounciness = 0.5
            },
            ColoredBall = {
                ballId = "black"
            }
        }
    },
    Heart = {
        components = {
            Transform = {
                positionX = -12.0,
                positionY = 8.2,
                positionZ = -5.8,
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
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
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
                positionX = -12.0,
                positionY = 8.2,
                positionZ = 5.0,
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
    Accelerator1 = {
        components = {
            Transform = {
                positionX = 0.0,
                positionY = 7.0,
                positionZ = 7.6,
                scaleX = 9.0,
                scaleY = 9.0,
                scaleZ = 9.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            -- MeshRenderer = {
            --     meshName = "models/cube.mesh",
            --     materialName= "grey"
            -- },
            RigidBody = {    
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
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
                positionZ = -15.0,
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
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
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
            }
        }
    },
    HoleOrange = {
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
                ballId = "orange"
            },
            RigidBody = {
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
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
            }
        }
    },
    HoleGreen = {
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
                ballId = "green"
            },
            RigidBody = {
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
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
            }
        }
    },
    HoleRed = {
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
                ballId = "red"
            },
            RigidBody = {
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
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
            }
        }
    },
    HoleBlue = {
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
                ballId = "blue"
            },
            RigidBody = {
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
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
            }
        }
    },
    HolePurple = {
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
                ballId = "purple"
            },
            RigidBody = {
                colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX = 1.0,
                colliderScaleY = 1.0,
                colliderScaleZ = 1.0,
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
    -- },
    -- Bomb = {
    --     components = {
    --         Transform = {
    --             positionX = -3.8,
    --             positionY = 8.2,
    --             positionZ = 0.0,
    --             scaleX = 1.2,
    --             scaleY = 1.2,
    --             scaleZ = 1.2,
    --             rotationX = 0.0,
    --             rotationY = 0.0,
    --             rotationZ = 0.0
    --         }, 
    --         MeshRenderer = {
    --             meshName = "models/Bomb/Bomb.mesh",
    --             --materialName = "white"
    --         },
    --         RigidBody = {    
    --             colShape = 0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
    --             colliderScaleX = 1.0,
    --             colliderScaleY = 1.0,
    --             colliderScaleZ = 1.5,
    --             isTrigger = true,
    --             movementType = 1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
    --             mass = 2.0,
    --             friction = 1.0,
    --             damping = 0.4,
    --             bounciness = 0.0
    --         },
    --         ExplosiveComponent = { 
    --             force = 50.0
    --         }
    --     }
    }
}