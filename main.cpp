#include <iostream>

#include "Init.ini"

#include "Wallbuilder.h"
#include "ArraySearch.h"


int main()
{

  ArraySearch arr(0, 4, 2000, 5000);
  return 0;

  Wallbuilder walls (1);

  std::array<int, 100> x_start;
  std::array<int, 100> y_start;
  std::array<int, 100> x_end;
  std::array<int, 100> y_end;

  x_end = {400, 1011, 228};
  y_end = {775, 1150, 177};

  x_start = {290,  0, 400};
  y_start = {1150, 0, 495};

  int i = 0;
  int j = 0;

  std::cout << walls.visible(x_start[i], y_start[i], x_end[j], y_end[j]) << std::endl;
  std::cout << walls.visible(x_end[i], y_end[i], x_start[j], y_start[j]) << std::endl;
  return 0;



}

