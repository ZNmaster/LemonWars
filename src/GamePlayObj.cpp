#include "GamePlayObj.h"

GamePlayObj::GamePlayObj()
{
    //ctor

}

GamePlayObj::GamePlayObj(char *filename)
{
    image = vita2d_load_PNG_file(filename);
}

GamePlayObj::~GamePlayObj()
{
    //dtor
    vita2d_free_texture (image);
}

/*void GamePlayObj::go_move()
{
std::cout << "move of GPO" << std::endl;
}*/
