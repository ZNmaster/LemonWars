#ifndef DPATHCHECKER_H
#define DPATHCHECKER_H

#include "ArraySearch.h"
#include "Game.h"
#include "Target.h"



class DPathChecker : public ArraySearch
{
    public:
        DPathChecker();
        DPathChecker(int coordX_start, int coordY_start, int coordX_end, int coordY_end);

        virtual ~DPathChecker();

        virtual bool run_tests(int x, int y);


    protected:

    private:
        Game *game;
        Entity *ent1;
        LevelMap *lev;
        Target target1;

        //Wallbuilder walls;
};

#endif // DPATHCHECKER_H
