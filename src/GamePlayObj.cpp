#include "GamePlayObj.h"

GamePlayObj::GamePlayObj()
{
    //ctor

}

GamePlayObj::GamePlayObj(const char *filename)
{
    image = vita2d_load_PNG_file(filename);
    terminated = 0;
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
