#include "MenuItem.h"

MenuItem::MenuItem(const char *filename)
                : GamePlayObj::GamePlayObj(filename)
{
    delta = 1;
    k_x = 200;
    k_y = 100;
    //ctor
}

void MenuItem::go_move()
{
   if (started)
    {
          pos_x += delta;
          pos_y += delta;
          k_x -= 2*delta;
          k_y -= delta;

            if (delta > 40)
           {
              terminated = 1;
           }
        delta ++;

    }
}

void MenuItem::layer_moved(std::vector<Entity *> &target_lay)
{
    move_to_bottom = 0;
    move_to_top = 0;
}

MenuItem::~MenuItem()
{
    //dtor
}
