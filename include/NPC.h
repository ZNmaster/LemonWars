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
        virtual ~NPC();

    protected:

    private:
};

#endif // NPC_H
