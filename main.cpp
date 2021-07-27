#include <iostream>
#include "Gamebooter.h"
#include "Scanner.h"
#include "Wallbuilder.h"

bool Scanner::up_pressed = 0;
bool Scanner::down_pressed = 0;
bool Scanner::left_pressed = 0;
bool Scanner::right_pressed = 0;
bool Scanner::start_pressed = 0;

int main()
{

    Scanner::start_pressed = 1;
    Gamebooter Game;

    Game.Play();

    return 0;
}
