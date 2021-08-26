#include "Sprite.h"

Sprite::Sprite()
{
    //ctor
}

Sprite::Sprite(const char *filename, int res_x, int res_y, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0, char letter)
               //: GamePlayObj::GamePlayObj(filename)
{
    //custom ctor
    res_of_sprites_x = res_x / num_horizontal_sprites;
    res_of_sprites_y = res_y / num_vertical_sprites;
    pos_x = x0;
    pos_y = y0;
    res_of_spritesheet_x = res_x;
    res_of_spritesheet_y = res_y;
    char_coord_calc(char_num_calc(letter));

}

int Sprite::char_num_calc(char letter)
{
    int letter_ascii = (int)letter;
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

void Sprite::char_coord_calc(int num)
{
    part_x = num % 8;
    part_y = num / 8;

}

Sprite::~Sprite()
{
    //dtor
}
