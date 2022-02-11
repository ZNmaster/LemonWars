#include "MovObj.h"

MovObj::MovObj()
{
    //ctor
}
MovObj::MovObj(const char *filename, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : Sprite::Sprite(filename, num_horizontal_sprites,
               num_vertical_sprites, x0, y0)
{
    set_pos(mymap, x0, y0);
}

MovObj::MovObj(vita2d_texture *im, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : Sprite::Sprite(im, num_horizontal_sprites,
               num_vertical_sprites, x0, y0)
{
    set_pos(mymap, x0, y0);
}

void MovObj::set_pos(LevelMap *mymap, int x0, int y0)
{
  //save the pointer to the Map
  level = mymap;
  //start timer to count the time between the frames
  move_timer.start();

  radius = res_of_sprites_x / 2;
  abs_x = x0;
  abs_y = y0;
}

float MovObj::get_move_delta()
{
    //stop the timer and calculate the time between current and previous frame
    move_timer.stop();

    //reset timer
    move_timer.start();

    return speed*move_timer.duration_float;
}

void MovObj::calc_screen_pos()
{
      pos_x = int(abs_x - (float)(level->part_x) - (float)(res_of_sprites_x)/2.0);
      pos_y = int(abs_y - (float)(level->part_y) - (float)(res_of_sprites_y)/2.0);
}

void MovObj::finish()
{

}

void MovObj::start_animation()
{

   if (explosion_timer.expired())
   {
       sprite_num ++;
       set_sprite(sprite_num);
       explosion_timer.delay_mills(sprite_change_delay);
   }

   if (sprite_num == last_sprite)
   {
       stop_animation();
   }

}

void MovObj::stop_animation()
{

}

MovObj::~MovObj()
{
    //dtor
}
