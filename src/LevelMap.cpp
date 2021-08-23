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


    map_min_x = 0;
    map_min_y = 0;
    map_max_x = mapres_x - vitares_x;
    map_max_y = mapres_y - vitares_y;

    //to render only visibble part of the map
    res_of_sprites_x = vitares_x;
    res_of_sprites_y = vitares_y;


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

/*void LevelMap::set_map_res()
{
    mapres_x = 2250;
    mapres_y = 1940;
}*/

void LevelMap::go_move()
{
    part_x = player_pos_x - vitares_x/2;
    part_y = player_pos_y - vitares_y/2;

    if (part_x < map_min_x)
    {
        part_x = map_min_x;
    }
    else if  (part_x > map_max_x)
    {
        part_x = map_max_x;
    }
    if (part_y < map_min_y)
    {
        part_y = map_min_y;
    }
    else if (part_y > map_max_y)
    {
        part_y = map_max_y;
    }
}


LevelMap::~LevelMap()
{
    //dtor
}
