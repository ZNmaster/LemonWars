#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H

#include <Entity.h>
#include "LevelMap.h"
#include "Timer.h"

#include <vector>


class SpawnPoint : public Entity
{
    public:
        SpawnPoint();
        SpawnPoint(int x, int y, std::vector<Entity *> *obj);
        void go_move();
        void set_levelmap(LevelMap *mymap);
        Timer *enemy_spawn_timer;
        //int number_of_enemies;


        virtual ~SpawnPoint();



    protected:

    private:
        LevelMap *level;
        bool activated, spawned;
        std::vector<Entity *> *objvector;

};

#endif // SPAWNPOINT_H
