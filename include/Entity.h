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

        //const float pi = 3.1415926;

        //abs_x, abs_y - absolute position on the map
        // pos_x, pos_y - position on the screen
        // part_x, part_y - position of the sprite to display


        float abs_x, abs_y;
        int pos_x, pos_y, part_x, part_y;


        //rotation angle in radians
        float angle;

        //size of the sprite to display
        int res_of_sprites_x;
        int res_of_sprites_y;

        //scaling factor (k)
        int k_x, k_y;

        //calculate the distance between the object and a point on the map
        float distance(int x1, int y1);
        float distance(int x1, int y1, int x2, int y2);

        virtual void hit(int hitpoints, float projectile_angle, int x, int y);

        //radius of the Character
        int radius;

        //call each frame to recalculate position of the object
        virtual void go_move();

        //image texture
        vita2d_texture *image;

        //for the objects which can stop drawing
        bool terminated;

        //for the objects which will be displayed partially (e.g. spritessheets)
        bool partial;

        //the image to display should be scaled
        bool scaled;


        //waved effect flag
        bool waved;

        //for projectiles to distinguish the enemies
        bool enemy;

        //for the objects to be deleted from the rendering vector
        bool dead;

        //flag to tell if we need to move the entity from one layer to another
        bool move_it;


    protected:

    private:
};

#endif // ENTITY_H
