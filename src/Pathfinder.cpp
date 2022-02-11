#include "Pathfinder.h"
#include <iostream>

Pathfinder::Pathfinder()
{
    //ctor
}

Pathfinder::Pathfinder(float x1, float y1, float x2, float y2)
{
    reinit(x1, y1, x2, y2);
}

void Pathfinder::reinit(float x1, float y1, float x2, float y2)
{
    reset();
    calcline(x1, y1, x2, y2);

    current_x = x1;
    current_y = y1;

    if (delta_x == 0 && delta_y == 0)
    {
        arrived = 1;
        return;
    }


    //checking the angle of the path
    if (abs (delta_x) > abs (delta_y))
    {
        calc_coord = &Pathfinder::go_low;
    }
    else
    {
        calc_coord = &Pathfinder::go_high;
    }

    if (!vertical && !horizontal)
    {
        calc_path(x1, y1, x2, y2);
    }

}

void Pathfinder::reset()
{
    current_x = 0;
    current_y = 0;
    x_end = 0;
    y_end = 0;

    vertical = 0;
    horizontal = 0;
    arrived = 0;
}

void Pathfinder::calc_path(float x1, float y1, float x2, float y2)
{
    a_x = (y2 - y1)/(x2 - x1);
    b_x = y2 - a_x*x2;

    a_y = (x2 - x1)/(y2 - y1);
    b_y = x2 - a_y*y2;

}

void Pathfinder::move_by(float distance)
{
   if (arrived) return;
   (this->*calc_coord)(distance);

}

void Pathfinder::go_high(float distance)
{
   delta_y = distance*sin_a;


   current_y += delta_y;


   if (sin_a > 0)
   {
      if (current_y >= y_end)
      {

          arrival();
          return;
      }

   }
   else
   {
       if (current_y <= y_end)
       {
           arrival();
           return;
       }
   }

   if (!vertical) current_x = a_y*current_y + b_y;
}

void Pathfinder::go_low(float distance)
{
   delta_x = distance*cos_a;

   current_x += delta_x;

   if (cos_a > 0)
   {
      if (current_x >= x_end)
      {

          arrival();
          return;
      }
   }
   else
   {
       if (current_x <= x_end)
       {
           arrival();
           return;
       }
   }

   if (!horizontal) current_y = a_x*current_x + b_x;
}

void Pathfinder::arrival()
{
    arrived = 1;
    current_y = y_end;
    current_x = x_end;
}

Pathfinder::~Pathfinder()
{
    //dtor
}
