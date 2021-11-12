#include "Scanner.h"
#include <string.h>


Scanner::Scanner()
{
    //ctor
    ResetAll();
    memset(&pad, 0, sizeof(pad));

    sceTouchSetSamplingState(SCE_TOUCH_PORT_FRONT, SCE_TOUCH_SAMPLING_STATE_START);
    sceTouchEnableTouchForce(SCE_TOUCH_PORT_FRONT);

    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);

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
    Scanner::left_stick_moved = 0;
    Scanner::right_stick_moved = 0;
    Scanner::front_touch = 0;

    return;
}

void Scanner::Scan()
{
    ResetAll();

    sceCtrlPeekBufferPositive(0, &pad, 1);
    sceTouchPeek(0, &touch, 1);

        if (pad.buttons & SCE_CTRL_START)
            {
                 start_pressed = 1;
            }

        if (pad.buttons & SCE_CTRL_SELECT)
            {
                 select_pressed = 1;
            }
        if (pad.buttons & SCE_CTRL_UP)
            {
                 up_pressed = 1;
            }
        if (pad.buttons & SCE_CTRL_DOWN)
            {
                 down_pressed = 1;
            }
        if (pad.buttons & SCE_CTRL_RIGHT)
            {
                 right_pressed = 1;
            }
        if (pad.buttons & SCE_CTRL_LEFT)
            {
                 left_pressed = 1;
            }
        if (pad.buttons & SCE_CTRL_CROSS)
            {
                 go_pressed = 1;
            }

        if (touch.reportNum)
        {
            front_touch = 1;
            //save touch point x ; y of the touchscreen and adjust to display resolution
            front_touch_point.x = touch.report[0].x/2;
            front_touch_point.y = touch.report[0].y/2;
        }


}

Scanner::~Scanner()
{
    //dtor
    sceTouchDisableTouchForce(SCE_TOUCH_PORT_FRONT);
    sceTouchSetSamplingState(SCE_TOUCH_PORT_FRONT, SCE_TOUCH_SAMPLING_STATE_STOP);

    ResetAll();

}
