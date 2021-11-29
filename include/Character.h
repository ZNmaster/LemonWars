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
        Character(vita2d_texture *im, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);



        virtual ~Character();

        //pointer to level map
        LevelMap *level;

        //moving speed in pixels per second
        float speed;

        //timer to calculate delta in pixels
        Timer move_timer;

        //delta in pixels
        float move_delta;

        int new_abs_x,
            new_abs_y;

        float get_move_delta();

        //calculates position on the screen based on abs_x and abs_y
        void calc_screen_pos();


    protected:

    private:
        void set_pos(int x0, int y0);
};

#endif // CHARACTER_H
