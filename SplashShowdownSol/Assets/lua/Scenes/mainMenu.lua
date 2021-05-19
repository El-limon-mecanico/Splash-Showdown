mainMenu = {
    entities = {"Cam","UI"}
}

UI = {
    Active = true,

    Components = {"Image", "Button", "Text"},
    
    Button = {
        Active = true,
        Enable = true,
        Style = "WindowsLook/Button",
        Name  = "ButtonPlay",
        Text  = "Play",
        TLColor = "FF000000",
        TRColor = "FF000000",
        BLColor = "FF000000",
        BRColor = "FF000000",
        Position = {0.450,0.450},
        Size = {100,50},
        CallBackFunction = "botonPresionado"
    },

    Text = {
        Active = true,
        Background = false,
        Border = false,
        Style= "TaharezLook/StaticText",
        Name = "TextoE1",
        Text = " Esto no es un boton, es solo texto, pero desde lua",
        TLColor = "FF000000",
        TRColor = "FF000000",
        BLColor = "FF000000",
        BRColor = "FF000000",
        Position = {0.5,0.05},
        Size = {405,50}
    },

    Image = {
        Active = true,
        Style= "WindowsLook/StaticImage",
        Name = "FondoMenuPrincipal",
        Image = "fondoMenuPrincipal.png",
        Position = {0,0},
        Size = {1000,700}
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