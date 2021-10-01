#include <iostream>
#include "Pathfinder.h"
#include "Scanner.h"


bool Scanner::up_pressed = 0;
bool Scanner::down_pressed = 0;
bool Scanner::left_pressed = 0;
bool Scanner::right_pressed = 0;
bool Scanner::start_pressed = 0;

int main()
{
  Pathfinder path(56,43,2,41);

  while (!path.arrived)
  {
      std::cout << path.current_x << ", " << path.current_y << std::endl;
      path.move_by(3);
  }


  std::cout << path.current_x << ", " << path.current_y << std::endl;


  return 0;



}

