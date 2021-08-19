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
}

LevelMap::~LevelMap()
{
    //dtor
}
