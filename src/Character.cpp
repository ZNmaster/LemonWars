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
  radius = 100;
  abs_x = x0+radius;
  abs_y = y0+radius;
}

Character::~Character()
{
    //dtor
}
