#include "Scanner.h"
#include <string.h>


Scanner::Scanner()
{
    //ctor
    ResetAll();

    hyst = 15;
    stick_zero = 127;
    stick_zero_lx = 127;
    stick_zero_ly = 127;
    stick_zero_rx = 127;
    stick_zero_ry = 127;




}

Point_int Scanner::read_stick(unsigned int x, unsigned int y)
{
    Point_int read;

    if (x > (stick_zero - hyst) && x < (stick_zero + hyst))
    {
        x = stick_zero;
    }

    if (y > (stick_zero - hyst) && y < (stick_zero + hyst))
    {
        y = stick_zero;
    }

    read.x = x;
    read.y = y;

    return read;
}


void Scanner::ResetAll()
{

    Scanner::up_pressed = 0;
    Scanner::down_pressed = 0;
    Scanner::left_pressed = 0;
    Scanner::right_pressed = 0;
    Scanner::start_pressed = 0;
    Scanner::select_pressed = 0;
    Scanner::go_pressed = 0;
    //Scanner::stick_nav = 0;
    Scanner::fire_pressed = 0;
    Scanner::pad_multiple_pressed = 0;
    Scanner::left_stick_moved = 0;
    Scanner::right_stick_moved = 0;
    Scanner::front_touch = 0;

    //reset stick coordinates
    Scanner::lstick_x = 0;
    Scanner::lstick_y = 0;
    Scanner::rstick_x = 0;
    Scanner::rstick_y = 0;

    return;
}

void Scanner::Scan()
{
    ResetAll();


    count_pressed = 0;



    int old_hyst = hyst;


}

void Scanner::calc_stick_relative(Point_int stick, float &stick_x, float &stick_y, bool &stick_moved)
{
    unsigned int pad_treshold = 20;

    stick_x = ((float)stick.x - (float)stick_zero)/(float)stick_zero;
    stick_y = ((float)stick.y - (float)stick_zero)/(float)stick_zero;


    if (stick.x > stick_zero)
    {
        stick_moved = 1;

        if (stick_nav && (stick.x > (2*stick_zero-pad_treshold)))
        {
            right_pressed = 1;
            count_pressed++;
        }

    }

    else if (stick.x < stick_zero)
    {
        stick_moved = 1;
        if (stick_nav && stick.x < pad_treshold)
        {
            left_pressed = 1;
            count_pressed++;
        }
    }

    if (stick.y > stick_zero)
    {
        stick_moved = 1;
        if (stick_nav && (stick.y > (2*stick_zero-pad_treshold)))
        {
            down_pressed = 1;
            count_pressed++;
        }

    }

    if (stick.y < stick_zero)
    {
        stick_moved = 1;
        if (stick_nav && stick.y < pad_treshold)
        {
            up_pressed = 1;
            count_pressed++;
        }
    }

}

Scanner::~Scanner()
{
    //dtor

    stick_nav = 0;
    ResetAll();

}
