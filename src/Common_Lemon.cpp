#include "Common_Lemon.h"

Common_Lemon::Common_Lemon()
{
    //ctor
}

Common_Lemon::Common_Lemon(LevelMap *mymap, const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : NPC::NPC(mymap, filename, num_horizontal_sprites,
                                      num_vertical_sprites, x0, y0)
{

    //set the speed in pixels per second
    speed = 200;

    //start timer to count the time between the frames
    move_timer.start();

    //select sprite #0
    sprite_coord_calc(0);



}


void Common_Lemon::go_move()
{
  pos_x = abs_x - level->part_x;
  pos_y = abs_y - level->part_y;
}

Common_Lemon::~Common_Lemon()
{
    //dtor
}
