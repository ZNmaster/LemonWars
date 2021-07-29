#include <iostream>
#include <chrono>
#include "Scanner.h"
#include "Timer.h"

bool Scanner::up_pressed = 0;
bool Scanner::down_pressed = 0;
bool Scanner::left_pressed = 0;
bool Scanner::right_pressed = 0;
bool Scanner::start_pressed = 0;

int main()
{
 Scanner::start_pressed = 1;







 Timer timer1;
 timer1.start();

 std::string mystring = "10 ";
 int a = 10;
 float b = 42.769;
 double c = 3456.98675;

 //int f = mystring + a;

 std::cout << mystring << a << b << c << std::endl;
 std::cout << &mystring << &a << &b << &c << std::endl;


 timer1.stop();

 //std::cout << << std::endl;

 std::cout << timer1.duration_int << std::endl;
 std::cout << timer1.duration_float << std::endl;
}
