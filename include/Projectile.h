#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <MovObj.h>
#include <vector>
#include "LevelMap.h"
#include "Point_int.h"



class Projectile : public MovObj
{
    public:
        Projectile();

        /* !!!!!!!!!!!!!!!!!!!!! be careful with this constructor. For some reason GPU crashes if you pass the
                                 pointer of the texture to create an object. To avoid this you must to load the texture TWICE!!!!!!!!!!!!!*/
        Projectile(vita2d_texture *im, LevelMap *mymap, std::vector<Entity*> *objvec, int x0, int y0, float rad);


        Projectile(const char *filename, LevelMap *mymap, std::vector<Entity*> *objvec, int x0, int y0, float rad);

        void ( Projectile::*carry_on) ();

        void find_destination();
        void set_path();
        void fly();
        void explode();
        void finish();

        Timer explosion_timer;
        Pathfinder path;


        virtual void go_move();

        virtual ~Projectile();

    protected:

    private:
        std::vector<Entity*> *obj;

        void set_scene (LevelMap *mymap, std::vector<Entity*> *objvec, float rad);

        int dest_x, dest_y;

        int sprite_num;
};

#endif // PROJECTILE_H
