Partida = {
    entities = {"defaultCamera", "entidad1","entidad2","entidad3","entidad4","entidad5", "tanque1", "tanque2", "sceneLight"}
}

plano = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,0,0},
        Scale = {13,10,1},
        Rotation = {-90,0,0}
    },

    MeshRenderer = {
        Mesh = "Plane",
    },

    Rigidbody = {
        Type = "Cube",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },
}

tanque1 = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody", "PlayerMovement", "Shoot"},

    Transform = {
        Position = {11,2,0},
        Scale = {50,50,50},
        Rotation = {-90,0,0}
    },

    MeshRenderer = {
        Mesh = "PatoCuerpo.mesh"
    },

    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0,0,0},
        RotationConstrains = {1,0,1}
    },

    PlayerMovement = {
        MovSpeed = 15,
        RotSpeed = 2.5,
        MovSpeedLimit = 10,
        RotSpeedLimit = 10,
        TurretSpeed = 55,
        TurretLeftKey = 20,
        TurretRightKey = 8,
        ShootKey = 21
    },

    Shoot = {
        BulletPrefabRoute = "Entities/BulletExample.lua"
    },
    
    Children = {
        entities = {"cabeza1"},

        cabeza1 = {
            Active = true,

            Components = {"Transform", "MeshRenderer"},

            Transform = {
                Position = {11,2.4,0.19},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
        
            MeshRenderer = {
                Mesh = "PatoCabeza.mesh"
            }
        }
    }
}

tanque2 = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {-11,2,0},
        Scale = {50,50,50},
        Rotation = {-90,0,0}
    },

    MeshRenderer = {
        Mesh = "PatoCuerpoMorado.mesh"
    },

    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0,0,0},
        RotationConstrains = {1,0,1}
    },

    Children = {
        entities = {"cabeza2"},

        cabeza2 = {
            Active = true,

            Components = {"Transform", "MeshRenderer"},

            Transform = {
                Position = {-11,2.4,0.19},
                Scale = {1,1,1},
                Rotation = {0,0,0}
            },
        
            MeshRenderer = {
                Mesh = "PatoCabezaMorado.mesh"
            }
        }
    }
}

defaultCamera = {
    Components = {"Transform", "Camera"},

    Transform = {
        Position = {0,24,14},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MainCam",
        Background = {0.6,0.8,1},
        LookAt = {0,0,0},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    }
}
sceneLight = {
    Active = true,

    Components = {"Transform", "Light"},

    Transform = {
        Position = {-5,17,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        LightType = 1,
        DiffuseColor = {1,1,1},
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 100,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}

entidad1 = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,0,0},
        Scale = {50,50,50},
        Rotation = {0,90,90}
    },

    MeshRenderer = {
        Mesh = "mapa.mesh",
    },

    Rigidbody = {
        Type = "Cube",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },
}

entidad2 = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,0,0},
        Scale = {50,50,50},
        Rotation = {0,90,90}
    },

    MeshRenderer = {
        Mesh = "arbol.mesh",
    },

    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },
}


entidad3 = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,0,0},
        Scale = {50,50,50},
        Rotation = {0,90,90}
    },

    MeshRenderer = {
        Mesh = "diagonales.mesh",
    },

    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },
}

entidad4 = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,0,0},
        Scale = {50,50,50},
        Rotation = {0,90,90}
    },

    MeshRenderer = {
        Mesh = "cruz.mesh",
    },

    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },
}

entidad5 = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,0,0},
        Scale = {50,50,50},
        Rotation = {0,90,90}
    },

    MeshRenderer = {
        Mesh = "bases.mesh",
    },

    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    },
}