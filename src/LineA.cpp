#include "LineA.h"

LineA::LineA()
{
    vertical = 0;
    horizontal = 0;
    x_start = 0;
    y_start = 0;
    x_end = 0;
    y_end = 0;
    intersection_known = 0;
    //ctor
}

LineA::LineA(float x1, float y1, float x2,  float y2)
             : LineEq::LineEq(x1, y1, x2, y2)
{

    if (horizontal)
    {
       A1 = 0;
       B1 = 1;
       C1 = y1;
    }

    else if (vertical)
    {
       A1 = 1;
       B1 = 0;
       C1 = x1;
    }

    else calcABC();

    intersection_known = 0;
    //ctor
}

void LineA::calcABC()
{
        A1 = -a;
        B1 = 1;
        C1 = b;
}

LineA LineA::normal(float x1, float y1)
{

    if (vertical)
    {
        //return horizontal line passing via (x1, y1)
        return LineA(x1, y1, x1+100, y1);
    }
    else if (horizontal)
    {
        //return vertical line passing via (x1, y1)
        return LineA(x1, y1, x1, y1+100);
    }

    else
    {
        //calculating and returning normal line y=ax+b from | y - y1 = (-1/a)*(x - x1) or y = (-1/a)*x + b_new
        float a_new = -1/a;
        float b_new = a_new*x1 + y1;

        // calc f(x1+100)

        float x2 = x1 + 100;

        float y2 = a_new*x2 + b_new;

        return LineA (x1, y1, x2, y2);

    }

}

LineA::~LineA()
{
    //dtor
}
