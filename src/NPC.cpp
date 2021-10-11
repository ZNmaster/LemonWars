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
}

void NPC::set_path()
{
   path = Pathfinder(abs_x, abs_y, level->levelmem.coord_x[target_nav_pos], level->levelmem.coord_y[target_nav_pos]);
   carry_on = &NPC::walk;



}

void NPC::find_nearest()
{
  target_nav_pos = 12;
  carry_on = &NPC::set_path;
}

void NPC::find_next()
{

}

void NPC::wait_a_sec()
{

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
        carry_on = &NPC::wait_a_sec;
    }



}

NPC::~NPC()
{
    //dtor
}
