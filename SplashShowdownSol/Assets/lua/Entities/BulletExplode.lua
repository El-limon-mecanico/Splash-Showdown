Bullet = {
    Active = true,

    Components = {"Transform", "MeshRenderer", "Rigidbody", "BulletMovement", "Explode", "DealDamage", "AudioSource"},

    Transform = {
        Position = {0,0,0},
        Scale = {0.3,0.3,0.3},
        Rotation = {0,0,0}
    },

    MeshRenderer = {
        Mesh = "Sphere",
        Material = "Tanques/Verde"
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
        BulletSpeed = 7.0
    },

    Explode = {
        Enabled = true
    },

    DealDamage= {
        Damage = 30        
    },

    AudioSource = {
        Source = "explode.wav",
        Volume = 1.5,
        Enabled = true
    }
}