Partida1Rebote = {
    entities = {
        "defaultCamera",
        "suelo",
        "diagonal1",
        "diagonal2",
        "diagonal3",
        "diagonal4",
        "base1",
        "base2",
        "cubo1",
        "cubo2",
        "cubo3",
        "cubo4",
        "arbol",
        "pared1",
        "pared2",
        "pared3",
        "pared4",
        "tanque1",
        "tanque2",
        "sceneLight",
        "pausa"
    }
}

suelo = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0, -0.25, 0},
        Scale = {50, 50, 50},
        Rotation = {0, 90, 90}
    },

    MeshRenderer = {Mesh = "Suelo.mesh"},

    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

tanque1 = {
    Active = true,
    Tag = "player",
    Components = {
        "Transform", "MeshRenderer", "Rigidbody", "PlayerController", "Shoot", "Health", "AudioSource"
    },

    Transform = {
        Position = {11, 0.75, 0},
        Scale = {50, 50, 50},
        Rotation = {-90, 0, 0}
    },

    MeshRenderer = {Mesh = "PatoCuerpo.mesh"},

    Rigidbody = {
        Type = "Box",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {1, 0, 1}
    },
    PlayerController = {
        MovSpeed = 15,
        RotSpeed = 2.5,
        MovSpeedLimit = 10,
        RotSpeedLimit = 10,
        TurretSpeed = 100,
        TurretLeftKey = 20,
        TurretRightKey = 8,
        ShootKey = 21
    },

    Shoot = {
        BulletPrefabRoute = "Entities/BulletRicochet.lua",
        Speed = 10.0
    },
    Children = {
        entities = {"cabeza1"},
        cabeza1 = {
            Active = true,
            Components = {"Transform", "MeshRenderer", "AudioSource"},

            Transform = {
                Position = {11, 2.4, 0.19},
                Scale = {1, 1, 1},
                Rotation = {0, 0, 0}
            },

            MeshRenderer = {Mesh = "PatoCabeza.mesh"},

            AudioSource = {
                Source = "duck.wav",
                Volume = 0.4,
                Loops = 0,
                Enabled = true
            }
        }
    },

    Health = {HitPoints = 50},

    AudioSource = {
        Source = "oof.wav",
        Volume = 1,
        Loops = 0,
        Enabled = true
    }
}

tanque2 = {
    Active = true,
    Tag = "enemy",
    Components = {"Transform", "MeshRenderer", "IATank", "Shoot", "Rigidbody", "Health", "AudioSource"},

    Transform = {
        Position = {-11, 0.75, 0},
        Scale = {50, 50, 50},
        Rotation = {-90, 0, 0}
    },

    MeshRenderer = {Mesh = "PatoCuerpoMorado.mesh"},

    Rigidbody = {
        Type = "Box",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {1, 0, 1}
    },
    IATank = {
        MovSpeed = 15,
        RotSpeed = 2.5,
        MovSpeedLimit = 10,
        RotSpeedLimit = 10,
        TurretSpeed = 55,
        TargetName = "tanque1",
        Frequency = 200
    },
    Shoot = {
        BulletPrefabRoute = "Entities/BulletExplode.lua",
        Speed = 10.0
    },
    Health = {HitPoints = 50},

    Children = {
        entities = {"cabeza2"},

        cabeza2 = {
            Active = true,

            Components = {"Transform", "MeshRenderer", "AudioSource"},

            Transform = {
                Position = {-11, 1.15, 0.19},
                Scale = {1, 1, 1},
                Rotation = {0, 0, 0}
            },

            MeshRenderer = {Mesh = "PatoCabezaMorado.mesh"},
            
            AudioSource = {
                Source = "duck.wav",
                Volume = 0.4,
                Loops = 0,
                Enabled = true
            }
        }
    },

    AudioSource = {
        Source = "oof.wav",
        Volume = 1,
        Loops = 0,
        Enabled = true
    }
}

