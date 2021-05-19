mainMenu = {
    entities = {"Cam","fondo", "playBoton", "titulo"}
}

fondo = {
    Active = true,

    Components = {"Image"},

    Image = {
        Active = true,
        Style= "WindowsLook/StaticImage",
        Name = "FondoMenuPrincipal",
        Image = "fondoMenuPrincipal.png",
        Position = {0,0},
        Size = {1000,700}
    }
}

playBoton = {
    Active = true,

    Components = {"Button"},

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
    }
}

titulo = {
    Active = true,

    Components = {"Image"},

    Image = {
        Active = true,
        Style= "WindowsLook/StaticImage",
        Name = "TituloPrincipal",
        Image = "Titulo.png",
        Position = {0.264,0.10},
        Size = {473,200}
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