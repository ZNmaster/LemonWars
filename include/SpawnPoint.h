#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H

#include <Entity.h>
#include "LevelMap.h"

#include <vector>


class SpawnPoint : public Entity
{
    public:
        SpawnPoint();
        SpawnPoint(int x, int y, std::vector<Entity *> *obj);
        void go_move();
        void set_levelmap(LevelMap *mymap);

        virtual ~SpawnPoint();


    protected:

    private:
        LevelMap *level;
        bool activated, spawned;
        std::vector<Entity *> *objvector;
};

#endif // SPAWNPOINT_H
