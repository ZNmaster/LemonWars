#include "Letter.h"

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

Letter::~Letter()
{
    //dtor
}
