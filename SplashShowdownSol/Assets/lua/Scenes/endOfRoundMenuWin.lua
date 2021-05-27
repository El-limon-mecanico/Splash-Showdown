endOfRoundMenuWin = {
    entities = {"Cam","fondo", "playBoton", "salirBoton", "titulo", "sonidoBoton"}
}

fondo = {
    Active = true,

    Components = {"Image"},

    Image = {
        Active = true,
        Background = false,
        Border = false,
        Style= "WindowsLook/StaticImage",
        Name = "FondoMenuEntreRondas",
        Image = "fondoMenuEntreRondas.png",
        Position = {0,0},
        Size = {1440,810},
        TargetResolution = {1440,810}
    }
}

sonidoBoton = {
    Active = true,

    Components = {"AudioSource"},

    AudioSource = {
        Source = "bong_001.ogg",
        Volume = 1,
        Loops = 0,
        Enable = true
    }
}

playBoton = {
    Active = true,

    Components = {"PlayButton", "Button"},

    PlayButton = {},

    Button = {
        Active = true,
        Enable = true,
        Style = "WindowsLook/Button",
        Name  = "ButtonPlay",
        Text  = "New game",
        TLColor = "FF000000",
        TRColor = "FF000000",
        BLColor = "FF000000",
        BRColor = "FF000000",
        Position = {0.465,0.5},
        Size = {100,50},
        CallBackFunction = "Play",
        TargetResolution = {1440,810}
    }
}


salirBoton = {
    Active = true,

    Components = {"BackButton", "Button"},

    BackButton = {},

    Button = {
        Active = true,
        Enable = true,
        Style = "WindowsLook/Button",
        Name  = "ButtonMainMenu",
        Text  = "MainMenu",
        TLColor = "FF000000",
        TRColor = "FF000000",
        BLColor = "FF000000",
        BRColor = "FF000000",
        Position = {0.465,0.65},
        Size = {100,50},
        CallBackFunction = "Back",
        TargetResolution = {1440,810}
    }
}


titulo = {
    Active = true,

    Components = {"Image"},

    Image = {
        Active = true,
        Background = false,
        Border = false,
        Style= "WindowsLook/StaticImage",
        Name = "YouWin",
        Image = "YouWin.png",
        Position = {0.34,0.10},
        Size = {623,154},
        TargetResolution = {1920,1080}
    }
}

Cam = {
    Active = true,

    Components = {"Transform", "Camera"},

    Transform = {
        Position = {10,10,10},
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