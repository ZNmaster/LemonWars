#ifndef MOVOBJ_H
#define MOVOBJ_H

#include "Sprite.h"
#include "LevelMap.h"
#include "Timer.h"
#include "Pathfinder.h"
#include "NearestPoint.h"


class MovObj : public Sprite, public NearestPoint
{
    public:
        MovObj();
        MovObj(const char *filename, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);


        /* !!!!!!!!!!!!!!!!!!!!! be careful with this constructor. For some reason GPU crashes if you pass the
                                 pointer of the texture to create an object. To avoid this you must to load the texture TWICE!!!!!!!!!!!!!*/
        MovObj(vita2d_texture *im, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);

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

        void finish();

        //calculates path between 2 nav points
        Pathfinder path;


        Timer explosion_timer;
        int sprite_num;

        virtual void explode();


        virtual ~MovObj();


    protected:

    private:

        //constructor delegee - sets initial position and starts the mov_timer
        void set_pos(LevelMap *mymap, int x0, int y0);
};

#endif // MOVOBJ_H
