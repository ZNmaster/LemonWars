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

NPC::~NPC()
{
    //dtor
}
