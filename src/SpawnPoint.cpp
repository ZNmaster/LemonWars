#include "SpawnPoint.h"
#include "Common_Lemon.h"

SpawnPoint::SpawnPoint()
{
    //ctor
}

SpawnPoint::SpawnPoint(int x, int y, std::vector<Entity *> *obj)
{
    activated = 0;
    spawned = 0;

    abs_x = x;
    abs_y = y;
    objvector = obj;

    //image = nullptr;
    image = vita2d_create_empty_texture(1, 1);


    enemy_spawn_timer = new Timer();
    number_of_enemies = 12;


}

void SpawnPoint::set_levelmap(LevelMap *mymap)
{
    level = mymap;
}

void SpawnPoint::go_move()
{

    if(spawned)
    {
        return;
    }

    if (!activated)
    {
        if (distance(level->player_pos_x, level->player_pos_y) < 200)
        {
            activated = 1;
        }
    }

    if (activated && !spawned)
    {
        if (enemy_spawn_timer->expired())
        {
            Common_Lemon *testlem = new Common_Lemon(level, "app0:/assets/images/characters/npc/lemon_sprite.png",
                                                 2, 2, abs_x, abs_y);
            objvector->push_back(testlem);

            enemy_spawn_timer->delay_mills(900);

            number_of_enemies--;
        }

        if(number_of_enemies == 0)
        {
            spawned = 1;
            delete enemy_spawn_timer;
        }
    }
}

SpawnPoint::~SpawnPoint()
{
    //dtor
    //vita2d_free_texture (image);
}
