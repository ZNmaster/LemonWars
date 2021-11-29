#include "Character.h"

Character::Character()
{
    //ctor
}
Character::Character(const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : Sprite::Sprite(filename, num_horizontal_sprites,
               num_vertical_sprites, x0, y0)
{
    set_pos(x0, y0);
}

Character::Character(vita2d_texture *im, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : Sprite::Sprite(im, num_horizontal_sprites,
               num_vertical_sprites, x0, y0)
{
    set_pos(x0, y0);
}

void Character::set_pos(int x0, int y0)
{
  //start timer to count the time between the frames
  move_timer.start();

  radius = res_of_sprites_x / 2;
  abs_x = x0;
  abs_y = y0;
}

float Character::get_move_delta()
{
    //stop the timer and calculate the time between current and previous frame
    move_timer.stop();


    //int delta = (int)(speed*move_timer.duration_float+1);

    //reset timer
    move_timer.start();

    return speed*move_timer.duration_float;
}

void Character::calc_screen_pos()
{
      pos_x = abs_x - level->part_x - res_of_sprites_x/2;
      pos_y = abs_y - level->part_y - res_of_sprites_y/2;
}


Character::~Character()
{
    //dtor
}
