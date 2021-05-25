pausa = {
    entities = {"Cam","fondo", "playBoton", "salirBoton", "titulo"}
}

fondo = {
    Active = true,

    Components = {"Image"},

    Image = {
        Active = true,
        Background = false,
        Border = false,
        Style= "WindowsLook/StaticImage",
        Name = "FondoPausa",
        Image = "fondoPausa.png",
        Position = {0,0},
        Size = {1440,810}
    }
}

playBoton = {
    Active = true,

    Components = {"ResumeButton", "Button"},

    PlayButton = {},

    Button = {
        Active = true,
        Enable = true,
        Style = "WindowsLook/Button",
        Name  = "ButtonPlay",
        Text  = "Resume",
        TLColor = "FF000000",
        TRColor = "FF000000",
        BLColor = "FF000000",
        BRColor = "FF000000",
        Position = {0.465,0.5},
        Size = {100,50},
        CallBackFunction = "ResumeGame"
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
        Name  = "ButtonBack",
        Text  = "Exit",
        TLColor = "FF000000",
        TRColor = "FF000000",
        BLColor = "FF000000",
        BRColor = "FF000000",
        Position = {0.465,0.65},
        Size = {100,50},
        CallBackFunction = "Back"
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
        Name = "TituloPausa",
        Image = "tituloPausa.png",
        Position = {0.300,0.10},
        Size = {514,134}
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