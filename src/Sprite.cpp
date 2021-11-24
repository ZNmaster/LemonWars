#include "Sprite.h"

Sprite::Sprite()
{
    //ctor
}

Sprite::Sprite(const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : GamePlayObj::GamePlayObj(filename)
{
    //custom ctor
    res_of_sprites_x = loaded_image_res_x / num_horizontal_sprites;
    res_of_sprites_y = loaded_image_res_y / num_vertical_sprites;
    pos_x = x0 - res_of_sprites_x/2;
    pos_y = y0- res_of_sprites_y/2;

    partial = 1;

}


void Sprite::sprite_coord_calc(int num)
{
    part_x = (num % 8)*res_of_sprites_x;
    part_y = (num / 8)*res_of_sprites_y;

}

Sprite::~Sprite()
{
    //dtor
}
