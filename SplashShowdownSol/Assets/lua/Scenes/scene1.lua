scene1 = {
    entities = {"defaultCamera","entidad1", "entidad2", "entidad3", "entidad4", "entidad5", "sceneLight"}
}

entidad1 = {
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
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true
    },
}

entidad2 = {
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
        Static = true
    },
}


entidad3 = {
    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {-5,1,4},
        Scale = {1,1,1},
        Rotation = {0,90,90}
    },

    MeshRenderer = {
        Mesh = "Cube",
    },

    Rigidbody = {
        Type = "Hull",
        Mass = 1,
        Trigger = false,
        Static = true
    },
}

entidad4 = {
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
        Static = true
    },
}

entidad5 = {
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
        Static = true
    },
}


defaultCamera = {
    Components = {"Transform", "Camera", "Prueba"},

    Transform = {
        Position = {0,20,20},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Camera = {
        Name = "MainCam",
        Background = {0.12,0.63,0.85},
        LookAt = {0,0,0},
        Width = 0,
        Height = 0,
        NearClipDistance = 1,
        FarClipDistance = 100000,
        ProjectionType = "Perspective"
    },

    Prueba = {
        valor1 = 1,
        valor2 = 3,
        valor3 = "Quack"
    }
}

sceneLight = {
    Components = {"Transform", "Light"},

    Transform = {
        Position = {-10,10,10},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    Light = {
        LightType = 0,
        DiffuseColor = {1,1,1},
        SpecularColor = {1,1,1},
        Direction = {0,0,0},
        Distance = 100,
        InnerAngle = 30,
        OuterAngle = 90,
        isOn = true
    }
}