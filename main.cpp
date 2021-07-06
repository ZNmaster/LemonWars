#include <iostream>
#include "Gamebooter.h"

int main()
{

    Gamebooter Game;

    Gamebooter *Game2 = new Gamebooter;

    std::cout << "Hello world!" << std::endl;
    Game.Play();
    std::cout << "Pointer to game2 is " << Game2 << std::endl;

    Game2->Play();

    delete Game2;

    return 0;
}
