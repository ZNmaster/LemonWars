#include <iostream>
#include <array>

#include "Init.ini"

#include "Wallbuilder.h"
#include "VisChecker.h"
#include "DPathChecker.h"
#include "LineVec.h"
#include "Geometry.h"

void printlinevec(LineVec &v)
{
    std::cout << "Start: (" << v.x_start << ", "<< v.y_start << ") " << std::endl;
    std::cout << "End: (" << v.x_end << ", "<< v.y_end << ") " << std::endl;
    std::cout << "Angle: " <<  v.angle << std::endl;
}

void check_v()
{





    constexpr float right = Angle::pi/2;
    constexpr float left = -Angle::pi/2;

    //set start point of the line between the player and enemy
    Point_float start_p;
    start_p.x = 430;
    start_p.y = 825;

    //set end point of the line between the player and enemy
    Point_float end_p;
    end_p.x = 295;
    end_p.y = 994;

    //create vector between the player and enemy
    LineVec direct_line(start_p, end_p);
    float direct_angle = direct_line.angle;
    std::cout << "Direct line: " << std::endl;
    printlinevec(direct_line);



    //the vectors point to the beginnings of right and left visibility lines
    LineVec left_aux_vec(start_p, 50, direct_angle + left);
    std::cout << "left_aux_vec: " << std::endl;
    printlinevec(left_aux_vec);

    LineVec right_aux_vec(start_p, 50, direct_angle + right);
    std::cout << "right_aux_vec: " << std::endl;
    printlinevec(right_aux_vec);


    //the vectors point to the ends of right and left visibility lines
    LineVec left_aux_vec_end = direct_line + left_aux_vec;
    std::cout << "left_aux_vec 2: " << std::endl;
    printlinevec(left_aux_vec_end);


    LineVec right_aux_vec_end = direct_line + right_aux_vec;
    std::cout << "right_aux_vec 2: " << std::endl;
    printlinevec(right_aux_vec_end);
}

int main()
{

    /*
    EPoint_float a1 (4, 8);
    EPoint_float b1 (10, 17);

    LineVec ab(a1,b1);
    std::cout << "ab: " << std::endl;
    printlinevec(ab);

    EPoint_float d (10, 10);
    LineVec cd(d);
    std::cout << "cd: " << std::endl;
    printlinevec(cd);

    LineVec abcd = ab + cd;

    std::cout << "abcd: " << std::endl;
    printlinevec(abcd);
    //return 0;
    */


  //check_v();
  //return 0;


  //rectangular area to check {x1, y2, x2, y2}
  std::array<int, 4> a = {210, 777, 318, 1470};

  //point coordinates x, y
  std::array<int, 2> point = {400, 775};

  int number_of_tests = 1;


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

