#include "Wallbuilder.h"
#include <iostream>

Wallbuilder::Wallbuilder()
{
    //ctor
    x_start [0] = 2;
    y_start [0] = 8;
    x_end [0] = 5;
    y_end [0] = 17;
}

Wallbuilder::~Wallbuilder()
{
    //dtor
}

void Wallbuilder::calc_ab (unsigned int wall_num)
{
 a [wall_num] = (y_end [wall_num] - y_start [wall_num]) / (x_end [wall_num]-x_start [wall_num]);
 b [wall_num] = y_end [wall_num] - a[wall_num] * x_end [wall_num];

 std::cout << "y= " << a[wall_num] << "x" << "+" << b[wall_num] << std::endl;
}
