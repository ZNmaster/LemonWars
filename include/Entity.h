#ifndef ENTITY_H
#define ENTITY_H
#include <vita2d.h>


class Entity
{
    public:
        Entity();
        Entity(int a);
        virtual ~Entity();
        int abs_x, abs_y, pos_x, pos_y;
        float distance(int x1, int y1);
        virtual void go_move();
        vita2d_texture *image;
        bool terminated;

    protected:

    private:
};

#endif // ENTITY_H
