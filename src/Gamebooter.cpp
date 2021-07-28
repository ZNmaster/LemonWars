#include "Gamebooter.h"
#include <iostream>
#include "Menu.h"

Gamebooter::Gamebooter()
{
    //ctor
    std::cout << "Loading assets..." << std::endl;


}

void Gamebooter::Play()
{
    std::cout << "Loading menu..." << std::endl;
    Menu MainMenu;
}


Gamebooter::~Gamebooter()
{
    //dtor
    std::cout << "Exiting game..." << std::endl;
}
