#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "LevelMap.h"
#include "Timer.h"


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
        //fire delay
        Timer fire_timer, charge_timer;

        //charged weapon flag
        bool charged;

        void fire();
        void calc_stick_rad(float x, float y);
        float sin_a, cos_a;

        //sprite num in the spritesheet
        unsigned int position;
};

#endif // PLAYER_H
