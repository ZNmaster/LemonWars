#ifndef CHARACTER_H
#define CHARACTER_H

#include <Sprite.h>
#include "LevelMap.h"
#include <Timer.h>


class Character : public Sprite
{
    public:
        Character();
        Character(const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);

        virtual ~Character();

        //pointer to level map
        LevelMap *level;

        //moving speed in pixels per second
        int speed;

        //timer to calculate delta in pixels
        Timer move_timer;

        //delta in pixels
        int move_delta;

        //radius of the Character
        int radius;

        int new_abs_x,
            new_abs_y;

        int get_move_delta();


    protected:

    private:
};

#endif // CHARACTER_H
