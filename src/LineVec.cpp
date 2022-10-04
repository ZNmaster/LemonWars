#include "LineVec.h"
#include "Geometry.h"

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

LineVec LineVec::opposite(LineVec a)
{
    EPoint_float start_point(a.x_end, a.y_end);
    EPoint_float end_point(a.x_start, a.y_start);

    return LineVec(start_point, end_point);
}

LineVec LineVec::operator +(LineVec b)
{
    EPoint_float start_point(x_start, y_start);

    float delta_x = b.x_end - b.x_start;
    float delta_y = b.y_end - b.y_start;

    Point_float end_point;
    end_point.x = x_end + delta_x;
    end_point.y = y_end + delta_y;

    LineVec result_vec(start_point, end_point);


    return result_vec;
}

LineVec LineVec::operator -(LineVec b)
{
    return *this + opposite(b);
}

LineVec LineVec::operator *(LineVec b)
{
    EPoint_float start_point(x_start, y_start);

    float length = len*b.len;
    float ang = angle + b.angle;

    return LineVec(start_point, length, ang);
}



LineVec::~LineVec()
{
    //dtor
}
