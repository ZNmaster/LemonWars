#ifndef WEAPONS_H
#define WEAPONS_H

#include <vita2d.h>
#include <vector>

#include "Timer.h"
#include "LevelMap.h"
#include "soloud.h"
#include "soloud_wav.h"


class Weapons
{
    public:
        Weapons();
        Weapons(unsigned int type, LevelMap *mymap, std::vector<Entity*> *objvec);

        static unsigned int weapon_type;
        unsigned int act(unsigned int sprite_num, float alpha);

        virtual ~Weapons();

        SoLoud::Soloud weapon_sounds;

        SoLoud::Wav fire_sound;

    protected:

    private:
        unsigned int current_player_sprite, default_player_sprite, fire_player_sprite;
        void fire();



        float gun_vector_len;
        float gun_vector_alpha;

        //fire and charge delay
        Timer fire_timer, charge_timer;

        //charged weapon flag
        bool charged;

        LevelMap *level;
        std::vector<Entity*> *obj;

        float player_alpha;

        //we run this func in a separate thread to avoid the lag
        void firesound();

        bool fire_sound_initialized;
        vita2d_texture *projectile_image;

        //const char *filename = "app0:/assets/sounds/gun1_fire.ogg";

};

#endif // WEAPONS_H
