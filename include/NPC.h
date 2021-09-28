#ifndef NPC_H
#define NPC_H

#include <Character.h>
#include "LevelMap.h"


class NPC : public Character
{
    public:
        NPC();
        NPC(LevelMap *mymap, const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);

        //for y=ax+b
        float a_x, b_x;

        //for x=ay+b
        float a_y, b_y;

        void calc_path_func(int x1, int y1, int x2, int y2);

        virtual ~NPC();

    protected:

    private:
};

#endif // NPC_H
