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

    floating_lemon_hit_sound.load("app0:/assets/sounds/Lemon_Squish.ogg");
    floating_lemon_hit_sound_id = SoloudSound.play (floating_lemon_hit_sound, 1, 0, 1);

    lemon_juice.load("app0:/assets/sounds/player/lemon_juice.ogg");

    lemonade.load("app0:/assets/sounds/player/lemonade.ogg");

    ezpz.load("app0:/assets/sounds/player/ezpz2.ogg");

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
void Sounds::play_floating_lemon_hit()
{
    SoloudSound.setPause(floating_lemon_hit_sound_id, 0);

    floating_lemon_hit_sound_id = SoloudSound.play(floating_lemon_hit_sound, 1, 0, 1);
}

void Sounds::play_lemonade()
{
   SoloudSound.play(lemonade);
}

void Sounds::play_lemon_juice()
{
   SoloudSound.play(lemon_juice);
}

void Sounds::play_ezpz()
{
   SoloudSound.play(ezpz);
}

Sounds::~Sounds()
{
    SoloudSound.deinit();
    //dtor
}
