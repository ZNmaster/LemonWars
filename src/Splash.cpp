#include "Splash.h"
//#include "Gamebooter.h"

Splash::Splash()
{
    //ctor
}
Splash::Splash(vita2d_texture *im, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0, float ang)
               : MovObj::MovObj(im, mymap, num_horizontal_sprites,
               num_vertical_sprites, x0, y0)
{
    //select sprite #0
    set_sprite(0);
    sprite_num = 0;
    angle = ang;
    sprite_change_delay = 60;
    last_sprite = 4;
    explosion_timer.delay_mills(sprite_change_delay);
    calc_screen_pos();

}

void Splash::stop_animation()
{

}

void Splash::go_move()
{
   if (sprite_num == last_sprite)
   {
       calc_screen_pos();
       return;
   }

   else
   {
       start_animation();
   }

   calc_screen_pos();

}

Splash::~Splash()
{
    //dtor
}
