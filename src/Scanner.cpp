#include "Scanner.h"
#include <string.h>


Scanner::Scanner()
{
    //ctor
    ResetAll();
    memset(&pad, 0, sizeof(pad));

}

Scanner::~Scanner()
{
    //dtor
    ResetAll();

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

    return;
}

void Scanner::Scan()
{
    ResetAll();

    sceCtrlPeekBufferPositive(0, &pad, 1);

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

}
