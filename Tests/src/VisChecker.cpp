#include "VisChecker.h"

#include <iostream>



VisChecker::VisChecker() : VisChecker::VisChecker(0, 0, 1, 1)
{
    //ctor
}

VisChecker::VisChecker(int coordX_start, int coordY_start, int coordX_end, int coordY_end)
                       : ArraySearch::ArraySearch (coordX_start, coordY_start, coordX_end, coordY_end)
{

    p_x = 0;
    p_y = 0;

    //first level
    int level = 1;

    walls = Wallbuilder(level);
    //ctor
}

bool VisChecker::run_tests(int x, int y)
{
    //forward direction
    bool a = walls.visible(p_x, p_y, x, y);

    //backward direction
    bool b = walls.visible(x, y, p_x, p_y);

    if (a != b)
    {
        std::cout << "Warning: forward and backward visibilities are not equal: from (" << p_x << ", " << p_y << ")"
                  <<" to (" << x << ", " << y << ") is " << a << std::endl;

        std::cout << "from (" << x << ", " << y << ")" <<" to (" << p_x << ", " << p_y << ") is " << b << std::endl;
    }

    bool result = a || b;

    if (result)
    {
       visible_point_x.push_back(x);
       visible_point_y.push_back(y);
    }

    return result;

}



VisChecker::~VisChecker()
{
    //dtor
}
