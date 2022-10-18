#include "Menu.h"
#include "Game.h"


void Menu::level1_1()
{

    std::string filename = Get_Level_Filename();
    Game level1_1(filename.c_str());
    bool gameover = level1_1.StartGame();


}

std::string Menu::Get_Level_Filename()
{
    return "app0:/assets/memory/level1003.dat";
}
