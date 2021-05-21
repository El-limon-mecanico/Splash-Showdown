weaponMenu = {
    entities = {"Cam","fondo", "salirBoton", "titulo"}
}

fondo = {
    Active = true,

    Components = {"Image"},

    Image = {
        Active = true,
        Background = false,
        Border = false,
        Style= "WindowsLook/StaticImage",
        Name = "FondoMenuArmas",
        Image = "fondoMenuArmas.png",
        Position = {0,0},
        Size = {1000,700}
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
        Text  = "Back",
        TLColor = "FF000000",
        TRColor = "FF000000",
        BLColor = "FF000000",
        BRColor = "FF000000",
        Position = {0.450,0.85},
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
        Name = "TituloArmas",
        Image = "TituloArmas.png",
        Position = {0.151,0.05},
        Size = {697,90}
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