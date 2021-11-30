#ifndef MOVOBJ_H
#define MOVOBJ_H

#include <Sprite.h>
#include "LevelMap.h"
#include <Timer.h>


class MovObj : public Sprite
{
    public:
        MovObj();
        MovObj(const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);


        /* !!!!!!!!!!!!!!!!!!!!! be careful with this constructor. For some reason GPU crashes if you pass the
                                 pointer of the texture to create an object. To avoid this you must to load the texture TWICE!!!!!!!!!!!!!*/
        MovObj(vita2d_texture *im, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);



        virtual ~MovObj();

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

#endif // MOVOBJ_H
