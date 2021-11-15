#include "Scanner.h"
#include <string.h>


Scanner::Scanner()
{
    //ctor
    ResetAll();
    memset(&pad, 0, sizeof(pad));

    hyst = 15;
    stick_zero = 127;
    stick_zero_lx = 127;
    stick_zero_ly = 127;
    stick_zero_rx = 127;
    stick_zero_ry = 127;

    sceTouchSetSamplingState(SCE_TOUCH_PORT_FRONT, SCE_TOUCH_SAMPLING_STATE_START);
    sceTouchEnableTouchForce(SCE_TOUCH_PORT_FRONT);
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);



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

    sceCtrlPeekBufferPositive(0, &pad, 1);
    sceTouchPeek(0, &touch, 1);

    count_pressed = 0;

    Point_int stick = read_stick(pad.lx, pad.ly);

    calc_stick_relative(stick, lstick_x, lstick_y, left_stick_moved);

    int old_hyst = hyst;

    stick = read_stick(pad.rx, pad.ry);


    calc_stick_relative(stick, rstick_x, rstick_y, right_stick_moved);


    if (count_pressed == 0)
    {
        if (pad.buttons & SCE_CTRL_START)
            {
                 start_pressed = 1;count_pressed++;
            }

        if (pad.buttons & SCE_CTRL_SELECT)
            {
                 select_pressed = 1;
            }
        if (pad.buttons & SCE_CTRL_UP)
            {
                 up_pressed = 1;
                 count_pressed++;
            }
        if (pad.buttons & SCE_CTRL_DOWN)
            {
                 down_pressed = 1;
                 count_pressed++;
            }
        if (pad.buttons & SCE_CTRL_RIGHT)
            {
                 right_pressed = 1;
                 count_pressed++;
            }
        if (pad.buttons & SCE_CTRL_LEFT)
            {
                 left_pressed = 1;
                 count_pressed++;
            }
        if (pad.buttons & SCE_CTRL_CROSS)
            {
                 go_pressed = 1;
            }
    }

    if (count_pressed > 1)
    {
        pad_multiple_pressed = 1;
    }


        if (touch.reportNum)
        {
            front_touch = 1;
            //save touch point x ; y of the touchscreen and adjust to display resolution
            front_touch_point_x = touch.report[0].x/2;
            front_touch_point_y = touch.report[0].y/2;
        }


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
    sceTouchDisableTouchForce(SCE_TOUCH_PORT_FRONT);
    sceTouchSetSamplingState(SCE_TOUCH_PORT_FRONT, SCE_TOUCH_SAMPLING_STATE_STOP);

    stick_nav = 0;
    ResetAll();

}
