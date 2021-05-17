scene1 = {
    entities = {"defaultCamera","plano", "tanque1", "tanque2", "sceneLight"}
}

plano = {
    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {0,0,0},
        Scale = {13,10,1},
        Rotation = {-90,0,0}
    },

    MeshRenderer = {
        Mesh = "Plane"
    },

    Rigidbody = {
        Type = "Cube",
        Mass = 1,
        Trigger = false,
        Static = true,
        PositionConstrains = {0,0,0},
        RotationConstrains = {0,0,0}
    }  
}

tanque1 = {
    Components = {"Transform", "MeshRenderer", "Rigidbody", "PlayerMovement"},

    Transform = {
        Position = {11,1.1,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Cube",
        Material = "Tanques/Rojo"
    },

    Rigidbody = {
        Type = "Cube",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0,1,0},
        RotationConstrains = {0,0,0}
    },

    PlayerMovement = {
        MovSpeed = 100,
        RotSpeed = 25,
        RotKeyLeft = 20,
        RotKeyRight = 8
    }
}

tanque2 = {
    Components = {"Transform", "MeshRenderer", "Rigidbody"},

    Transform = {
        Position = {-11,1.1,0},
        Scale = {1,1,1},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Cube",
        Material = "Tanques/Verde"
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