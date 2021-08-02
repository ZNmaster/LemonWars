#ifndef GAMEPLAYOBJ_H
#define GAMEPLAYOBJ_H

#include <Entity.h>


class GamePlayObj : public Entity
{
    public:
        GamePlayObj();
        GamePlayObj(char *filename);
        virtual ~GamePlayObj();
        //virtual void go_move();

    protected:

    private:
};

#endif // GAMEPLAYOBJ_H
