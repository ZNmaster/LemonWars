#include "Angle.h"

#include <cmath>

Angle::Angle()
{
    //ctor
}

float Angle::calcangle(float sin, float cos)
{
        float alpha = asin(sin);
        if (cos < 0)
        {
            alpha = pi - alpha;
        }
        return alpha;
}

Angle::~Angle()
{
    //dtor
}
