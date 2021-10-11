#ifndef NPC_H
#define NPC_H

#include <Character.h>
#include "LevelMap.h"
#include "Pathfinder.h"


class NPC : public Character
{
    public:
        NPC();
        NPC(LevelMap *mymap, const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);

        void find_nearest();
        void find_next();
        void wait_a_sec();

        Pathfinder path;

        //for y=ax+b
        float a_x, b_x;

        //for x=ay+b
        float a_y, b_y;

        //target nav point
        int target_nav_pos;

        void set_path();

        void ( NPC::*carry_on) ();

        void walk();

        virtual ~NPC();

    protected:

    private:
};

#endif // NPC_H
