#include "Pathfinder.h"

Pathfinder::Pathfinder()
{
    //ctor
}

Pathfinder::Pathfinder(int x1, int y1, int x2, int y2)
{
    reinit(x1, y1, x2, y2);
}

void Pathfinder::reinit(int x1, int y1, int x2, int y2)
{
    reset();

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


    current_x = x1;
    current_y = y1;
    target_x = x2;
    target_y = y2;
}

void Pathfinder::reset()
{
    current_x = 0;
    current_y = 0;
    target_x = 0;
    target_y = 0;

    vertical = 0;
    horizontal = 0;
}

void Pathfinder::calc_path(int x1, int y1, int x2, int y2)
{
    a_x = (y2 - y1)/(x2 - x1);
    b_x = y2 - a_x*x2;

    a_y = (x2 - x1)/(y2 - y1);
    b_y = x2 - a_y*y2;
}


Pathfinder::~Pathfinder()
{
    //dtor
}
