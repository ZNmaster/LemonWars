#include "Menu.h"
#include <iostream>
#include "Scanner.h"

Menu::Menu()
{
    //ctor
    std::cout << "Menu Loaded!" << std::endl;

    // assigning func pointers
    MenuFuncPtr [0] = &Menu::StartPlay;
    MenuFuncPtr [1] = &Menu::StartLoad;
    MenuFuncPtr [2] = &Menu::StartCredits;
    MenuFuncPtr [3] = &Menu::StartControls;
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
