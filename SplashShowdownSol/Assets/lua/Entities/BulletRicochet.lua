Bullet = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody", "BulletMovement", "Ricochet", "DealDamage", "AudioSource"},

    Transform = {
        Position = {0,0,0},
        Scale = {0.2,0.2,0.2},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Sphere",
        Material = "Tanques/Rojo"
    },

    Rigidbody = {
        Type = "Sphere",
        Mass = 1,
        Trigger = false,
        Static = false,
        PositionConstrains = {0,1,0},
        RotationConstrains = {0,0,0}
    },

    BulletMovement = {
        BulletSpeed = 10.0
    },

    Ricochet = {
        BouncesMax = 4
    },

    DealDamage= {
        Damage = 20        
    },

    AudioSource = {
        Source = "bounce.wav",
        Volume = 0.8,
        Loops = 0,
        Enabled = true
    }
}