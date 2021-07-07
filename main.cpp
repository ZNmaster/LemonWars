#include <iostream>
#include "Gamebooter.h"
#include "Scanner.h"

bool Scanner::up_pressed = 0;
bool Scanner::down_pressed = 0;
bool Scanner::left_pressed = 0;
bool Scanner::right_pressed = 0;
bool Scanner::start_pressed = 0;

int main()
{

    Scanner::start_pressed = 1;
    Gamebooter Game;

    Gamebooter *Game2 = new Gamebooter;

    std::cout << "Hello world!" << std::endl;
    Game.Play();
    std::cout << "Pointer to game2 is " << Game2 << std::endl;

    Game2->Play();

    delete Game2;


    return 0;
}
