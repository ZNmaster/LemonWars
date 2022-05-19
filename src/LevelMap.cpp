#include "LevelMap.h"
#include <fstream>

LevelMap::LevelMap()
{
    //ctor
    number_of_enemies_spawned = 0;
}

LevelMap::LevelMap(const char *MapFilename, const char *MemFilename)
          : GamePlayObj::GamePlayObj(MapFilename)
{

    mapres_x = loaded_image_res_x;
    mapres_y = loaded_image_res_y;

    std::fstream myFile2;
    myFile2.open(MemFilename, std::ios::in | std::ios::binary);

    myFile2.read((char *)&levelmem, sizeof(MemoryAI));

    myFile2.close();

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

    levelwalls = Wallbuilder{1};

    bodycount = 0;
    killstreak = 0;
    number_of_enemies_spawned = 0;

    killstreak_timer.delay_mills(1000);

    player_ptr = nullptr;
    player_pos_x = 0;
    player_pos_y = 0;

}

bool LevelMap::valid_pos(int abs_x, int abs_y, int radius)
{
    //check if the map position is valid
    touch_radius = radius - 10;

    if (!levelwalls.pos_valid(abs_x, abs_y, touch_radius))
    {
        return 0;
    }

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
