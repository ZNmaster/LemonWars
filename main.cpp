#include <iostream>
#include "RNG.h"
#include "Scanner.h"


bool Scanner::up_pressed = 0;
bool Scanner::down_pressed = 0;
bool Scanner::left_pressed = 0;
bool Scanner::right_pressed = 0;
bool Scanner::start_pressed = 0;

int main()
{
    RNG rnd;


        std::cout << std::endl;


    for(int i = 0; i < 30; i++)
    {

      int randnum = rnd.int_random(100, 110);
      std::cout << randnum << std::endl;
    }





  return 0;










}

