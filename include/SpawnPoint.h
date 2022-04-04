#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H

#include <vector>
#include <vita2d.h>

#include "Entity.h"
#include "LevelMap.h"
#include "Timer.h"





class SpawnPoint : public Entity
{
    public:
        SpawnPoint();
        SpawnPoint(int x, int y, std::vector<Entity *> *obj);

        virtual void go_move();

        void set_levelmap(LevelMap *mymap);

        //delay between spawns
        Timer *enemy_spawn_timer;

        //image of the enemy
        vita2d_texture *enemy1;

        //lemon juice splash of the ennemy
        vita2d_texture *blood1;

        //number of enemies to spawn
        int number_of_enemies;

        static unsigned int number_of_spawn_points;


        virtual ~SpawnPoint();



    protected:

    private:
        LevelMap *level;

        //when the player spotted the spawn point is activated, then when all the enemies spawned it becomes spawned
        bool activated, spawned;

        //vector of spawned enemies
        std::vector<Entity *> *objvector;

        float visibility_distance;

};

#endif // SPAWNPOINT_H
