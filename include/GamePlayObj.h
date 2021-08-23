#ifndef GAMEPLAYOBJ_H
#define GAMEPLAYOBJ_H

#include <Entity.h>


class GamePlayObj : public Entity
{
    public:
        GamePlayObj();
        GamePlayObj(const char *filename);
        virtual ~GamePlayObj();

        //ressolution of the texture loaded
        int mapres_x,
            mapres_y;

            //used for spritesheet resolution
        int res_x,
            res_y;

        //for moving objects
        bool started;//if moving enabled
        int delta;// moving step

        void set_res();

    protected:

    private:
};

#endif // GAMEPLAYOBJ_H
