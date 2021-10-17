#include "Pathfinder.h"
#include <cmath>
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
    current_x = x1;
    current_y = y1;
    target_x = x2;
    target_y = y2;

    delta_x = x2 - x1;
    delta_y = y2 - y1;

    if (delta_x == 0 && delta_y == 0)
    {
        arrived = 1;
        return;
    }

    float len = sqrt(delta_x*delta_x + delta_y*delta_y);

    sin_a = delta_y/len;
    cos_a = delta_x/len;

    //checking the angle of the path
    if (abs (delta_x) > abs (delta_y))
    {
        calc_coord = &Pathfinder::go_low;
    }
    else
    {
        calc_coord = &Pathfinder::go_high;
    }


    if (x2 == x1)
    {
        vertical = 1;
    }

    else if (y2 == y1)
    {
        horizontal = 1;
    }

    else
    {

        calc_path(x1, y1, x2, y2);
    }

}

void Pathfinder::reset()
{
    current_x = 0;
    current_y = 0;
    target_x = 0;
    target_y = 0;

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

   //if (delta_y < 1 && delta_y > 0) delta_y = 1;
   //if (delta_y < 0 && delta_y > -1) delta_y = -1;

   current_y += delta_y;


   if (sin_a > 0)
   {
      if (current_y >= target_y)
      {

          arrival();
          return;
      }

   }
   else
   {
       if (current_y <= target_y)
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
   //if (delta_x < 1 && delta_x > 0) delta_x = 1;
   //if (delta_x < 0 && delta_x > -1) delta_x = -1;

   current_x += delta_x;

   if (cos_a > 0)
   {
      if (current_x >= target_x)
      {

          arrival();
          return;
      }
   }
   else
   {
       if (current_x <= target_x)
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
    current_y = target_y;
    current_x = target_x;
}

Pathfinder::~Pathfinder()
{
    //dtor
}
