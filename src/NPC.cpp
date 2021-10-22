#include <vector>

#include "NPC.h"

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

    current_nav_pos = -1;
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
  float ref_dist = 99000;

  for (int i=0; i<level->levelmem.number_of_points; i++)
  {
       float dist = distance(level->levelmem.coord_x[i], level->levelmem.coord_y[i]);
       if (dist <= ref_dist)
       {
           ref_dist = dist;
           second_nearest = nearest;
           nearest = i;
       }

  }

  target_nav_pos = nearest;

  carry_on = &NPC::set_path;
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
    //get the distance to move
    move_delta = get_move_delta();
    path.move_by(move_delta);

    abs_x = path.current_x;
    abs_y = path.current_y;

    if (path.arrived)
    {
        current_nav_pos = target_nav_pos;
        carry_on = &NPC::find_next;
    }

}

void NPC::calc_screen_pos()
{
      pos_x = abs_x - level->part_x - res_of_sprites_x/2;
      pos_y = abs_y - level->part_y - res_of_sprites_y/2;
}

NPC::~NPC()
{
    //dtor
}
