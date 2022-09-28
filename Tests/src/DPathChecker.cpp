#include "DPathChecker.h"

#include <iostream>





DPathChecker::DPathChecker() : DPathChecker::DPathChecker(0, 0, 1, 1)
{
    //ctor
}

DPathChecker::DPathChecker(int coordX_start, int coordY_start, int coordX_end, int coordY_end)
                       : ArraySearch::ArraySearch (coordX_start, coordY_start, coordX_end, coordY_end)
{

    p_x = 0;
    p_y = 0;

    //first level
    int level = 1;

    game = Game("Level1_1.png", "level1.dat");;

    ent1 = game.layers.layer0_obj[2];

    lev = dynamic_cast<LevelMap*>(ent1);

     if (level)
    {
        target1 = Target(lev);

    }

    else
    {
         std::cout << "Warning:  could not find the map " << std::endl;
    }

    //ctor
}

bool DPathChecker::run_tests(int x, int y)
{

   //forward direction

    lev->player_pos_x = p_x;
    lev->player_pos_y = p_y;
    bool a = target1.direct_path_available(x, y, 50);



    //backward direction
    lev->player_pos_x = x;
    lev->player_pos_y = y;
    bool b = target1.direct_path_available(p_x, p_y, 50);

    if (a != b)
    {
        std::cout << "Warning: forward and backward pathes are not equally available: from (" << p_x << ", " << p_y << ")"
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



DPathChecker::~DPathChecker()
{
    //dtor
}
