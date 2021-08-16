#include "Letter.h"
#include <cmath>

Letter::Letter()
{
    //ctor
}
Letter::Letter(const char *filename, int res_x, int res_y, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0, int letter)
               : Sprite::Sprite(filename, res_x, res_y, num_horizontal_sprites,
                                num_vertical_sprites, x0, y0)
{
    sprite_coord_calc(char_pos_calc(letter));
    effect_jump = 0;

}

int Letter::char_pos_calc(int letter_ascii)
{

    int char_position = 93;
    //Check capitals
    if (letter_ascii > 64 && letter_ascii < 91)
    {
        char_position = letter_ascii - 65;
    }
      //Check lower case
      else if (letter_ascii > 96 && letter_ascii < 123)
      {
        char_position = letter_ascii - 71;
      }
   return char_position;
}

void Letter::set_effect(int effect_num, int delta1, int i)
{
    effect_jump = 1;
    x0 = pos_x;
    y0 = pos_y;
    int odd = i % 2;
    direction = pow((-1),odd);
    delta = delta1;
}

void Letter::go_move()
{
   if (effect_jump)
   {
       pos_y += delta*direction;
       if (pos_y < (y0 - res_of_sprites_y*k/2) || pos_y > (y0 + res_of_sprites_y*k/2))
       {
           direction = -direction;
       }

   }
}


Letter::~Letter()
{
    //dtor
}
