#include "LineVec.h"
#include <cmath>


LineVec::LineVec()
{
    //ctor
}

LineVec::LineVec(Point_float end_point)
                 : Line::Line(0, 0, end_point.x, end_point.y)
{
    angle = calcangle(sin_a, cos_a);
}

LineVec::LineVec(Point_float start_point, Point_float end_point)
                 : Line::Line(start_point.x, start_point.y, end_point.x,  end_point.y)
{
    angle = calcangle(sin_a, cos_a);
}

LineVec::LineVec(float length, float rad)
{

    x_start = 0;
    y_start = 0;
    calcline(length, rad);

}

LineVec::LineVec(Point_float start_point, float length, float rad)
{

    x_start = start_point.x;
    y_start = start_point.y;
    calcline(length, rad);

}


void LineVec::calcline(float length, float rad)
{
    len = length;
    angle = rad;
    sin_a = sin(angle);
    cos_a = cos(angle);


    delta_x = len * cos_a;
    delta_y = len * sin_a;
    x_end = x_start + delta_x;
    y_end = y_start + delta_y;
}

/*void LineVec::calcangle()
{
        angle = asin(sin_a);
        if (cos_a < 0)
        {
            angle = pi - angle;
        }
}*/

LineVec::~LineVec()
{
    //dtor
}