defaultCamera = {
    Components = {"Transform", "Camera"},
    Transform = {
        Position = {0, 17, 17},
        Scale = {1, 1, 1},
        Rotation = {0, 0, 0}
    },
    Camera = {
        Name = "MainCam",
        Background = {0.6, 0.8, 1},
        LookAt = {0, 0, 0},
        Width = 1,
        Height = 1,
        xProp = 16,
        yProp = 9,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective",
        zOrder = 0
    }
}

sceneLight = {
    Active = true,
    Components = {"Transform", "Light"},
    Transform = {
        Position = {-5, 17, 10},
        Scale = {1, 1, 1},
        Rotation = {0, 0, 0}
    },
    Light = {
        LightType = 1,
        DiffuseColor = {1, 1, 1},
        SpecularColor = {1, 1, 1},
        Direction = {0, 0, 0},
        Distance = 100,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}

arbol = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {0, 0, 0},
        Scale = {50, 50, 50},
        Rotation = {0, 90, 90}
    },
    MeshRenderer = {
        Mesh = "arbol.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

diagonal1 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {4, 0, 4},
        Scale = {50, 50, 50},
        Rotation = {-90, -45, 0}
    },
    MeshRenderer = {
        Mesh = "Diagonal.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

diagonal2 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {-4, 0, -4},
        Scale = {50, 50, 50},
        Rotation = {-90, -45, 0}
    },
    MeshRenderer = {
        Mesh = "Diagonal.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

diagonal3 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {-4, 0, 4},
        Scale = {50, 50, 50},
        Rotation = {-90, 45, 0}
    },
    MeshRenderer = {
        Mesh = "Diagonal.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

diagonal4 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {4, 0, -4},
        Scale = {50, 50, 50},
        Rotation = {-90, 45, 0}
    },
    MeshRenderer = {
        Mesh = "Diagonal.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

base1 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {9, 0, 0},
        Scale = {50, 50, 50},
        Rotation = {-90, 0, 0}
    },
    MeshRenderer = {
        Mesh = "Base.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

base2 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {-9, 0, 0},
        Scale = {50, 50, 50},
        Rotation = {-90, 0, 0}
    },
    MeshRenderer = {
        Mesh = "Base.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

cubo1 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {5, 0, 0},
        Scale = {50, 50, 50},
        Rotation = {-90, 0, 0}
    },
    MeshRenderer = {
        Mesh = "Cubo.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

cubo2 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {-5, 0, 0},
        Scale = {50, 50, 50},
        Rotation = {-90, 0, 0}
    },
    MeshRenderer = {
        Mesh = "Cubo.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

cubo3 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {0, 0, 5},
        Scale = {50, 50, 50},
        Rotation = {-90, 0, 0}
    },
    MeshRenderer = {
        Mesh = "Cubo.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

cubo4 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {0, 0, -5},
        Scale = {50, 50, 50},
        Rotation = {-90, 0, 0}
    },
    MeshRenderer = {
        Mesh = "Cubo.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

pared1 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {0, 0, 7.5},
        Scale = {50, 48.25, 50},
        Rotation = {0, 90, 90}
    },
    MeshRenderer = {
        Mesh = "ParedLarga.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

pared2 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {0, 0, -7.5},
        Scale = {50, 50, 50},
        Rotation = {0, 90, 90}
    },
    MeshRenderer = {
        Mesh = "ParedLarga.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

pared3 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {12.5, 0, 0},
        Scale = {53, 50, 50},
        Rotation = {0, 90, 90}
    },
    MeshRenderer = {
        Mesh = "ParedCorta.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

pared4 = {
    Active = true,
    Components = {"Transform", "MeshRenderer", "Rigidbody"},
    Transform = {
        Position = {-12.5, 0, 0},
        Scale = {53, 50, 50},
        Rotation = {0, 90, 90}
    },
    MeshRenderer = {
        Mesh = "ParedCorta.mesh"
    },
    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0, 0, 0},
        RotationConstrains = {0, 0, 0}
    }
}

pausa = {
    Active = true,
    Components = {"Pause"},
    Pause = {
        SceneRoute = "scenes/pausa.lua",
        SceneName = "pausa"
    }
}
