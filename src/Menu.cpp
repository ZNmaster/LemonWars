#include "Menu.h"
#include <iostream>
#include "Scanner.h"
#include <string.h>

Menu::Menu()
{
    //ctor
    std::cout << "Menu Loaded!" << std::endl;

    // assigning func pointers
    MenuFuncPtr [0] = &Menu::StartPlay;
    MenuFuncPtr [1] = &Menu::StartLoad;
    MenuFuncPtr [2] = &Menu::StartCredits;
    MenuFuncPtr [3] = &Menu::StartControls;

    //test image
    GPU_init();

	//image = vita2d_load_PNG_file("app0:/Title_screen.png");

	//memset(&pad, 0, sizeof(pad));

	/*while (1)
  {

        sceCtrlPeekBufferPositive(0, &pad, 1);
        if (pad.buttons & SCE_CTRL_START)
               {
                   GPU_finish();
                   vita2d_free_texture (image);
                   break;}


        vita2d_start_drawing();
		vita2d_clear_screen();

        //vita2d_draw_fill_circle(200, 420, 100, RGBA8(0, 255,0 ,255));

        //vita2d_draw_texture_tint(image, 0, 0, RGBA8(0, 255,0 ,255));

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


*/
}

void Menu::MenuRun()
{
    std::cout << "Menu is running" << std::endl;

    ActivatePlay();
      if (Scanner::start_pressed)
    {
        //assigning and calling a test method
        StartActiveMenuItem = MenuFuncPtr[MenuItem];

        (this->*StartActiveMenuItem) ();

    }


}




void Menu::StartPlay()
{
        std::cout << "StartPlay func" << std::endl;
}
void Menu::StartLoad()
{
        std::cout << "StartLoad func" << std::endl;
}
void Menu::StartCredits()
{
        std::cout << "StartCredits func" << std::endl;
}
void Menu::StartControls()
{
        std::cout << "StartControls func" << std::endl;
}
void Menu::ActivatePlay()
{
   MenuItem = 0;
}
void Menu::ActivateLoad()
{
   MenuItem = 1;
}
void Menu::ActivateCredits()
{
   MenuItem = 2;
}
void Menu::ActivateControls()
{
   MenuItem = 3;
}
Menu::~Menu()
{
    //dtor
}
