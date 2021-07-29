#include "Base_Init.h"



Base_Init::Base_Init()
{
    //ctor
}

Base_Init::~Base_Init()
{
    //dtor
}

void Base_Init::GPU_init()
{
    vita2d_init();
	vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));

	//pgf = vita2d_load_default_pgf();
	pvf = vita2d_load_default_pvf();
}
void Base_Init::GPU_finish()
{
    vita2d_wait_rendering_done();
    vita2d_fini();
}

void Base_Init::draw_grid()
{
    //draw a grid with stride 100
    draw_grid(100);
}

void Base_Init::draw_grid(int stride)
{
    //drawing vertical lines of the grid
    int x_start = stride;


    while(x_start < 960)
    {

    int x_stop = x_start;
    vita2d_draw_line(x_start, 0, x_stop, 544, RGBA8(0, 255, 252, 150));
    x_start = x_start + stride;

    }

    //drawing horizontal lines of the grid
    int y_start = stride;


    while(y_start < 544)
    {

    int y_stop = y_start;
    vita2d_draw_line(0, y_start, 960, y_stop, RGBA8(0, 255, 252, 150));
    y_start = y_start + stride;

    }

}
