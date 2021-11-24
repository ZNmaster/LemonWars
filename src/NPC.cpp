#include <vector>

#include "NPC.h"

#define VISIBILITY 1

NPC::NPC()
{
    //ctor
}
NPC::NPC(LevelMap *mymap, const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : Character::Character(filename, num_horizontal_sprites,
                                      num_vertical_sprites, x0, y0)
{
    //save the pointer to the Map
    level = mymap;

    //set current nav pos to none
    current_nav_pos = -1;

    //set reference nav point for find nearest
    final_nav_pos = 0;

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
       carry_on = &NPC::wait_a_sec;
       npc_wait_timer.delay_mills(rand.int_random(7000));
   }
   else
   {
       path = Pathfinder(abs_x, abs_y, level->levelmem.coord_x[target_nav_pos], level->levelmem.coord_y[target_nav_pos]);
       carry_on = &NPC::walk;
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

/*int NPC::find_nearest_to(int from_x, int from_y, std::vector<Point_int> target_points)
{
  float ref_dist = 99000;
  float ref_dist_sec = 99000;

  for (std::vector<Point_int>::size_type i = 0; i < target_points.size(); i++)
  {
       float dist = distance(from_x, from_y, target_points[i].x, target_points[i].y);
       if (dist <= ref_dist)
       {
           ref_dist_sec = ref_dist;
           ref_dist = dist;
           second_nearest = nearest;
           nearest = i;
       }
       else if(dist<=ref_dist_sec)
       {
           ref_dist_sec = dist;
           second_nearest = i;
       }

  }

  return nearest;
}*/

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
    if(spot_timer.expired())
    {
        if(spotted())
        {
        sprite_coord_calc(1);
        }
    spot_timer.delay_mills(300);

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

}

void NPC::set_roam()
{
    //set the speed in pixels per second
    speed = 100;

    //first action is find nearest
    carry_on = &NPC::find_nearest;

    //
    what_after_arrival = &NPC::find_next;

}

void NPC::set_chase()
{

}

void NPC::calc_screen_pos()
{
      pos_x = abs_x - level->part_x - res_of_sprites_x/2;
      pos_y = abs_y - level->part_y - res_of_sprites_y/2;
}

bool NPC::spotted()
{
    //we're gonna add some code for distance and the angle of view here



    if(level->levelwalls.intersection(abs_x, abs_y, level->player_pos_x, level->player_pos_y, VISIBILITY))
    {
        return 1;
    }

    return 0;
}

NPC::~NPC()
{
    //dtor
}
