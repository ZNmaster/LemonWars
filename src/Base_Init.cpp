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
