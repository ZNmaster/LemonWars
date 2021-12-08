#include "Sounds.h"

Sounds::Sounds()
{
    //ctor
    SoloudSound.init();
    background_music.loadToMem("app0:/music.ogg");


    projectile1_explosion_sound.load("app0:/assets/sounds/bullet_explosion.ogg");
    projectile_explosion_sound_id = SoloudSound.play(projectile1_explosion_sound, 2, 0, 1);


    gun1_fire_sound.load("app0:/assets/sounds/gun1_fire.ogg");
    gunfire_sound_id = SoloudSound.play (gun1_fire_sound, 1, 0, 1);
    SoloudSound.setProtectVoice(gunfire_sound_id, 1);

}

void Sounds::play_fire_sound()
{
    if (SoloudSound.isValidVoiceHandle(gunfire_sound_id))
    {
       SoloudSound.setPause(gunfire_sound_id, 1);
       SoloudSound.seek(gunfire_sound_id, 0);
       SoloudSound.setPause(gunfire_sound_id, 0);
    }

    else
    {
        SoloudSound.setProtectVoice(gunfire_sound_id, 0);
        gunfire_sound_id = SoloudSound.play(gun1_fire_sound);
        SoloudSound.setProtectVoice(gunfire_sound_id, 1);
    }

}

void Sounds::play_projectile_explosion_sound()
{
    SoloudSound.setPause(projectile_explosion_sound_id, 0);

    projectile_explosion_sound_id = SoloudSound.play(projectile1_explosion_sound, 2, 0, 1);
    //projectile_explosion_sound_id = SoloudSound.play(projectile1_explosion_sound);
}

Sounds::~Sounds()
{
    SoloudSound.deinit();
    //dtor
}
