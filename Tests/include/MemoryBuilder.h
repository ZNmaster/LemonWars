#ifndef MEMORYBUILDER_H
#define MEMORYBUILDER_H
#include "LevelData.h"
#include "Entity.h"


class MemoryBuilder
{
    public:
        MemoryBuilder();
        float nav_dist(int16_t point_1, int16_t point_2);
        ~MemoryBuilder();

        LevelData level1;
        Entity calc_dist;

    protected:

    private:
};

#endif // MEMORYBUILDER_H
