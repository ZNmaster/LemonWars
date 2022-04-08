#include "Projectile.h"
#include "LineVec.h"
#include "Point_float.h"
#include "Gamebooter.h"
//#include "NPC.h"
#include <thread>

Projectile::Projectile()
{
    //ctor
    hitcheck_running = 0;
}

Projectile::Projectile(vita2d_texture *im, LevelMap *mymap, std::vector<Entity*> *objvec, int x0, int y0, float rad)
                       : MovObj::MovObj(im, mymap, 2, 3, x0, y0)
{
   set_scene(objvec, rad);
}

Projectile::Projectile(const char *filename, LevelMap *mymap, std::vector<Entity*> *objvec, int x0, int y0, float rad)
                       : MovObj::MovObj(filename, mymap, 2, 3, x0, y0)
{
   set_scene(objvec, rad);
}

void Projectile::set_scene (std::vector<Entity*> *objvec, float rad)
{

   //reset hitcheck running flag
   hitcheck_running = 0;

   obj = objvec;
   speed = 500;
   angle = rad;
   set_sprite(0);
   sprite_change_delay = 80;
   last_sprite = 5;
   calc_screen_pos();

   if (!level->levelwalls.visible(abs_x, abs_y, level->player_pos_x, level->player_pos_y))
   {
       set_sprite(1);
       carry_on = &Projectile::start_animation;
       Gamebooter::soundengine->play_projectile_explosion_sound();
       explosion_timer.delay_mills(50);
   }
   else
   {
       carry_on = &Projectile::find_destination;
   }

   sprite_num = 1;

   /*std::thread loading_explosion_sound(&Projectile::load_explosion_sound, this);
   if (loading_explosion_sound.joinable())
   {
       loading_explosion_sound.detach();
   }*/
}

void Projectile::find_destination()
{

    Point_float start_point;
    start_point.x = abs_x;
    start_point.y = abs_y;
    LineVec destination(start_point, 5000, angle);

    dest_x = destination.x_end;
    dest_y = destination.y_end;
    if (level->levelwalls.intersected(abs_x, abs_y, dest_x, dest_y))
    {
         int point_index = find_nearest_to(abs_x, abs_y, level->levelwalls.intersection_points);

         Point_int dest;
         dest = level->levelwalls.intersection_points[point_index];
         dest_x = dest.x;
         dest_y = dest.y;
    }
    carry_on = &Projectile::set_path;

}

void Projectile::set_path()
{
    path = Pathfinder(abs_x, abs_y, dest_x, dest_y);
    move_timer.start();
    set_sprite(1);
    carry_on = &Projectile::fly;
}

void Projectile::fly()
{
    std::thread t1(&Projectile::hitcheck, this);
    if (t1.joinable())
    {
        t1.detach();
    }


    move_delta = get_move_delta();
    path.move_by(move_delta);

    abs_x = path.current_x;
    abs_y = path.current_y;

    if (path.arrived)
    {
        explosion_timer.delay_mills(50);
        carry_on = &Projectile::start_animation;
        Gamebooter::soundengine->play_projectile_explosion_sound();
    }
}

void Projectile::stop_animation()
{
    carry_on = &Projectile::finish;
}

void Projectile::go_move()
{
   (this->*carry_on) ();
   calc_screen_pos();
}

void Projectile::hitcheck()
{
    for(auto it = obj->begin() + 1; it < obj->end(); it++)
    {

        if(distance((*it)->abs_x, (*it)->abs_y) < 35)
        {
            if((*it)->enemy && !(*it)->move_it)
            {

                    (*it)->hit(1000, angle, abs_x, abs_y);
                    dead = 1;
                    carry_on = &Projectile::finish;
            }

        }
    }
}

Projectile::~Projectile()
{
    //dtor

        //wait until the threads finish the job

    while (hitcheck_running)
    {
        std::this_thread::sleep_for (std::chrono::milliseconds(10));
    }

}
