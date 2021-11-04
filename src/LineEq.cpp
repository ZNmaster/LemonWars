#include "LineEq.h"

LineEq::LineEq()
{

}

LineEq::LineEq(float x1, float y1, float x2,  float y2)
        : Line::Line(x1, y1, x2, y2)
{
    calcfactors();
    //ctor
}

void LineEq::calcfactors ()
{
    if (!vertical)
    {
        a = delta_y/delta_x;
        b = y_end - (a*x_end);
    }
}
LineEq::~LineEq()
{
    //dtor
}
