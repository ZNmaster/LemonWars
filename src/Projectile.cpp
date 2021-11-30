#include "Projectile.h"

Projectile::Projectile()
{
    //ctor
}

Projectile::Projectile(vita2d_texture *im, LevelMap *mymap, std::vector<Entity*> *objvec, int x0, int y0, float rad)
                       : MovObj::MovObj(im, 2, 3, x0, y0)
{
   set_scene(mymap, objvec, rad);
}

Projectile::Projectile(const char *filename, LevelMap *mymap, std::vector<Entity*> *objvec, int x0, int y0, float rad)
                       : MovObj::MovObj(filename, 2, 3, x0, y0)
{
   set_scene(mymap, objvec, rad);
}

void Projectile::set_scene (LevelMap *mymap, std::vector<Entity*> *objvec, float rad)
{
   level = mymap;
   obj = objvec;
   speed = 500;
   angle = rad;
   sprite_coord_calc(0);
   calc_screen_pos();
}

void Projectile::go_move()
{
   calc_screen_pos();
}

Projectile::~Projectile()
{
    //dtor

    //uncomment if you want to pass the loaded image to MovObj constructor to ensure it is not deleted in GamePlayObj
    //image = nullptr;
}
