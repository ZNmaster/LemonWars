#ifndef PLAYER_H
#define PLAYER_H

#include "MovObj.h"
#include "LevelMap.h"
#include "Timer.h"
#include "Weapons.h"


class Player : public MovObj
{
    public:
        float sqrt2 = 1.414213562;

        Player();

        Player(LevelMap *mymap, std::vector<Entity*> *objvec, const char *filename,
               int num_horizontal_sprites, int num_vertical_sprites,
               int x0, int y0);



        Weapons gun;

        void go_move();

        virtual ~Player();


    protected:

    private:


        void calc_stick_rad(float x, float y);
        float sin_a, cos_a;

        //sprite num in the spritesheet
        unsigned int position = 0;
};

#endif // PLAYER_H
