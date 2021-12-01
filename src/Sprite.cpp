#include "Sprite.h"

Sprite::Sprite()
{
    //ctor
    image_loaded = 0;
}

Sprite::Sprite(const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : GamePlayObj::GamePlayObj(filename)
{
    //custom ctor
    set_sprites(num_horizontal_sprites, num_vertical_sprites, x0, y0);
    image_loaded = 0;

}

Sprite::Sprite(vita2d_texture *im, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : GamePlayObj::GamePlayObj(im)
{
    //custom ctor
    set_sprites(num_horizontal_sprites, num_vertical_sprites, x0, y0);
    image_loaded = 1;

}

void Sprite::set_sprites(int num_horizontal_sprites, int num_vertical_sprites, int x0, int y0)
{
    res_of_sprites_x = loaded_image_res_x / num_horizontal_sprites;
    res_of_sprites_y = loaded_image_res_y / num_vertical_sprites;
    pos_x = x0 - res_of_sprites_x/2;
    pos_y = y0 - res_of_sprites_y/2;

    partial = 1;
}

void Sprite::set_sprite(int num)
{
    part_x = (num % 8)*res_of_sprites_x;
    part_y = (num / 8)*res_of_sprites_y;

}

Sprite::~Sprite()
{
    //dtor
    //to ensure the image texture is not deleted in GamePlayObj
    if (image_loaded)
    {
        image = nullptr;
    }
}
