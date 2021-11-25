#include "Menu.h"
#include "GamePlayObj.h"


Menu::Menu()
{

    //ctor
    GPU_init();

    //current menu item
    current = 0;

    //when creating a new menu item it is need to increment this counter
    menu_item_count=0;


    //creating menu objects

    GamePlayObj *background_1 = new GamePlayObj ("app0:/assets/images/main_menu/Background.png");
    obj.push_back (background_1);

    MenuItem *play_button = new MenuItem ("app0:/assets/images/main_menu/play.png");
    play_button->pos_x = 200;
    play_button->pos_y = 200;
    play_button->item_num = 1;
    obj.push_back (play_button);
    menuitem[play_button->item_num] = play_button;
    MenuFuncPtr [play_button->item_num] = &Menu::StartPlay;
    menu_item_count++;

    MenuItem *load_button = new MenuItem ("app0:/assets/images/main_menu/load.png");
    load_button->pos_x = 600;
    load_button->pos_y = 200;
    load_button->item_num = 4;
    obj.push_back (load_button);
    menuitem[load_button->item_num] = load_button;
    MenuFuncPtr [load_button->item_num] = &Menu::StartLoad;
    menu_item_count++;

    MenuItem *controls_button = new MenuItem ("app0:/assets/images/main_menu/controls.png");
    controls_button->pos_x = 600;
    controls_button->pos_y = 330;
    controls_button->item_num = 5;
    obj.push_back (controls_button);
    menuitem[controls_button->item_num] = controls_button;
    MenuFuncPtr [controls_button->item_num] = &Menu::StartCredits;
    menu_item_count++;

    MenuItem *credits_button = new MenuItem ("app0:/assets/images/main_menu/credits.png");
    credits_button->pos_x = 200;
    credits_button->pos_y = 330;
    credits_button->item_num = 2;
    obj.push_back (credits_button);
    menuitem[credits_button->item_num] = credits_button;
    MenuFuncPtr [credits_button->item_num] = &Menu::StartCredits;
    menu_item_count++;

    MenuItem *exit_button = new MenuItem ("app0:/assets/images/main_menu/exit.png");
    exit_button->pos_x = 400;
    exit_button->pos_y = 420;
    exit_button->item_num = 3;
    obj.push_back (exit_button);
    menuitem[exit_button->item_num] = exit_button;
    MenuFuncPtr [exit_button->item_num] = &Menu::StartExit;
    menu_item_count++;

    create_text_from_font("LemonWars", 250, 80, "app0:/assets/fonts/default_font.png", obj);

}

void Menu::MenuRun()
{

    scanner = new Scanner;
    scanner->stick_nav = 1;
    scanner->Scan();

    while (!draw_frame(obj))
    {

     if (scanner)
     {
         scanner->Scan();
     }

     //entering active menu item
     if (Scanner::go_pressed && current >0)
     {
         menuitem[current]->started = 1;

         delete scanner;
         scanner = nullptr;
     }

     //touch screen scan
     if (Scanner::front_touch)
     {

         //checking all menu items
         for (int i=1; i<=menu_item_count; i++)
         {
             //checking the coordinates
             if (scanner->front_touch_point_x > menuitem[i]->pos_x && scanner->front_touch_point_x < (menuitem[i]->pos_x + menuitem[i]->loaded_image_res_x) &&
                 scanner->front_touch_point_y > menuitem[i]->pos_y && scanner->front_touch_point_y < (menuitem[i]->pos_y + menuitem[i]->loaded_image_res_y))
                 {
                    menuitem[current]->waved = 0;
                    current = menuitem[i]->item_num;
                    menuitem[current]->waved = 1;
                    menuitem[current]->started = 1;
                    delete scanner;
                    scanner = nullptr;
                    break;
                 }
         }


     }

     //navigation with buttons
     navigate();

    }

    //deleting title screen objects and input scanner

    GPU_finish();
    free_textures(obj);

    if (scanner)
    {
        delete scanner;
    }

        StartActiveMenuItem = MenuFuncPtr[current];

        (this->*StartActiveMenuItem) ();

        return;


}


void Menu::StartPlay()
{
  level1_1();
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
   MenuItemO = 0;
}
void Menu::ActivateLoad()
{
   MenuItemO = 1;
}
void Menu::ActivateCredits()
{
   MenuItemO = 2;
}
void Menu::ActivateControls()
{
   MenuItemO = 3;
}

void Menu::navigate()
{

    if (navigate_timer.expired())
    {
    navigate_timer.delay_mills(100);

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
         else if(current == 3)
           {
             menuitem[current]->waved = 0;
             current --;
             menuitem[current]->waved = 1;
           }
     }
    }
}
Menu::~Menu()
{
    free_textures(obj);
    //dtor
}
