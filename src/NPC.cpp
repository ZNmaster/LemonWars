#include <vector>
#include <thread>
#include <chrono>

#include "NPC.h"
#include "Point_float.h"
#include "LineVec.h"

//#define VISIBILITY 1



NPC::NPC()
{
    //ctor

    enemy = 1;
    level->number_of_enemies_spawned++;

    //set nav point for final approach (player coord)
    fa_point_index = 100 - level->number_of_enemies_spawned;


}
NPC::NPC(const char *filename, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : MovObj::MovObj(filename, mymap, num_horizontal_sprites,
                                      num_vertical_sprites, x0, y0)
{
    init_nav_pos();
}

NPC::NPC(vita2d_texture *im, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : MovObj::MovObj(im, mymap, num_horizontal_sprites,
                                      num_vertical_sprites, x0, y0)
{
    init_nav_pos();
}


void NPC::init_nav_pos()
{
    direct_path_check_delay = 600;
    level->number_of_enemies_spawned++;

    //set nav point for final approach (player coord)
    fa_point_index = 100 - level->number_of_enemies_spawned;

    //reset find nearest flags
    find_nearest_running = 0;

    enemy = 1;

    //set chase mode timer
    direct_path_check_timer.delay_mills(direct_path_check_delay);

    //set current nav pos to none
    current_nav_pos = -1;

    //copy of nav points
    for (int i=0; i<level->levelmem.number_of_points; i++)
    {
      Point_int p;
      p.x = level->levelmem.coord_x[i];
      p.y = level->levelmem.coord_y[i];
      p_vec.push_back(p);
    }

    //set target object
    target_to_chase = Target(level);
}

void NPC::set_path()
{

   //if the target point is the current location the enemy will:
   if (target_nav_pos == current_nav_pos)
   {
       //switch to roam if in chasing mode and find next nav point to roam
       if (what_after_arrival == &NPC::is_final_dest)
       {
           set_roam();
           carry_on = &NPC::find_next;
           return;
       }

       //wait some time if in roaming mode
       carry_on = &NPC::wait_a_sec;
       npc_wait_timer.delay_mills(rand.int_random(7000));
   }

   else
   {
       path = Pathfinder(abs_x, abs_y, level->levelmem.coord_x[target_nav_pos], level->levelmem.coord_y[target_nav_pos]);
       carry_on = &NPC::walk;
       rot = Rotator(angle, path.sin_a, path.cos_a, 8);
   }

}

void NPC::find_nearest()
{

  target_nav_pos = find_nearest_to(abs_x, abs_y, p_vec);


  //when the nearest point visible
  if (level->levelwalls.visible(abs_x, abs_y, p_vec[target_nav_pos].x, p_vec[target_nav_pos].y))
      {
        //set second nearest if needed
        if (
          //when the distance to final nav pos from second nearest is less than that from nearest
          (level->levelmem.distance[final_nav_pos][second_nearest] < level->levelmem.distance[final_nav_pos][target_nav_pos])
            //in chasing mode only
            && (what_after_arrival == &NPC::is_final_dest)
           )

            //second nearest visible
            if(level->levelwalls.visible(abs_x, abs_y, p_vec[second_nearest].x, p_vec[second_nearest].y))
            {
               target_nav_pos = second_nearest;
            }
      }
    // the nearest is not visible
    else
        {
            //second nearest visible
            if(level->levelwalls.visible(abs_x, abs_y, p_vec[second_nearest].x, p_vec[second_nearest].y))
            {
               target_nav_pos = second_nearest;
            }
            //second nearest not visible
            else
            {
                if(level->levelwalls.visible(abs_x, abs_y, p_vec[third_nearest].x, p_vec[third_nearest].y))
                {
                   target_nav_pos = third_nearest;
                }

                //if third nearest is not visible then set any visible
                else
                {
                    for (std::vector<Point_int>::size_type i = 0; i < p_vec.size(); i++)
                    {
                        if(level->levelwalls.visible(abs_x, abs_y, p_vec[i].x, p_vec[i].y))
                           {
                               target_nav_pos = i;
                               break;
                           }
                    }
                }
            }
        }

  carry_on = &NPC::set_path;
  find_nearest_running = 0;
}

void NPC::where_to_go()
{
    if (!find_nearest_running)
    {
        find_nearest_running = 1;
        std::thread t1(&NPC::find_nearest, this);
        if (t1.joinable())
        {
            t1.detach();
        }
    }

}

void NPC::find_nearest_to_player()
{
    final_nav_pos = find_nearest_to(level->player_pos_x, level->player_pos_y, p_vec);
    carry_on = &NPC::where_to_go;
}

void NPC::find_next()
{
    std::vector<int> possible_nav_points;
    for(int i = 0; i < level->levelmem.number_of_points; i++)
    {
        if (level->levelmem.path[i][current_nav_pos] == -1)
        {
            possible_nav_points.push_back(i);
        }
    }
    int pos = rand.int_random(possible_nav_points.size() - 1);
    target_nav_pos = possible_nav_points[pos];

    carry_on = &NPC::set_path;

}

void NPC::wait_a_sec()
{

   if (npc_wait_timer.expired())
   {
       carry_on = &NPC::find_next;
       move_timer.start();
   }
}

void NPC::walk()
{
    //check the distance to player
    if (target_to_chase.distance(abs_x, abs_y) <= (50))
    {

        target_to_chase.player->hit(1000, 1, 5, 5);

        return;
    }

    //spotting enabled in roaming mode only
    if (what_after_arrival == &NPC::find_next)
    {
        if(spot_timer.expired())
      {
        if(spotted())
        {
          set_chase();
        }
    spot_timer.delay_mills(300);

      }
    }

    //get the distance to move
    move_delta = get_move_delta();
    path.move_by(move_delta);

    abs_x = path.current_x;
    abs_y = path.current_y;


    if (path.arrived)
    {
        current_nav_pos = target_nav_pos;
        carry_on = what_after_arrival;
    }


    //checking if direct path is possible after coordinates has been changed
    if (what_after_arrival != &NPC::find_next)
    {
        if (target_to_chase.direct_path_available(abs_x, abs_y, radius))
        {
            //set direct path if possible
            set_new_direct();
        }
        //run_direct_path_check();
    }

    angle = rot.get_angle();

}

void NPC::set_new_direct()
{
            level->levelmem.coord_x[fa_point_index] = level->player_pos_x;
            level->levelmem.coord_y[fa_point_index] = level->player_pos_y;
            target_nav_pos = fa_point_index;
            current_nav_pos = fa_point_index - 1;
            final_nav_pos = target_nav_pos;
            carry_on = &NPC::set_path;
            what_after_arrival = &NPC::fa_arrived;
            spot_timer.delay_mills(2500);
}

void NPC::set_roam()
{
    //set the speed in pixels per second
    speed = 100;

    //select sprite #0
    set_sprite(0);

    //set reference nav point for find nearest
    final_nav_pos = 0;

    //first action is find nearest
    carry_on = &NPC::where_to_go;

    //
    what_after_arrival = &NPC::find_next;

}

void NPC::set_chase()
{
   //set chasing sprite
   set_sprite(1);

   //set state to chase sequence
   carry_on = &NPC::find_nearest_to_player;

   //final destination is a target nav pos
   final_nav_pos = target_nav_pos;

   //what to do after arrival
   what_after_arrival = &NPC::is_final_dest;
   speed = 100;
}

void NPC::stop_animation()
{
    carry_on = &NPC::finish;
}

bool NPC::spotted()
{
    //we're gonna add some code for distance and the angle of view here

    return level->levelwalls.visible(abs_x, abs_y, level->player_pos_x, level->player_pos_y);

}

void NPC::is_final_dest()
{

    //if the enemy has arrived at the final nav point
    if (current_nav_pos == final_nav_pos)
    {
        set_roam();
        carry_on = &NPC::wait_a_sec;
        return;
    }

    //if it's not the final nav point yet
    else
    {
        int wheretogo = level->levelmem.path[final_nav_pos][current_nav_pos];

        //direct path exists
        if (wheretogo < 0)
        {

            //go directly to final nav point
            target_nav_pos = final_nav_pos;


            //just in case the enemy is already at the final nav point (normally should never happen)
            if (target_nav_pos == current_nav_pos)
            {
               set_roam();
               carry_on = &NPC::wait_a_sec;
               return;
            }
        }

        //go to transit point
        else
        {
           target_nav_pos = wheretogo;
        }

      carry_on = &NPC::set_path;
    }
}

void NPC::fa_arrived()
{
   //distance to move (we don't use it here, but it is need to avoid teleportation)
   move_delta = get_move_delta();
   direct_path_check_timer.make_expired();
   if (target_to_chase.direct_path_available(abs_x, abs_y, radius))
   {
      set_new_direct();
   }

   if (spot_timer.expired())
   {
       set_roam();
   }
}

NPC::~NPC()
{
    //dtor

    //wait until the threads finish the job
    while (find_nearest_running)
    {
        std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }

}
