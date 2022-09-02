#ifndef SOUNDS_H
#define SOUNDS_H

#include "soloud.h"
#include "soloud_wavstream.h"
#include "soloud_wav.h"



class Sounds
{
    public:
        Sounds();
        virtual ~Sounds();

        void play_fire_sound();
        void play_projectile_explosion_sound();
        void play_floating_lemon_hit();
        void play_lemon_juice();
        void play_lemonade();
        void play_ezpz();

        void play_beep();
        void play_beep2();










    protected:

    private:

        SoLoud::Soloud SoloudSound;// SoLoud engine

        SoLoud::WavStream background_music;

        SoLoud::Wav gun1_fire_sound;
        SoLoud::Wav projectile1_explosion_sound;
        SoLoud::Wav floating_lemon_hit_sound;
        SoLoud::Wav lemon_juice;
        SoLoud::Wav ezpz;
        SoLoud::Wav lemonade;

        SoLoud::Wav beep;
        SoLoud::Wav beep2;



        int gunfire_sound_id,
            projectile_explosion_sound_id,
            floating_lemon_hit_sound_id;

};

#endif // SOUNDS_H
