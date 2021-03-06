scene1 = {
    entities = {"defaultCamera","entidad1", "entidad2", "entidad3", "entidad4", "entidad5", "sceneLight"}
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


defaultCamera = {
    Active = true,
    
    Components = {"Transform", "Camera"},

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
}

sceneLight = {
    Active = true,
    
    Components = {"Transform", "Light"},

    Transform = {
        Position = {-10,10,10},
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

UI = {
    Components = {"Text1", "Image1", "Button1"},

    Text1 = {
        Type = "Text",
        Style= "TaharezLook/StaticText",
        Name = "Texto",
        Text = " Esto no es un boton, es solo texto, pero desde lua",
        Position = {0.5,0.05},
        Size = {405,50}
    },

    Image1 = {
        Type = "Image",
        Style= "WindowsLook/StaticImage",
        Name = "Cuchao",
        Image = "cuchao.png",
        Position = {0.1,0.6},
        Size = {300,200}
    },

    Button1 = {
        Type = "Button",
        Style= "WindowsLook/Button",
        Name = "Button",
        Text = "Betis",
        Position = {0.5,0.5},
        Size = {100,100},
        CallBackFunction = "botonPresionado"
    }

}