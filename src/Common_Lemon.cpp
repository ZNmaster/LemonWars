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
    set_roam();

    //select sprite #0
    sprite_coord_calc(0);

}


void Common_Lemon::go_move()
{

  (this->*carry_on) ();

  calc_screen_pos();
}

Common_Lemon::~Common_Lemon()
{
    //dtor
}
