#include <iostream>
#include "MemoryBuilder.h"
#include "Scanner.h"
#include <iostream>
#include "LineVec.h"
#include "Point_int.h"



bool Scanner::up_pressed = 0;
bool Scanner::down_pressed = 0;
bool Scanner::left_pressed = 0;
bool Scanner::right_pressed = 0;
bool Scanner::start_pressed = 0;


int main()
{
            float player_alpha = 3.14/2;

            Point_float gun_end_point;
            gun_end_point.x = 49;
            gun_end_point.y = -8;

            LineVec fire_point(gun_end_point);

            float gun_vector_len = fire_point.len;
            float gun_vector_alpha = fire_point.angle;

            std::cout << gun_vector_len << std::endl;
            std::cout << gun_vector_alpha << std::endl;

             Point_int projectile_coords;

   Point_float start_point;

   int x =100;
   int y =100;

   start_point.x = (float)(x);
   start_point.y = (float)(y);

   LineVec gun_vector(start_point, gun_vector_len, gun_vector_alpha + player_alpha);

   std::cout << gun_vector.x_start << std::endl;
   std::cout << gun_vector.x_start << std::endl;
   std::cout << gun_vector.sin_a << std::endl;


   start_point.x = gun_vector.x_end;
   start_point.y = gun_vector.y_end;


   std::cout << "gun points to " << start_point.x << " ; " << start_point.y << std::endl;
   //std::cout << start_point.y << std::endl;


   LineVec projectile_vector(start_point, 5.5, player_alpha);

   projectile_coords.x = (int)(projectile_vector.x_end);
   projectile_coords.y = (int)(projectile_vector.y_end);


   std::cout << "Projectile coords: " << projectile_coords.x << " ; " << projectile_coords.y << std::endl;
   //std::cout << projectile_coords.y << std::endl;

  return 0;



}

