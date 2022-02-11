#include "Wallbuilder.h"
#include <iostream>
#include <cmath>
#include <algorithm>

Wallbuilder::Wallbuilder()
{
    //ctor
    x_start [0] = 2;
    y_start [0] = 8;
    x_end [0] = 5;
    y_end [0] = 17;
}

Wallbuilder::Wallbuilder(int level)
{
    switch(level)
    {
    case 1 :
        x_start = {0, 0, 460, 340, 63, 63, 333, 63, 180, 180, 333, 333, 396, 396, 861, 399, 399, 339, 339, 339, 936, 936, 2220};
        y_start = {30, 290, 30, 290, 648, 648, 867, 900, 900, 1905, 867, 1083, 960, 960, 960, 1407, 1293, 1293, 1293, 1488, 960, 960, 960};
        x_end = {460, 340, 460, 340, 340, 63, 460, 180, 180, 2220, 333, 396, 396, 861, 861, 861, 399, 399, 339, 936, 936, 2220, 2220};
        y_end = {30, 290, 867, 648, 648, 902, 867, 900, 1905, 1905, 1083, 1083, 1083, 960, 1407, 1407, 1407, 1293, 1488, 1488, 1488, 960, 1905};
        array_size = 33;
    break;

    case 2 :
        x_start = {0, 31, 31, 933, 32, 32, 0};
        y_start = {231, 27, 27, 27, 520, 341, 341};
        x_end = {31, 31, 933, 933, 933, 32, 32};
        y_end = {231, 231, 27, 520, 520, 520, 341};
        array_size = 7;
    break;


    default :
        x_start = {0};
        y_start = {0};
        x_end = {0};
        y_end = {0};
        array_size = 1;
    }
}

bool Wallbuilder::pos_valid(int x0, int y0, int radius)
{
    //b factor for vertical walls
    int b_vert = -2*y0;

    //b factor for horizontal walls
    int b_hor = -2*x0;

    //constant part of c for both vertical and horizontal walls
    int c_part_2 = x0*x0 + y0*y0 - radius*radius;

    for(unsigned int i = 0; i<array_size; i++)
    {
        if (x_start[i] == x_end[i])
        {
            int c = x_start[i]*x_start[i] - 2*x_start[i]*x0 + c_part_2;
            int disc = b_vert*b_vert - 4*c;
            if (disc>=0)
            {
                int y1 = (-b_vert + sqrt(disc))/2;
                int y2 = (-b_vert - sqrt(disc))/2;
                if(
                   //checking two intersection points
                   (y1>std::min(y_start[i], y_end[i]) && y1<std::max(y_start[i], y_end[i])) ||
                   (y2>std::min(y_start[i], y_end[i]) && y2<std::max(y_start[i], y_end[i]))
                   )
                {
                    return 0;
                }

            }

        }


        else if (y_start[i] == y_end[i])
        {
            int c = y_start[i]*y_start[i] - 2*y_start[i]*y0 + c_part_2;
            int disc = b_hor*b_hor - 4*c;

            if (disc>=0)
            {
                int x1 = (-b_hor + sqrt(disc))/2;
                int x2 = (-b_hor - sqrt(disc))/2;
                if(
                   //checking two intersection points
                   (x1>std::min(x_start[i], x_end[i]) && x1<std::max(x_start[i], x_end[i])) ||
                   (x2>std::min(x_start[i], x_end[i]) && x2<std::max(x_start[i], x_end[i]))
                   )
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

bool Wallbuilder::visible(int x1, int y1, int x2, int y2)
{
    return !intersection(x1, y1, x2, y2, 1);
}

bool Wallbuilder::intersected(int x1, int y1, int x2, int y2)
{
    return intersection(x1, y1, x2, y2, 0);
}

bool Wallbuilder::intersection(int x1, int y1, int x2, int y2, bool visibility_only)
{

    intersection_points.clear();

    //intersection point coordinates
    float y_intersec, x_intersec;


     AB = LineEq(x1, y1, x2, y2);

     for(unsigned int i = 0; i<array_size; i++)
     {
        Point_int p;

        //visibility line is vertical
        if (AB.vertical)
        {
            //horizontal walls
            if(y_start[i] == y_end[i])
            {
                if(y_start[i] >= std::min(AB.y_start, AB.y_end) && y_start[i] <= std::max(AB.y_start, AB.y_end) &&
                   AB.x_start >= std::min(x_start[i], x_end[i]) && AB.x_start <= std::max(x_start[i], x_end[i]))
                   {
                       if (visibility_only) return 1;
                       p.x = AB.x_start;
                       p.y = y_start[i];
                       intersection_points.push_back(p);
                   }
            }
        }
        //visibility line is horizontal
        else if (AB.horizontal)
        {
            if(x_start[i] == x_end[i])
            {
                   if(x_start[i] >= std::min(AB.x_start, AB.x_end) && x_start[i] <= std::max(AB.x_start, AB.x_end) &&
                   AB.y_start >= std::min(y_start[i], y_end[i]) && AB.y_start <= std::max(y_start[i], y_end[i]))
                   {
                       if (visibility_only) return 1;
                       p.x = x_start[i];
                       p.y = AB.y_start;
                       intersection_points.push_back(p);
                   }
            }
        }
        //other visibility line
        else
        {

        //vertical walls
        if (x_start[i] == x_end[i])
        {
            if(x_start[i] >= std::min(AB.x_start, AB.x_end) && x_start[i] <= std::max(AB.x_start, AB.x_end))
            {
                x_intersec = x_start[i];
                y_intersec = AB.a*x_intersec + AB.b;
                if (y_intersec >= std::min(y_start[i], y_end[i]) && y_intersec <= std::max(y_start[i], y_end[i]))
                {
                  if (visibility_only) return 1;
                  p.x = x_intersec;
                  p.y = y_intersec;
                  intersection_points.push_back(p);
                }
            }
        }

        //horizontal walls
        else if (y_start[i] == y_end[i])
        {

            if(y_start[i] >= std::min(AB.y_start, AB.y_end) && y_start[i] <= std::max(AB.y_start, AB.y_end))
            {
                y_intersec = y_start[i];
                x_intersec = (y_intersec - AB.b) / AB.a;

                if (x_intersec >= std::min(x_start[i], x_end[i]) && x_intersec <= std::max(x_start[i], x_end[i]))
                {
                    if (visibility_only) return 1;
                    p.x = x_intersec;
                    p.y = y_intersec;
                    intersection_points.push_back(p);
                }
            }
        }

           //other walls
           else
           {

           }
        }

      }

    //returns
    if(intersection_points.size() == 0)
    {
        return 0;
    }
    else

    {
        return 1;
    }
}



Wallbuilder::~Wallbuilder()
{
    //dtor
}

//LineEQ to be used here

/*void Wallbuilder::calc_ab (unsigned int wall_num)
{
 a [wall_num] = (y_end [wall_num] - y_start [wall_num]) / (x_end [wall_num]-x_start [wall_num]);
 b [wall_num] = y_end [wall_num] - a[wall_num] * x_end [wall_num];

 //std::cout << "y= " << a[wall_num] << "x" << "+" << b[wall_num] << std::endl;
}*/
