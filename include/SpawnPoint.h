#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H

#include <Entity.h>
#include <vector>


class SpawnPoint : public Entity
{
    public:
        SpawnPoint();
        SpawnPoint(int x, int y, std::vector<Entity *> *obj);
        void go_move();

        virtual ~SpawnPoint();


    protected:

    private:
};

#endif // SPAWNPOINT_H
