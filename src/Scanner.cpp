#include "Scanner.h"


Scanner::Scanner()
{
    //ctor
    ResetAll();

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

    return;
}
