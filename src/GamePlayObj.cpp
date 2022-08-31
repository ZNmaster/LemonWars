#include "GamePlayObj.h"

extern unsigned char _binary_missing_png_start;


GamePlayObj::GamePlayObj()
{
    //ctor
    external_image = 0;

}

GamePlayObj::GamePlayObj(const char *filename)
{
    external_image = 0;
    image = vita2d_load_PNG_file(filename);
    set_texture();
}

GamePlayObj::GamePlayObj(vita2d_texture *im)
{
    external_image = 1;
    image = im;
    set_texture();
}

void GamePlayObj::set_texture()
{
    if (!image)
    {
        external_image = 0;
        //image = vita2d_load_PNG_buffer(&_binary_missing_png_start);
    }

    started = 0;
    set_res();
}


void GamePlayObj::set_res()
{
    loaded_image_res_x = vita2d_texture_get_width (image);
    loaded_image_res_y = vita2d_texture_get_height (image);

}

GamePlayObj::~GamePlayObj()
{
    //dtor
    if (image && !external_image)
    {
        vita2d_free_texture (image);
    }

}


