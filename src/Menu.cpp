#include "Menu.h"
#include <string.h>


Menu::Menu()
{
    //ctor

    //current menu item
    current = 0;

    GPU_init();

    scanner2 = new Scanner;
    scanner2->Scan();

    // assigning func pointers
    MenuFuncPtr [0] = &Menu::StartPlay;
    MenuFuncPtr [1] = &Menu::StartLoad;
    MenuFuncPtr [2] = &Menu::StartCredits;
    MenuFuncPtr [3] = &Menu::StartControls;
    MenuFuncPtr [4] = &Menu::StartExit;

    //creating menu objects


    GamePlayObj * background_1 = new GamePlayObj ("app0:/assets/images/main_menu/Background.png");
    obj.push_back (background_1);



    GamePlayObj * play_button = new GamePlayObj ("app0:/assets/images/main_menu/play.png");
    play_button->pos_x = 200;
    play_button->pos_y = 200;
    obj.push_back (play_button);
    menuitem[1] = play_button;

    GamePlayObj * load_button = new GamePlayObj ("app0:/assets/images/main_menu/load.png");
    load_button->pos_x = 600;
    load_button->pos_y = 200;
    obj.push_back (load_button);
    menuitem[4] = load_button;

    GamePlayObj * controls_button = new GamePlayObj ("app0:/assets/images/main_menu/controls.png");
    controls_button->pos_x = 600;
    controls_button->pos_y = 330;
    obj.push_back (controls_button);
    menuitem[5] = controls_button;

    GamePlayObj * credits_button = new GamePlayObj ("app0:/assets/images/main_menu/credits.png");
    credits_button->pos_x = 200;
    credits_button->pos_y = 330;
    obj.push_back (credits_button);
    menuitem[2] = credits_button;

    GamePlayObj * exit_button = new GamePlayObj ("app0:/assets/images/main_menu/exit.png");
    exit_button->pos_x = 400;
    exit_button->pos_y = 420;
    obj.push_back (exit_button);
    menuitem[3] = exit_button;

    create_text_from_font("LemonWars", 250, 80, "app0:/assets/fonts/default_font.png", obj);


}

void Menu::MenuRun()
{

    while (!draw_frame(obj))
    {
     scanner2->Scan();
     navigate();


    }
    //deleting title screen objects and input scanner

    GPU_finish();
    free_textures(obj);
    delete scanner2;


    return;

    /*
    ActivatePlay();
      if (Scanner::start_pressed)
    {
        //assigning and calling a test method
        StartActiveMenuItem = MenuFuncPtr[MenuItem];

        (this->*StartActiveMenuItem) ();

    }
    */


}




void Menu::StartPlay()
{

}
void Menu::StartLoad()
{
}
void Menu::StartCredits()
{

}
void Menu::StartControls()
{

}

void Menu::StartExit()
{

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
void Menu::navigate()
{

    if (grid_toggle_timer.expired())
    {
    grid_toggle_timer.delay_mills(100);

    if (current == 0)
     {
         if (Scanner::up_pressed||
             Scanner::down_pressed||
             Scanner::left_pressed||
             Scanner::right_pressed)
         {
             current = 1;
             menuitem[current]->waved = 1;
         }

     }
     else if (Scanner::down_pressed)
     {
         if (current == 1 || current == 2 || current == 4)
         {
             menuitem[current]->waved = 0;
             current ++;
             menuitem[current]->waved = 1;
         }
         else if (current == 5)
         {
             menuitem[current]->waved = 0;
             current -= 2;
             menuitem[current]->waved = 1;
         }
     }
     else if (Scanner::up_pressed)
     {
         if (current == 3 || current == 2 || current == 5)
         {
             menuitem[current]->waved = 0;
             current --;
             menuitem[current]->waved = 1;
         }


     }
     else if (Scanner::right_pressed)
     {
         if (current == 1 || current == 2)
         {
             menuitem[current]->waved = 0;
             current += 3;
             menuitem[current]->waved = 1;
         }
           else if (current == 3)
           {
             menuitem[current]->waved = 0;
             current += 2;
             menuitem[current]->waved = 1;
           }
     }
     else if (Scanner::left_pressed)
     {
         if (current == 4 || current == 5)
         {
             menuitem[current]->waved = 0;
             current -= 3;
             menuitem[current]->waved = 1;
         }
     }
    }
}
Menu::~Menu()
{
    //dtor
}
