#include "SpawnPoint.h"
#include "Common_Lemon.h"

SpawnPoint::SpawnPoint()
{
    //ctor
}

SpawnPoint::SpawnPoint(int x, int y, std::vector<Entity *> *obj)
{
    abs_x = x;
    abs_y = y;
    objvector = obj;


    image = vita2d_create_empty_texture(1, 1);
    activated = 0;
    spawned = 0;
}

void SpawnPoint::set_levelmap(LevelMap *mymap)
{
    level = mymap;
}

void SpawnPoint::go_move()
{
    if (!activated)
    {
        if (distance(level->player_pos_x, level->player_pos_y) < 200)
        {
            activated = 1;
        }
    }

    if (activated && !spawned)
    {
        Common_Lemon *testlem = new Common_Lemon(level, "app0:/assets/images/characters/npc/lemon_sprite.png",
                                                 2, 2, abs_x, abs_y);
        objvector->push_back(testlem);
        spawned = 1;
    }
}

SpawnPoint::~SpawnPoint()
{
    //dtor
}
