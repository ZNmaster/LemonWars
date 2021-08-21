#include "LevelMap.h"

LevelMap::LevelMap()
{
    //ctor
}

LevelMap::LevelMap(const char *filename)
          : GamePlayObj::GamePlayObj(filename)
{
    partial = 1;
    part_x = 0;
    part_y = 0;
    res_of_sprites_x = vitares_x;
    res_of_sprites_y = vitares_y;
    set_map_res();
}

bool LevelMap::valid_pos(int abs_x, int abs_y, int radius)
{
    //check if the map position is valid
    if ((abs_x - radius) < 0 || (abs_y - radius) < 0)
    {
        return 0;
    }
    if ((abs_x + radius) > mapres_x || (abs_y + radius) > mapres_y)
    {
        return 0;
    }
    return 1;

}

void LevelMap::set_map_res()
{
    mapres_x = 2250;
    mapres_y = 1940;
}

void LevelMap::go_move()
{

}

LevelMap::~LevelMap()
{
    //dtor
}
