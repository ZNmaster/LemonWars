#ifndef WEAPONS_H
#define WEAPONS_H
#include "Timer.h"
#include <vita2d.h>


class Weapons
{
    public:
        Weapons();
        Weapons(unsigned int type);

        static unsigned int weapon_type;
        unsigned int act(unsigned int sprite_num);


        virtual ~Weapons();

        vita2d_texture *image;

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
};

#endif // WEAPONS_H
