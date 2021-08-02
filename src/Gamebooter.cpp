#include "Gamebooter.h"
#include <iostream>
#include "Menu.h"
#include "Scanner.h"

Gamebooter::Gamebooter()
{
    //ctor

    std::cout << "Loading assets..." << std::endl;


}

void Gamebooter::Play()
{
    std::cout << "Loading menu..." << std::endl;
    Scanner scanner1;
    Menu MainMenu;
    MainMenu.MenuRun();
}


Gamebooter::~Gamebooter()
{
    //dtor
    std::cout << "Exiting game..." << std::endl;
}
