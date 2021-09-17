#ifndef COMMON_LEMON_H
#define COMMON_LEMON_H

#include <NPC.h>


class Common_Lemon : public NPC
{
    public:
        Common_Lemon();
        Common_Lemon(LevelMap *mymap, const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);
        virtual ~Common_Lemon();
        void go_move();

    protected:

    private:
};

#endif // COMMON_LEMON_H
