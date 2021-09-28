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

void NPC::calc_path_func(int x1, int y1, int x2, int y2)
{
    a_x = (y2 - y1)/(x2 - x1);
    b_x = y2 - a_x*x2;

    a_y = (x2 - x1)/(y2 - y1);
    b_y = x2 - a_y*y2;


}

NPC::~NPC()
{
    //dtor
}
