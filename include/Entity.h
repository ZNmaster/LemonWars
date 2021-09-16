#ifndef ENTITY_H
#define ENTITY_H
#include <vita2d.h>


class Entity
{
    public:
        Entity();
        Entity(int a);

        virtual ~Entity();

        const int vitares_x = 960;
        const int vitares_y = 544;

        //abs_x, abs_y - absolute position on the map
        // pos_x, pos_y - position on the screen
        // part_x, part_y - position of the sprite to display


        int abs_x, abs_y, pos_x, pos_y, part_x, part_y;


        //size of the sprite to display
        int res_of_sprites_x;
        int res_of_sprites_y;

        //scaling factor (k)
        int k_x, k_y;

        //calculate the distance between the object and a point on the map
        float distance(int x1, int y1);

        //call each frame to recalculate position of the object
        virtual void go_move();

        //image texture
        vita2d_texture *image;

        //for the objects which can stop drawing
        bool terminated;

        //for the objects which will be displayed partially (e.g. spritessheets)
        bool partial;

        bool scaled;

        bool waved;


    protected:

    private:
};

#endif // ENTITY_H
