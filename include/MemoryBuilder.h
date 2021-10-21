#ifndef MEMORYBUILDER_H
#define MEMORYBUILDER_H
#include "Memory.h"
#include "Entity.h"


class MemoryBuilder
{
    public:
        MemoryBuilder();
        float nav_dist(int point_1, int point_2);
        ~MemoryBuilder();

        Memory level1;
        Entity calc_dist;

    protected:

    private:
};

#endif // MEMORYBUILDER_H
