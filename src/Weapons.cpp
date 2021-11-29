#include "Weapons.h"
#include "Scanner.h"
#include "LineVec.h"
#include "Projectile.h"


Weapons::Weapons()
{
    //ctor
}

Weapons::Weapons(unsigned int type, LevelMap *mymap, std::vector<Entity*> *objvec)
{
    level = mymap;
    obj = objvec;

    charged = 1;

    //set fire timer
    fire_timer.delay_mills(10);

    charge_timer.delay_mills(10);


   switch(type)
    {
    //simple gun
    case 1 :
        default_player_sprite = 0;
        fire_player_sprite = 1;
        current_player_sprite = default_player_sprite;
        image = vita2d_load_PNG_file("app0:/assets/images/projectiles/bullet.png");

        {
            Point_float gun_end_point;
            gun_end_point.x = 49;
            gun_end_point.y = -8;

            LineVec fire_point(gun_end_point);

            gun_vector_len = fire_point.len;
            gun_vector_alpha = fire_point.angle;
        }


    break;

    case 2 :

    break;

    default :
        current_player_sprite = 0;
    }



}

unsigned int Weapons::act(unsigned int sprite_num, float alpha)

{
    player_alpha = alpha;

   if (Scanner::fire_pressed && charged)
        {
            charged = 0;
            fire_timer.delay_mills(50);
            charge_timer.delay_mills(500);
            fire();
        }

        if (sprite_num == fire_player_sprite)
        {
            if (fire_timer.expired())
            {
                current_player_sprite = default_player_sprite;
            }

        }

        if(charge_timer.expired() || !Scanner::fire_pressed)
        {
            charged = 1;
        }



   return current_player_sprite;
}

void Weapons::fire()
{
   current_player_sprite = fire_player_sprite;

   Point_int projectile_coords;

   Point_float start_point;

   start_point.x = (float)level->player_pos_x;
   start_point.y = (float)level->player_pos_y;

   LineVec gun_vector(start_point, gun_vector_len, gun_vector_alpha + player_alpha);

   start_point.x = gun_vector.x_end;
   start_point.y = gun_vector.y_end;

   LineVec projectile_vector(start_point, 5.5, player_alpha);

   projectile_coords.x = (int)projectile_vector.x_end;
   projectile_coords.y = (int)projectile_vector.y_end;

   if (image)
   {
      Projectile *bullet = new Projectile(image, projectile_coords, level, obj, player_alpha);
      obj->push_back(bullet);
   }

   return;

}

Weapons::~Weapons()
{
    //dtor
    if (image)
    {
        vita2d_free_texture (image);
    }
}
