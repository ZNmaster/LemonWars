#ifndef PLAYER_H
#define PLAYER_H

#include <Character.h>
#include <LevelMap.h>


class Player : public Character
{
    public:
        float sqrt2 = 1.414213562;

        Player();

        Player(LevelMap *mymap, const char *filename,
               int num_horizontal_sprites, int num_vertical_sprites,
               int x0, int y0);


        void go_move();

        virtual ~Player();


    protected:

    private:

        void calc_stick_rad(float x, float y);
        float sin_a, cos_a;
};

#endif // PLAYER_H
