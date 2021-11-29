#include "Projectile.h"

Projectile::Projectile()
{
    //ctor
}

Projectile::Projectile(vita2d_texture *im, Point_int coord, LevelMap *mymap, std::vector<Entity*> *objvec, float rad)
                       : Character::Character(im, 2, 3, coord.x, coord.y)
{
   speed = 200;

   angle = rad;
   sprite_coord_calc(0);
}

void Projectile::go_move()
{
   //calc_screen_pos();
}

Projectile::~Projectile()
{
    //dtor
    image = nullptr;
}
