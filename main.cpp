#include <iostream>
#include "MemoryBuilder.h"
#include "Scanner.h"
#include <iostream>


bool Scanner::up_pressed = 0;
bool Scanner::down_pressed = 0;
bool Scanner::left_pressed = 0;
bool Scanner::right_pressed = 0;
bool Scanner::start_pressed = 0;



int main()
{


  MemoryBuilder test1;

  for (int a = 0; a < test1.level1.number_of_points; a++)
  {
      for (int b = 0; b < test1.level1.number_of_points; b++)
      {
          std::cout << test1.level1.distance[b][a] << " ";
      }
      std::cout << std::endl;
  }
  //checking path
  /*
  Pathfinder path(500,500,50,50);


  while (!path.arrived)
  {
      std::cout << path.current_x << ", " << path.current_y << std::endl;
      path.move_by(9);
  }


  std::cout << path.current_x << ", " << path.current_y << std::endl;*/


  return 0;



}

