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


        //pointer to a current action func (the func is called by it each frame from go_move)
        void ( NPC::*carry_on) ();

        //action funcs:

        //find nearest nav point
        void find_nearest();
        //find next nav point
        void find_next();
        //wait at the current nav point
        void wait_a_sec();
        //walking to a target point
        void walk();


        //calculates path between 2 nav points
        Pathfinder path;
        //init pathfinder ant set a path to a target nav point
        void set_path();

        //calculates position on the screen based on abs_x and abs_y
        void calc_screen_pos();

        //target nav point
        int target_nav_pos;


        /*
        //for y=ax+b
        float a_x, b_x;

        //for x=ay+b
        float a_y, b_y;
        */







        virtual ~NPC();

    protected:

    private:
};

#endif // NPC_H
