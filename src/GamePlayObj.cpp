#include "GamePlayObj.h"

extern unsigned char _binary_missing_png_start;


GamePlayObj::GamePlayObj()
{
    //ctor

}

GamePlayObj::GamePlayObj(const char *filename)
{
    image = vita2d_load_PNG_file(filename);
    init();
}

GamePlayObj::GamePlayObj(vita2d_texture *im)
{
    image = im;
    init();
}

void GamePlayObj::init()
{
    if (!image)
    {
        image = vita2d_load_PNG_buffer(&_binary_missing_png_start);
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
    if (image)
    {
        vita2d_free_texture (image);
    }

}


