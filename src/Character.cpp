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
  //start timer to count the time between the frames
  move_timer.start();

  radius = res_of_sprites_x / 2;
  abs_x = x0+radius;
  abs_y = y0+radius;
}

int Character::get_move_delta()
{
    //stop the timer and calculate the time between current and previous frame
    move_timer.stop();


    int delta = (int)(speed*move_timer.duration_float+1);

    //reset timer
    move_timer.start();

    return delta;
}

Character::~Character()
{
    //dtor
}
