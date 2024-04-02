scene = {
    {
        components = {
            Transform = {
                positionX = 20.0,
                positionY = 0.0,
                positionZ = 20.0,
                scaleX = 1.0,
                scaleY = 1.0,
                scaleZ = 1.0,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
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
                positionX = WINDOW_WIDTH / 2 - 25,
                positionY = WINDOW_HEIGHT / 2 - 60,
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
                text = "xxxx",
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
    --            meshName = "Sinbad.mesh",
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
   CueContainer={
    components={
        Transform = {
            positionX = 0.0,
            positionY = 0.0,
            positionZ =13.0,--offset
            scaleX = 10.0,
            scaleY = 10.0,
            scaleZ = 10.0,
            rotationX = 0.0,
            rotationY = 0.0,
            rotationZ = 0.0
        }, 
        MeshRenderer = {
            meshName = "CueStick/CueStick.mesh",
        },
        -- RigidBody = {    
        --     colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
        --     colliderScaleX=0.3,
        --     colliderScaleY=0.3,
        --     colliderScaleZ=5.0,
        --     isTrigger=false,
        --     movementType=0, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
        --     mass=10.0,
        --     friction=1.0,
        --     damping=0.4,
        --     bounciness=0.0
        -- },
        CueController = {    
            powerFactor=3.0,
            moveBackwardFactor=0.5,
            rotateFactor=0.5,
            ballDistanceOffsetX=0.0,
            ballDistanceOffsetY=0.0,
            ballDistanceOffsetZ=2.0,
            impulseFactor=0.05
        }
    }
},
    BallPlayer={
        components={
            Transform = {
                positionX = 0.0,
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
                meshName = "Ball1/Ball1.mesh",
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
    --     CueContainer={
    --         components={
    --             Transform = {
    --                 positionX = 0.0,
    --                 positionY = 0.0,
    --                 positionZ = 0.0,--offset
    --                 scaleX = 10.0,
    --                 scaleY = 10.0,
    --                 scaleZ = 10.0,
    --                 rotationX = 0.0,
    --                 rotationY = 30.0,
    --                 rotationZ = 0.0
    --             }, 
    --             MeshRenderer = {
    --                 meshName = "CueStick/CueStick.mesh",
    --             },
    --             RigidBody = {    
    --                 colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
    --                 colliderScaleX=0.3,
    --                 colliderScaleY=0.3,
    --                 colliderScaleZ=5.0,
    --                 isTrigger=false,
    --                 movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
    --                 mass=10.0,
    --                 friction=1.0,
    --                 damping=0.4,
    --                 bounciness=0.0
    --             },
    --             CueController = {    
    --                 powerFactor=3.0,
    --                 moveFactor=1.0
    --             }
    --         }
    --     }
    --     }
    -- },
    MovableWall1={
        components={
            Transform = {
                positionX = 0.0,
                positionY = 0.0,
                positionZ = -2.0,
                scaleX = 2.6,
                scaleY = 0.52,
                scaleZ = 5.2,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            MeshRenderer = {
                meshName = "meshes/cube2.mesh",
                materialName= "grey"
            },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=3.0,
                colliderScaleY=0.5,
                colliderScaleZ=5.0,
                isTrigger=false,
                movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=0.0,
                friction=1.0,
                damping=0.0,
                bounciness=1.0
            },
            MovableWall = {    
                speed=0.02,
                destX=8.0,
                destZ=-2.0
              
            }
        }
    },
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
            --     meshName = "meshes/cube.mesh",
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
                positionX = 0.0,
                positionY = -4.0,
                positionZ = 0.0,
                scaleX = 5.2,
                scaleY = 1.04,
                scaleZ = 10.4,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            },
            MeshRenderer = {
                meshName = "meshes/cube2.mesh",
                materialName= "green"
            },
            RigidBody = {    
                colShape=0, --0 BOX, 1 SPHERE, 2 PLANE, 3 CAPSULE
                colliderScaleX=6.0,
                colliderScaleY=1.0,
                colliderScaleZ=10.0,
                isTrigger=false,
                movementType=2, --0 DYNAMIC , 1 STATIC, 2 KINEMATIC
                mass=0.0,
                friction=1.0,
                damping=0.0,
                bounciness=1.0
            }
        }
    },
    Ball1={
        components={
            Transform = {
                positionX = 0.0,
                positionY = 5.0,
                positionZ = 6.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "Ball1/Ball1.mesh"
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
    Ball2={
        components={
            Transform = {
                positionX = 10.0,
                positionY = 10.0,
                positionZ = 10.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "Ball2/Ball2.mesh"
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
    Ball3={
        components={
            Transform = {
                positionX = 6.0,
                positionY = 0.0,
                positionZ = 10.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "Ball3/Ball3.mesh"
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
    Ball4={
        components={
            Transform = {
                positionX = 6.0,
                positionY = 5.0,
                positionZ = 10.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "Ball4/Ball4.mesh"
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
    Ball5={
        components={
            Transform = {
                positionX = 6.0,
                positionY = 2.0,
                positionZ = 5.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "Ball5/Ball5.mesh"
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
    Ball6={
        components={
            Transform = {
                positionX = 3.0,
                positionY = 3.0,
                positionZ = 3.0,
                scaleX = 0.8,
                scaleY = 0.8,
                scaleZ = 0.8,
                rotationX = 0.0,
                rotationY = 0.0,
                rotationZ = 0.0
            }, 
            MeshRenderer = {
                meshName = "Ball6/Ball6.mesh"
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
                meshName = "meshes/heart.mesh",
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
    Hole1 = {
        components = {
            MeshRenderer = {
                meshName = "Sinbad.mesh"
            },
            ColoredHole = {
                ballName = "Ball1"
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