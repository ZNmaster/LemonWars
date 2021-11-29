#include "Projectile.h"

Projectile::Projectile()
{
    //ctor
}

Projectile::Projectile(vita2d_texture *im, LevelMap *mymap, std::vector<Entity*> *objvec, int x0, int y0, float rad)
                       : Character::Character(im, 2, 3, x0, y0)
{
   level = mymap;
   obj = objvec;

   speed = 200;

   angle = rad;
   sprite_coord_calc(0);
}

Projectile::Projectile(const char *filename, LevelMap *mymap, std::vector<Entity*> *objvec, int x0, int y0, float rad)
                       : Character::Character(filename, 2, 3, x0, y0)
{
   level = mymap;
   obj = objvec;

   speed = 200;

   angle = rad;
   sprite_coord_calc(0);
}

void Projectile::go_move()
{
   calc_screen_pos();
}

Projectile::~Projectile()
{
    //dtor
    image = nullptr;
}
