#include "Menu.h"
#include "Gamebooter.h"
#include "Scanner.h"
#include "Wallbuilder.h"


bool Scanner::up_pressed = 0;
bool Scanner::down_pressed = 0;
bool Scanner::left_pressed = 0;
bool Scanner::right_pressed = 0;
bool Scanner::start_pressed = 0;
bool Scanner::select_pressed = 0;
bool Scanner::go_pressed = 0;

int main()
{

    //Scanner::start_pressed = 1;
    //Menu MainMenu;
    //MainMenu.MenuRun();

    Gamebooter Game1;

    Game1.Play();

    return 0;
}
