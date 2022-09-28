#include <iostream>
#include <array>

#include "Init.ini"

#include "Wallbuilder.h"
#include "VisChecker.h"
#include "DPathChecker.h"



int main()
{
  //rectangular area to check {x1, y2, x2, y2}
  std::array<int, 4> a = {200, 1090, 820, 1280};

  //point coordinates x, y
  std::array<int, 2> point = {400, 800};

  int number_of_tests = 4;


  for (int i = 0; i < number_of_tests; i++)
  {
     VisChecker myarea (a[0], a[1], a[2], a[3]);

     myarea.check(point[0], point[1]);

     for (unsigned int i = 0; i < myarea.visible_point_x.size(); i++)
      {
        std::cout << "Point (" << myarea.visible_point_x[i] << ", " << myarea.visible_point_y[i] << ") is visible" << std::endl;
      }
  }

for (int i = 0; i < number_of_tests; i++)
  {
     DPathChecker myarea (a[0], a[1], a[2], a[3]);

     myarea.check(point[0], point[1]);

     for (unsigned int i = 0; i < myarea.visible_point_x.size(); i++)
      {
        std::cout << "Point (" << myarea.visible_point_x[i] << ", " << myarea.visible_point_y[i] << ") is pathable" << std::endl;
      }
  }


  return 0;



}

