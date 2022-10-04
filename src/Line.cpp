#include "Line.h"
#include <cmath>

Line::Line()
{
    vertical = 0;
    horizontal = 0;
}

Line::Line(float x1, float y1, float x2,  float y2)
{

    vertical = 0;
    horizontal = 0;
    calcline(x1, y1, x2, y2);

    //ctor
}

float Line::length(float dx, float dy)
{
    return sqrt(dx*dx + dy*dy);
}

float Line::length(float x1, float y1, float x2,  float y2)
{
     float a = x2-x1;
     float b = y2-y1;

     return sqrt(a*a + b*b);
}

void Line::calcline (float x1, float y1, float x2,  float y2)
{
    x_start = x1;
    y_start = y1;
    x_end = x2;
    y_end = y2;

    delta_x = x2 - x1;
    delta_y = y2 - y1;

    len = length(delta_x, delta_y);

    if (len)
    {
    sin_a = delta_y/len;
    cos_a = delta_x/len;
    }

    setVH();
}

void Line::setVH()
{
    if (x_end == x_start)
    {
        vertical = 1;
    }

    else if (y_end == y_start)
    {
        horizontal = 1;
    }
}

Line::~Line()
{
    //dtor
}
