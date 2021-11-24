#ifndef NPC_H
#define NPC_H

#include <vector>

#include "Character.h"
#include "Timer.h"
#include "LevelMap.h"
#include "Pathfinder.h"
#include "RNG.h"
#include "Point_int.h"
#include "NearestPoint.h"


class NPC : public Character, public NearestPoint
{
    public:
        NPC();
        NPC(LevelMap *mymap, const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);


        //pointer to a current action func (the func is called by it each frame from go_move)
        void ( NPC::*carry_on) ();
        void ( NPC::*what_after_arrival) ();

        //action funcs:

        //find nearest nav point to current object
        void find_nearest();
        //find nearest nav point to a position on the map
        //int find_nearest_to(int from_x, int from_y, std::vector<Point_int> target_points);
        //find nearest nav point to player
        void find_nearest_to_player();

        //find next nav point
        void find_next();
        //wait at the current nav point
        void wait_a_sec();
        //walking to a target point
        void walk();
        //set roaming mode
        void set_roam();
        //set chasing mode
        void set_chase();


        //calculates path between 2 nav points
        Pathfinder path;
        //init pathfinder ant set a path to a target nav point
        void set_path();

        //calculates position on the screen based on abs_x and abs_y
        void calc_screen_pos();

        //target nav point
        int target_nav_pos;
        //final destination
        int final_nav_pos;

        //current nav point
        int current_nav_pos;
        //int nearest, second_nearest;

        bool spotted();

        RNG rand;

        Timer npc_wait_timer;

        Timer spot_timer;


        /*
        //for y=ax+b
        float a_x, b_x;

        //for x=ay+b
        float a_y, b_y;
        */







        virtual ~NPC();

    protected:

    private:
        //copy of nav points
        std::vector<Point_int> p_vec;
};

#endif // NPC_H
