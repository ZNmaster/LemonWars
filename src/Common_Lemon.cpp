#include "Common_Lemon.h"

Common_Lemon::Common_Lemon()
{
    //ctor
}

Common_Lemon::Common_Lemon(const char *filename, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : NPC::NPC(filename, mymap, num_horizontal_sprites,
                                      num_vertical_sprites, x0, y0)
{
    angle = 0;
    set_roam();

    //select sprite #0
    set_sprite(0);

}

Common_Lemon::Common_Lemon(vita2d_texture *im, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : NPC::NPC(im, mymap, num_horizontal_sprites,
                                      num_vertical_sprites, x0, y0)
{
    angle = 0;
    set_roam();

    //select sprite #0
    set_sprite(0);

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
