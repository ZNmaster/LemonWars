#ifndef WEAPONS_H
#define WEAPONS_H

#include <vita2d.h>
#include <vector>

#include "Timer.h"
#include "LevelMap.h"


class Weapons
{
    public:
        Weapons();
        Weapons(unsigned int type, LevelMap *mymap, std::vector<Entity*> *objvec);

        static unsigned int weapon_type;
        unsigned int act(unsigned int sprite_num, float alpha);

        virtual ~Weapons();

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
};

#endif // WEAPONS_H
