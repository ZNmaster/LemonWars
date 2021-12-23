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

void Common_Lemon::hit(int hitpoints, float projectile_angle, int x, int y)
{
    if (!is_hit)
    {
        is_hit = 1;
        move_it = 1;
        hit_angle = projectile_angle;
        splash_x = x;
        splash_y = y;
        carry_on = &Common_Lemon::finish;
    }
}

void Common_Lemon::layer_moved()
{
    move_it = 0;
    sprite_num = 3;
    set_sprite(sprite_num);
    explosion_timer.delay_mills(80);

    carry_on = &NPC::explode;

    //carry_on = &Common_Lemon::lemon_explode;
}

void Common_Lemon::explode()
{

   if (explosion_timer.expired())
   {
       sprite_num ++;
       set_sprite(sprite_num);
       explosion_timer.delay_mills(80);
   }

   if (sprite_num == 10)
   {
       carry_on = &Common_Lemon::finish;
   }

}

Common_Lemon::~Common_Lemon()
{
    //dtor
}
