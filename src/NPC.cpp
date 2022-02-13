#include <vector>
#include "NPC.h"
//#include "Gamebooter.h"
#define VISIBILITY 1


//debug



NPC::NPC()
{
    //ctor
    is_hit = 0;
    enemy = 1;
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
    is_hit = 0;
    enemy = 1;

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
}

void NPC::set_path()
{

   if (target_nav_pos == current_nav_pos)
   {
       if (what_after_arrival == &NPC::is_final_dest)
       {
           set_roam();
           carry_on = &NPC::find_next;
           return;
       }

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


  if (level->levelmem.distance[final_nav_pos][second_nearest] < level->levelmem.distance[final_nav_pos][target_nav_pos])
  {
      target_nav_pos = second_nearest;
  }

  carry_on = &NPC::set_path;
}

void NPC::find_nearest_to_player()
{
    final_nav_pos = find_nearest_to(level->player_pos_x, level->player_pos_y, p_vec);
    carry_on = &NPC::find_nearest;
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
        //Gamebooter::soundengine->play_beep2();
        current_nav_pos = target_nav_pos;
        carry_on = what_after_arrival;
    }

        angle = rot.get_angle();
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
    carry_on = &NPC::find_nearest;

    //
    what_after_arrival = &NPC::find_next;

}

void NPC::set_chase()
{
   set_sprite(1);
   carry_on = &NPC::find_nearest_to_player;
   what_after_arrival = &NPC::is_final_dest;
   speed = 200;
}

void NPC::stop_animation()
{
    carry_on = &NPC::finish;
}

bool NPC::spotted()
{
    //we're gonna add some code for distance and the angle of view here



    if(level->levelwalls.visible(abs_x, abs_y, level->player_pos_x, level->player_pos_y))
    {
        return 1;
    }

    return 0;
}

void NPC::is_final_dest()
{

    if (current_nav_pos == final_nav_pos)
    {
        set_roam();
        carry_on = &NPC::wait_a_sec;
        return;
    }
    else
    {
        int wheretogo = level->levelmem.path[final_nav_pos][current_nav_pos];

        if (wheretogo < 0)
        {

            target_nav_pos = final_nav_pos;

            if (target_nav_pos == current_nav_pos)
            {
               set_roam();
               carry_on = &NPC::wait_a_sec;
               return;
            }
        }

        else
        {
           target_nav_pos = wheretogo;
        }

      carry_on = &NPC::set_path;
    }
}


NPC::~NPC()
{
    //dtor
}
