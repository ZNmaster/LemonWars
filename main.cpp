#include <iostream>

#include "Init.ini"

#include "Wallbuilder.h"
#include "VisChecker.h"


int main()
{
  VisChecker myarea (200, 1090, 820, 1280);

  myarea.check(396, 800);

  for (unsigned int i = 0; i < myarea.visible_point_x.size(); i++)
  {
      std::cout << "Point (" << myarea.visible_point_x[i] << ", " << myarea.visible_point_y[i] << ") is visible" << std::endl;
  }




  return 0;



}

