#ifndef NPC_H
#define NPC_H

#include <vector>

#include "MovObj.h"
#include "Timer.h"
#include "LevelMap.h"
#include "RNG.h"
#include "Point_int.h"
#include "Rotator.h"


class NPC : public MovObj
{
    public:

        NPC();
        NPC(const char *filename, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);
        NPC(vita2d_texture *im, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);

        //final approach index
        int fa_point_index;

        //pointer to a current action func (the func is called by it each frame from go_move)
        void ( NPC::*carry_on) ();
        void ( NPC::*what_after_arrival) ();

        //action funcs:

        //find nearest nav point to current object
        void find_nearest();

        //finds a nav point where to go
        virtual void where_to_go();

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
        //check if is final destination for chasing
        void is_final_dest();

        //init pathfinder ant set a path to a target nav point
        void set_path();

        void run_direct_path_check();
        void set_new_direct();

        virtual void stop_animation();

        //target nav point
        int target_nav_pos;

        //final destination
        int final_nav_pos;

        //current nav point
        int current_nav_pos;

        vita2d_texture *juice;



        bool spotted();

        RNG rand;

        Timer npc_wait_timer;

        Timer spot_timer;

        Timer direct_path_check_timer;
        unsigned int direct_path_check_delay;

        Rotator rot;

        //When a projectile hits the ennemy
        float hit_angle;
        int splash_x, splash_y;

        //visibility check flags
        bool right_visible, left_visible;
        bool right_visibility_running, left_visibility_running;

        //nearest point checks flags
        bool find_nearest_running;


        void check_visibility(bool &running_flag, bool &visibility_flag, float side);
        void fa_arrived();

        virtual ~NPC();

    protected:

    private:
        //copy of nav points
        std::vector<Point_int> p_vec;
        void init_nav_pos();

};

#endif // NPC_H
