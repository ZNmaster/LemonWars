#include <iostream>
#include <array>
#include "Scanner.h"
#include "Wallbuilder.h"

bool Scanner::up_pressed = 0;
bool Scanner::down_pressed = 0;
bool Scanner::left_pressed = 0;
bool Scanner::right_pressed = 0;
bool Scanner::start_pressed = 0;

int main()
{
  Wallbuilder LevelWall (1);


  if (LevelWall.pos_valid(100, 500, 50))
  {
      std::cout << "Position is valid" << std::endl;
  }
  else {std::cout << "Position is NOT valid" << std::endl;}




  return 0;

 /*
 //Table of pointers
 Entity *ptr[5];

 Title *ent1 = new Title;

 ptr[0] = ent1;


 float a = ptr[0]->distance(3,4);

 std::cout << "The distance is: " << a << std::endl;
 ptr[0]->go_move();


 delete ent1;
*/









 //Scanner::start_pressed = 1;


 /*Timer timer1;
 timer1.start();
 timer1.delay_mills(500);

 std::string mystring = "10 ";
 int a = 10;
 float b = 42.769;
 double c = 3456.98675;

 //int f = mystring + a;

 std::cout << mystring << a << b << c << std::endl;
 std::cout << &mystring << &a << &b << &c << std::endl;


 while (!timer1.expired())
 {
     timer1.stop();

 //std::cout << << std::endl;

 std::cout << timer1.duration_int << std::endl;
 std::cout << timer1.duration_float << std::endl;
 }*/



}
