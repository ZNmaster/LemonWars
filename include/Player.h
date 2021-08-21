#ifndef PLAYER_H
#define PLAYER_H

#include <Character.h>
#include <LevelMap.h>


class Player : public Character
{
    public:
        Player();
        Player(LevelMap *mymap, const char *filename, int res_x, int res_y, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);
        void go_move();

        virtual ~Player();
        LevelMap *level;
    protected:

    private:
};

#endif // PLAYER_H
