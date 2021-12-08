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










    protected:

    private:

        SoLoud::Soloud SoloudSound;// SoLoud engine

        SoLoud::WavStream background_music;

        SoLoud::Wav gun1_fire_sound;
        SoLoud::Wav projectile1_explosion_sound;



        int gunfire_sound_id,
            projectile_explosion_sound_id;

};

#endif // SOUNDS_H
