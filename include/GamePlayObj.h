#ifndef GAMEPLAYOBJ_H
#define GAMEPLAYOBJ_H

#include <Entity.h>


class GamePlayObj : public Entity
{
    public:
        GamePlayObj();
        GamePlayObj(const char *filename);
        virtual ~GamePlayObj();
        //virtual void go_move();

        //for moving objects
        bool started;//if moving enabled
        int delta;// moving step

    protected:

    private:
};

#endif // GAMEPLAYOBJ_H
