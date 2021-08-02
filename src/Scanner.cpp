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

}
void Scanner::ResetAll()
{

    Scanner::up_pressed = 0;
    Scanner::down_pressed = 0;
    Scanner::left_pressed = 0;
    Scanner::right_pressed = 0;
    Scanner::start_pressed = 0;
    Scanner::select_pressed = 0;

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

}
