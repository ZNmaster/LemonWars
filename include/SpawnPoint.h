#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H

#include <vector>

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
        Timer *enemy_spawn_timer;

        //number of enemies to spawn
        int number_of_enemies;




        virtual ~SpawnPoint();



    protected:

    private:
        LevelMap *level;
        bool activated, spawned;
        std::vector<Entity *> *objvector;

};

#endif // SPAWNPOINT_H
