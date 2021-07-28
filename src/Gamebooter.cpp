#include "Gamebooter.h"
#include <iostream>
#include "Menu.h"
#include <string.h>


Gamebooter::Gamebooter()
{
    //ctor

    //initializing 2d library

    vita2d_init();
	vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));

	//pgf = vita2d_load_default_pgf();
	pvf = vita2d_load_default_pvf();

    //GPU_init();

	image = vita2d_load_PNG_file("app0:/Title_screen.png");

	memset(&pad, 0, sizeof(pad));

}

void Gamebooter::Play()
{
        //soloud
    gSoloud.init(); // Initialize SoLoud
    gWave.load("app0:/music.ogg");
    gSoloud.play(gWave);

  while (1)
  {

        sceCtrlPeekBufferPositive(0, &pad, 1);
        if (pad.buttons & SCE_CTRL_START)
               {//GPU_finish();
                   break;}


        vita2d_start_drawing();
		vita2d_clear_screen();

        //vita2d_draw_fill_circle(200, 420, 100, RGBA8(0, 255,0 ,255));

        vita2d_draw_texture(image, 0, 0);

        //vita2d_draw_fill_circle(500, 220, 100, RGBA8(200, 255, 87 ,60));

        //vita2d_pvf_draw_text(pvf, 70, 80, RGBA8(0,255,0,255), 1.0f, "Waiting 8 ms");

        vita2d_end_drawing();
        vita2d_swap_buffers();
        //std::this_thread::sleep_for (std::chrono::milliseconds(100));

        if (pad.buttons & SCE_CTRL_RIGHT){
                rad += 0.1f;
        } else if (pad.buttons & SCE_CTRL_LEFT){
                rad -= 0.1f;;
            }


  }

  return;
}


    //Menu MainMenu;
    //MainMenu.MenuRun();


Gamebooter::~Gamebooter()
{
    //dtor
}
