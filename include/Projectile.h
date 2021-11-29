#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <Character.h>
#include "LevelMap.h"
#include "Point_int.h"



class Projectile : public Character
{
    public:
        Projectile();
        Projectile(vita2d_texture *im, Point_int coord, LevelMap *mymap, std::vector<Entity*> *objvec, float rad);
        virtual ~Projectile();
        virtual void go_move();

    protected:

    private:
};

#endif // PROJECTILE_H
