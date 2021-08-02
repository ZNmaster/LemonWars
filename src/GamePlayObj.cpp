#include "GamePlayObj.h"
#include <iostream>

GamePlayObj::GamePlayObj()
{
    //ctor
    std::cout << "default constructor of GPO" << std::endl;
}

GamePlayObj::GamePlayObj(int a)
{
    //ctor
    std::cout << "int a constructor of GPO" << std::endl;
}

GamePlayObj::~GamePlayObj()
{
    //dtor
    std::cout << "destructor of GPO" << std::endl;
}

/*void GamePlayObj::go_move()
{
std::cout << "move of GPO" << std::endl;
}*/
