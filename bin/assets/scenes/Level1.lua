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
                positionX = 0.0,
                positionY = 60.0,
                positionZ = 0.0,
                scaleX = 1.0,
                scaleY = 1.0,
                scaleZ = 1.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 90.0
            },
            CameraComponent = {
                zOrder = 0,
                bgColorR = 0.925,
                bgColorG = 0.698,
                bgColorB = 0.941,
                targetToLookX = 0.0,
                targetToLookY = 0.0,
                targetToLookZ = 0.0
            },
            GameManager = {
                initLife = 3,
                initTime = 9999.0
            },
            LightDirComp = {
                directionX = 0.0,
                directionY = -1.0,
                directionZ = -1.0,
                mainLight = true,
            }
        }
    },
    TimerText={
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2 - 25,
                positionY = 5.0,
                positionZ = 0.0,
                scaleX = 0.0,
                scaleY = 0.0,
                scaleZ = 0.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            Text = {
                name = "TimerText",
                text = "Timer",
                --textSize = 20.0,
                textFontName = "AGENCYB.TTF"
            }
        }
    },
    -- Sinbad={
    --    components={
    --        Transform = {
    --            positionX = 0.0,
    --            positionY = 0.0,
    --            positionZ = -8.0,
    --            scaleX = 0.6,
    --            scaleY = 0.6,
    --            scaleZ = 0.6,
    --            rotationX = 0.0,
    --            rotationY = 0.0,
    --            rotationZ = 0.0
    --        }, 
    --        MeshRenderer = {
    --            meshName = "models/Sinbad/Sinbad.mesh",
    --        },
    --        RigidBody = {    
    --            colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
    --            colliderScaleX=1.0,
    --            colliderScaleY=1.0,
    --            colliderScaleZ=1.0,
    --            isTrigger=false,
    --            movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
    --            mass=3.0,
    --            friction=2.0,
    --            damping=0.4,
    --            bounciness=0.5
    --        },
    --        Animator = {
    --            playbackSpeed=0.001
    --        }
    --    }
   -- },
   Cue={
    components={
        MeshRenderer = {
            meshName = "models/CueStick/CueStick.mesh",
        },
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
    children ={
        CueContainer={
            components={
                Transform = {
                    positionX = 0.0,
                    positionY = 0.0,
                    positionZ =-8.0,--offset
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
                    powerFactor=3.0,
                    moveBackwardFactor=0.5,
                    rotateFactor=0.3,
                    impulseTime=0.5,
                    impulseFactor=0.05
                }
            }
        }
    }
},
    BallPlayer={
        components={
            Transform = {
                positionX = 0.0,
                positionY = 8.2,
                positionZ = 0.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball1/Ball1.mesh",
                materialName="white"
            },
            RigidBody = {    
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.8,
                colliderScaleY=0.8,
                colliderScaleZ=0.8,
                isTrigger=false,
                movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            }
        }
            
           
    },
 --NO BORRAR
    -- Cue={
    --     components={
    --         Transform = {
    --             positionX = 0.0,
    --             positionY = 0.0,
    --             positionZ = 0.0,
    --             scaleX = 1.0,
    --             scaleY = 1.0,
    --             scaleZ = 1.0,
    --             rotationX = 0.0,
    --             rotationY = 0.0,
    --             rotationZ = 0.0
    --         } 
    --      },
    --     children ={
    --         CueContainer={
    --             components={
    --                 Transform = {
    --                     positionX = 0.0,
    --                     positionY = 0.0,
    --                     positionZ =5.0,--offset
    --                     scaleX = 10.0,
    --                     scaleY = 10.0,
    --                     scaleZ = 10.0,
    --                     rotationX = 0.0,
    --                     rotationY = 0.0,
    --                     rotationZ = 0.0
    --                 }, 
    --                 MeshRenderer = {
    --                     meshName = "models/CueStick/CueStick.mesh",
    --                 },
    --                 CueController = {    
    --                     powerFactor=3.0,
    --                     moveBackwardFactor=0.5,
    --                     rotateFactor=0.5,
    --                     impulseTime=0.5,
    --                     impulseFactor=0.05
    --                 }
    --             }
    --         }
    --     }
    -- },
    MovableWall1={
        components={
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
                materialName= "grey"
            },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=1.0,
                colliderScaleY=1.0,
                colliderScaleZ=4.0,
                isTrigger=false,
                movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=0.0,
                friction=1.0,
                damping=0.0,
                bounciness=1.0
            },
            MovableWall = {    
                speed=0.02,
                destX=12.2,
                destZ=8.0,
                --destX=8.0,
                --destZ=-2.0
              
            }
        }
    },
    -- Accelerator1={
    --     components={
    --         Transform = {
    --             positionX = 0.0,
    --             positionY = -2.8,
    --             positionZ = 0.0,
    --             scaleX = 5.0,
    --             scaleY = 5.0,
    --             scaleZ = 5.0,
    --             rotationX = 0.0,
    --             rotationY = 0.0,
    --             rotationZ = 0.0
    --         },
    --         -- MeshRenderer = {
    --         --     meshName = "models/cube.mesh",
    --         --     materialName= "grey"
    --         -- },
    --         RigidBody = {    
    --             colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
    --             colliderScaleX=2.0,
    --             colliderScaleY=2.0,
    --             colliderScaleZ=2.0,
    --             isTrigger=true,
    --             movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
    --             mass=0.0,
    --             friction=0.0,
    --             damping=0.0,
    --             bounciness=0.0
    --         },
    --         Accelerator = {    
    --             speedFactor=1.5,
    --         },
    --         PlaneComponent = {  
    --             materialName="lighting",
    --             upX=0.0,
    --             upY=0.0,
    --             upZ=1.0,
    --             rkNormalX=0.0,
    --             rkNormalY=1.0,
    --             rkNormalZ=0.0,
    --             -- width=200.0,
    --             -- height=200.0
    --         }
    --     }
    -- },
    Ground={
        components={
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
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=33.0,
                colliderScaleY=15.0,
                colliderScaleZ=7.0,
                isTrigger=false,
                movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=0.0,
                friction=1.0,
                damping=0.0,
                bounciness=1.0
            }
        },
        children = {
            Wall1 = {
                components = {
                    Transform = {
                        positionX = -30.0,
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
                        colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX=1.0,
                        colliderScaleY=3.0,
                        colliderScaleZ=17.0,
                        isTrigger=false,
                        movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass=0.0,
                        friction=1.0,
                        damping=0.0,
                        bounciness=1.0
                    }
                }
            },
            Wall2 = {
                components = {
                    Transform = {
                        positionX = 30.0,
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
                        colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX=1.0,
                        colliderScaleY=3.0,
                        colliderScaleZ=17.0,
                        isTrigger=false,
                        movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass=0.0,
                        friction=1.0,
                        damping=0.0,
                        bounciness=1.0
                    }
                }
            },
            Wall3 = {
                components = {
                    Transform = {
                        positionX = 0.0,
                        positionY = 6.0,
                        positionZ = -16.5,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX=30.0,
                        colliderScaleY=3.0,
                        colliderScaleZ=1.0,
                        isTrigger=false,
                        movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass=0.0,
                        friction=1.0,
                        damping=0.0,
                        bounciness=1.0
                    }
                }
            },
            Wall4 = {
                components = {
                    Transform = {
                        positionX = 0.0,
                        positionY = 6.0,
                        positionZ = 16.5,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX=30.0,
                        colliderScaleY=3.0,
                        colliderScaleZ=1.0,
                        isTrigger=false,
                        movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                        mass=0.0,
                        friction=1.0,
                        damping=0.0,
                        bounciness=1.0
                    }
                }
            }
        }
    },
    BallYellow={
        components={
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
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.7,
                colliderScaleY=0.7,
                colliderScaleZ=0.7,
                isTrigger=false,
                movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            },
            ColoredBall = {
                ballId = "yellow"
            }
        }
    },
    BallBlue={
        components={
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
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.7,
                colliderScaleY=0.7,
                colliderScaleZ=0.7,
                isTrigger=false,
                movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            },
            ColoredBall = {
                ballId = "blue"
            }
        }
    },
    BallRed={
        components={
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
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.7,
                colliderScaleY=0.7,
                colliderScaleZ=0.7,
                isTrigger=false,
                movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            },
            ColoredBall = {
                ballId = "red"
            }
        }
    },
    BallPurple={
        components={
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
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.7,
                colliderScaleY=0.7,
                colliderScaleZ=0.7,
                isTrigger=false,
                movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            },
            ColoredBall = {
                ballId = "purple"
            }
        }
    },
    BallOrange={
        components={
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
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.7,
                colliderScaleY=0.7,
                colliderScaleZ=0.7,
                isTrigger=false,
                movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            },
            ColoredBall = {
                ballId = "orange"
            }
        }
    },
    BallGreen={
        components={
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
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.7,
                colliderScaleY=0.7,
                colliderScaleZ=0.7,
                isTrigger=false,
                movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            },
            ColoredBall = {
                ballId = "green"
            }
        }
    },
    BallBlack={
        components={
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
                colliderScaleX=0.7,
                colliderScaleY=0.7,
                colliderScaleZ=0.7,
                isTrigger=false,
                movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            },
            ColoredBall = {
                ballId = "black"
            }
        }
    },
    Heart={
        components={
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
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.8,
                colliderScaleY=0.8,
                colliderScaleZ=0.8,
                isTrigger=true,
                movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            },
            HeartComponent = { }
        }
    },
    Accelerator1={
        components={
            Transform = {
                positionX = 0.0,
                positionY = 7.0,
                positionZ = 7.6,
                scaleX = 9.0,
                scaleY = 9.0,
                scaleZ =9.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            -- MeshRenderer = {
            --     meshName = "models/cube.mesh",
            --     materialName= "grey"
            -- },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=2.0,
                colliderScaleY=2.0,
                colliderScaleZ=2.0,
                isTrigger=true,
                movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=0.0,
                friction=0.0,
                damping=0.0,
                bounciness=0.0
            },
            Accelerator = {    
                speedFactor=5.0,
            },
            PlaneComponent = {  
                materialName="lighting",
                upX=0.0,
                upY=0.0,
                upZ=-1.0,
                rkNormalX=0.0,
                rkNormalY=1.0,
                rkNormalZ=0.0,
                width=3.0,
                height=3.0,
            }
        }
    },
    HoleYellow = {
        components = {
            -- MeshRenderer = {
            --     meshName = "models/Sinbad/Sinbad.mesh"
            -- },
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
                colliderScaleX=0.6,
                colliderScaleY=0.6,
                colliderScaleZ=0.6,
                isTrigger=true,
                movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
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
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.6,
                colliderScaleY=0.6,
                colliderScaleZ=0.6,
                isTrigger=true,
                movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
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
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.6,
                colliderScaleY=0.6,
                colliderScaleZ=0.6,
                isTrigger=true,
                movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
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
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.6,
                colliderScaleY=0.6,
                colliderScaleZ=0.6,
                isTrigger=true,
                movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
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
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.6,
                colliderScaleY=0.6,
                colliderScaleZ=0.6,
                isTrigger=true,
                movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            }
        }
    },
    HolePurple = {
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
                ballId = "purple"
            },
            RigidBody = {
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.6,
                colliderScaleY=0.6,
                colliderScaleZ=0.6,
                isTrigger=true,
                movementType=1, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=3.0,
                friction=2.0,
                damping=0.4,
                bounciness=0.5
            }
        }
    }
}