#ifndef WEAPONS_H
#define WEAPONS_H

#include <vector>

#include "Timer.h"
#include "LevelMap.h"
//#include "Layers.h"



class Weapons
{
    public:
        Weapons();
        Weapons(unsigned int type, LevelMap *mymap, std::vector<std::vector<Entity *> *> &lay);

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
        std::vector<Entity*> *en_layer;

        float player_alpha;

        //we run this func in a separate thread to avoid the lag
        void firesound();

        bool fire_sound_initialized;
        vita2d_texture *projectile_image;

        //const char *filename = "app0:/assets/sounds/gun1_fire.ogg";

};

#endif // WEAPONS_H
