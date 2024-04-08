scene = {
    {
        components = {
            -- Transform = {
            --     positionX = 20.0,
            --     positionY = 0.0,
            --     positionZ = 20.0,
            --     scaleX = 1.0,
            --     scaleY = 1.0,
            --     scaleZ = 1.0,
            --     rotationX = 0.0,
            --     rotationY = 0.0,
            --     rotationZ = 0.0
            -- },
            Transform = {
                positionX = 0.0,
                positionY = 30.0,
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
            }
        }
    },
    TimerText={
        components = {
            Transform = {
                positionX = WINDOW_WIDTH / 2,
                positionY = 10.0,
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
--    CueContainer={
--     components={
--         Transform = {
--             positionX = 0.0,
--             positionY = -4.0,
--             positionZ =6.0,--offset
--             scaleX = 10.0,
--             scaleY = 10.0,
--             scaleZ = 10.0,
--             rotationX = 0.0,
--             rotationY = 0.0,
--             rotationZ = 0.0
--         }, 
--         MeshRenderer = {
--             meshName = "models/CueStick/CueStick.mesh",
--         },
--         CueController = {    
--             powerFactor=3.0,
--             moveBackwardFactor=0.5,
--             rotateFactor=0.5,
--             impulseTime=0.5,
--             impulseFactor=0.05
--         }
--     }
-- },
    BallPlayer={
        components={
            Transform = {
                positionX = 4.0,
                positionY = -2.0,
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
                colliderScaleX=1.0,
                colliderScaleY=1.0,
                colliderScaleZ=1.0,
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
    -- MovableWall1={
    --     components={
    --         Transform = {
    --             positionX = 0.0,
    --             positionY = 0.0,
    --             positionZ = -2.0,
    --             scaleX = 2.6,
    --             scaleY = 0.52,
    --             scaleZ = 5.2,
    --             rotationX = 0.0,
    --             rotationY = 0.0,
    --             rotationZ = 0.0
    --         },
    --         MeshRenderer = {
    --             meshName = "models/cube2.mesh",
    --             materialName= "grey"
    --         },
    --         RigidBody = {    
    --             colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
    --             colliderScaleX=3.0,
    --             colliderScaleY=0.5,
    --             colliderScaleZ=5.0,
    --             isTrigger=false,
    --             movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
    --             mass=0.0,
    --             friction=1.0,
    --             damping=0.0,
    --             bounciness=1.0
    --         },
    --         MovableWall = {    
    --             speed=0.02,
    --             destX=8.0,
    --             destZ=-2.0
              
    --         }
    --     }
    -- },
    Accelerator1={
        components={
            Transform = {
                positionX = 0.0,
                positionY = -2.8,
                positionZ = 0.0,
                scaleX = 5.0,
                scaleY = 5.0,
                scaleZ = 5.0,
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
                speedFactor=1.5,
            },
            PlaneComponent = {  
                planeName="Accelerator1",  
                materialName="lighting",
                upX=0.0,
                upY=0.0,
                upZ=1.0,
                rkNormalX=0.0,
                rkNormalY=1.0,
                rkNormalZ=0.0,
                initRotationX=0.0,
                initRotationY=0.0,
                initRotationZ=0.0
                -- width=200.0,
                -- height=200.0
            }
        }
    },
    Ground={
        components={
            Transform = {
                positionX = 5.0,
                positionY = -9.0,
                positionZ = 5.0,
                scaleX = 0.05,
                scaleY = 0.05,
                scaleZ = 0.05,
                rotationX = -90.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            MeshRenderer = {
                meshName = "models/Table2/Table.mesh"
            },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=19.0,
                colliderScaleY=7.5,
                colliderScaleZ=3.5,
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
                        positionX = -14.5,
                        positionY = 4.0,
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
                        colliderScaleY=1.0,
                        colliderScaleZ=8.0,
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
                        positionX = 14.5,
                        positionY = 4.0,
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
                        colliderScaleY=1.0,
                        colliderScaleZ=8.0,
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
                        positionY = 4.0,
                        positionZ = -8.5,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX=16.0,
                        colliderScaleY=1.0,
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
                        positionY = 4.0,
                        positionZ = 8.5,
                        scaleX = 0.05,
                        scaleY = 0.05,
                        scaleZ = 0.05,
                        rotationX = -90.0,
                        rotationY = 0.0,
                        rotationZ = 0.0
                    },
                    RigidBody = {    
                        colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                        colliderScaleX=16.0,
                        colliderScaleY=1.0,
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
                positionX = 0.0,
                positionY = 5.0,
                positionZ = 6.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = -90.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball1/Ball1.mesh"
            },
            RigidBody = {    
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=1.0,
                colliderScaleY=1.0,
                colliderScaleZ=1.0,
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
                positionX = 10.0,
                positionY = 10.0,
                positionZ = 10.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = -90.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball2/Ball2.mesh"
            },
            RigidBody = {    
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=1.0,
                colliderScaleY=1.0,
                colliderScaleZ=1.0,
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
                positionX = 6.0,
                positionY = 0.0,
                positionZ = 10.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = -90.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball3/Ball3.mesh"
            },
            RigidBody = {    
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=1.0,
                colliderScaleY=1.0,
                colliderScaleZ=1.0,
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
                positionX = 6.0,
                positionY = 5.0,
                positionZ = 10.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = -90.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball4/Ball4.mesh"
            },
            RigidBody = {    
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=1.0,
                colliderScaleY=1.0,
                colliderScaleZ=1.0,
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
                positionX = 6.0,
                positionY = 2.0,
                positionZ = 5.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = -90.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball5/Ball5.mesh"
            },
            RigidBody = {    
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=1.0,
                colliderScaleY=1.0,
                colliderScaleZ=1.0,
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
                positionX = 3.0,
                positionY = 3.0,
                positionZ = 3.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = -90.0,
                rotationZ = 90.0
            }, 
            MeshRenderer = {
                meshName = "models/Ball6/Ball6.mesh"
            },
            RigidBody = {    
                colShape=1, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=1.0,
                colliderScaleY=1.0,
                colliderScaleZ=1.0,
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
    Heart={
        components={
            Transform = {
                positionX = 10.0,
                positionY = 0.0,
                positionZ = 10.0,
                scaleX = 0.6,
                scaleY = 0.6,
                scaleZ = 0.6,
                rotationX = -90.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "models/heart/heart.mesh",
                materialName = "heart"
            },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=0.6,
                colliderScaleY=0.6,
                colliderScaleZ=0.6,
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
    HoleYellow = {
        components = {
            -- MeshRenderer = {
            --     meshName = "models/Sinbad/Sinbad.mesh"
            -- },
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
            },
            Animator = {
                playbackSpeed=0.001
            }
        }
    }
}