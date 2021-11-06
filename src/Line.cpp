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
     return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
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

    if (x2 == x1)
    {
        vertical = 1;
    }

    else if (y2 == y1)
    {
        horizontal = 1;
    }
}

Line::~Line()
{
    //dtor
}
