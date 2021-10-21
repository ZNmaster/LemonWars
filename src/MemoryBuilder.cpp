#include "MemoryBuilder.h"
#include "Memory.h"
#include "Entity.h"
#include <array>
#include <iostream>
#include <fstream>

MemoryBuilder::MemoryBuilder()
{
    //ctor
  Memory level1;
  Entity calc_dist;

  int number_of_points = 53;

  std::array<int, 100> coord_x;
  std::array<int, 100> coord_y;
  //std::array<std::array<float, 100>, 100> distance;
  //std::array<std::array<int, 100>, 100> path;

  coord_x = {65, 110, 230, 230, 230, 230, 230, 230, 230, 400, 400, 400, 495, 495, 495, 630,
             630, 630, 630, 630, 790, 790, 790, 1010, 1010, 1010, 1010, 1010, 1260, 1260, 1260, 1260,
             1260, 1440, 1440, 1440, 1440, 1440, 1700, 1700, 1700, 1700, 1700, 1940, 1940, 1940, 1940,
             1940, 2100, 2100, 2100, 2100, 2100};

  coord_y = {170, 783, 170, 783, 1015, 1225, 1419, 1608, 1815, 170, 402, 783, 1060, 1225,
             1330, 1060, 1225, 1330, 1608, 1815, 1060, 1225, 1330, 1060, 1225, 1419, 1608, 1815, 1060,
             1225, 1419, 1608, 1815, 1060, 1225, 1419, 1608, 1815, 1060, 1225, 1419, 1608, 1815, 1060,
             1225, 1419, 1608, 1815, 1060, 1225, 1419, 1608, 1815};

  std::array<std::array<int, 100>, 100> path{

           //0
           std::array<int, 100>
           {
               -1, 11, -1, 11, 3, 3, 3, 3, 3, -1, 9, 9, 13, 5, 13, 13, 5, 13, 7, 7, 13, 5, 13, 26, 26,
               26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26,
               26, 7, 7
           },

           //1
           std::array<int, 100>
           {
               9, -1, 9, -1, 3, 3, 3, 3, 3, 11, 11, -1, 13, 5, 13, 13, 5, 13, 7, 7, 13, 5, 13, 26, 26,
               26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26,
               26, 7, 7
           },

           //2
           std::array<int, 100>
           {
               -1, 11, -1, 11, 3, 3, 3, 3, 3, -1, 9, 9, 13, 5, 13, 13, 5, 13, 7, 7, 13, 5, 13, 26, 26, 26,
               7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //3
           std::array<int, 100>
           {
               9, -1, 9, -1, -1, -1, -1, -1, -1, 11, 11, -1, 13, 5, 13, 13, 5, 13, 7, 7, 13, 5, 13, 26, 26, 26,
               7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //4
           std::array<int, 100>
           {
                9, 3, 9, -1, -1, -1, -1, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, 7, 7, 13, 5, 13, 26, 26, 26, 7,
                7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //5
           std::array<int, 100>
           {
               9, 3, 9, -1, -1, -1, -1, -1, -1, 11, 11, 3, 13, -1, 13, 13, -1, 13, 7, 7, 13, -1, 13, 26, 26, 26, 7,
               7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //6
           std::array<int, 100>
           {
               9, 3, 9, -1, -1, -1, -1, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, 7, 7, 13, 5, 13, 26, 26, 26, 7, 7,
               26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //7
           std::array<int, 100>
           {
               9, 3, 9, -1, -1, -1, -1, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, 26, 26, 26, -1, -1,
               26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1
           },

           //8
           std::array<int, 100>
           {
               9, 3, 9, -1, -1, -1, -1, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, 26, 26, 26, -1, -1,
               26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1
           },

           //9
           std::array<int, 100>
           {
               -1, 11, -1, 11, 3, 3, 3, 3, 3, -1, -1, -1, 13, 5, 13, 13, 5, 13, 7, 7, 13, 5, 13, 26, 26, 26, 7, 7, 26, 26,
               26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //10
           std::array<int, 100>
           {
               9, 11, 9, 11, 3, 3, 3, 3, 3, -1, -1, -1, 13, 5, 13, 13, 5, 13, 7, 7, 13, 5, 13, 26, 26, 26, 7, 7, 26, 26, 26, 7,
               7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //11
           std::array<int, 100>
           {
               9, -1, 9, -1, 3, 3, 3, 3, 3, -1, -1, -1, 13, 5, 13, 13, 5, 13, 7, 7, 13, 5, 13, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7,
               26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //12
           std::array<int, 100>
           {
               9, 3, 9, 5, 5, 13, 5, 5, 5, 11, 11, 3, -1, -1, -1, -1, -1, -1, 7, 7, -1, -1, -1, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7,
               26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //13
           std::array<int, 100>
           {
               9, 3, 9, 5, 5, -1, 5, 5, 5, 11, 11, 3, -1, -1, -1, -1, -1, -1, 7, 7, -1, -1, -1, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7,
               26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },


           //14,
           std::array<int, 100>
           {
           9, 3, 9, 5, 5, 13, 5, 5, 5, 11, 11, 3, -1, -1, -1, -1, -1, -1, 7, 7, -1, -1, -1, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //15,
           std::array<int, 100>
           {
           9, 3, 9, 5, 5, 13, 5, 5, 5, 11, 11, 3, -1, -1, -1, -1, -1, -1, 7, 7, -1, -1, -1, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //16,
           std::array<int, 100>
           {
           9, 3, 9, 5, 5, -1, 5, 5, 5, 11, 11, 3, -1, -1, -1, -1, -1, -1, 7, 7, -1, -1, -1, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //17,
           std::array<int, 100>
           {
           9, 3, 9, 5, 5, 13, 5, 5, 5, 11, 11, 3, -1, -1, -1, -1, -1, -1, 7, 7, -1, -1, -1, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //18,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1
           },

           //19,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1, 26, 26, 26, -1, -1
           },

           //20,
           std::array<int, 100>
           {
           9, 3, 9, 5, 5, 13, 5, 5, 5, 11, 11, 3, -1, -1, -1, -1, -1, -1, 7, 7, -1, -1, -1, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //21,
           std::array<int, 100>
           {
           9, 3, 9, 5, 5, -1, 5, 5, 5, 11, 11, 3, -1, -1, -1, -1, -1, -1, 7, 7, -1, -1, -1, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //22,
           std::array<int, 100>
           {
           9, 3, 9, 5, 5, 13, 5, 5, 5, 11, 11, 3, -1, -1, -1, -1, -1, -1, 7, 7, -1, -1, -1, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7, 26, 26, 26, 7, 7
           },

           //23,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //24,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //25,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //26,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //27,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //28,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //29,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //30,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //31,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //32,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //33,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },


           //34,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //35,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },


           //36,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },


           //37,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //38,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //39,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //40,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //41,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //42,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //43,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //44,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //45,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //46,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //47,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //48,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //49,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //50,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, 26, 26, 11, 11, 3, 13, 5, 13, 13, 5, 13, 26, 26, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //51,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },

           //52,
           std::array<int, 100>
           {
           9, 3, 9, 7, 7, 7, 7, -1, -1, 11, 11, 3, 13, 5, 13, 13, 5, 13, -1, -1, 13, 5, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
           },


         };


    for(int a = 0; a < number_of_points; a++)
    {
        for(int b = 0; b < number_of_points; b++)
        {

            if (path[a][b] < 0)
            {
                level1.distance[a][b] = calc_dist.distance(coord_x[a], coord_y[a], coord_x[b], coord_y[b]);
            }

            level1.path[a][b] = path[a][b];
            std::cout << path[a][b] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < number_of_points; i++)
    {
        level1.coord_x[i] = coord_x[i];
        level1.coord_y[i] = coord_y[i];
    }
    level1.number_of_points = number_of_points;

    std::fstream myFile;
    myFile.open("level1.dat", std::ios::out | std::ios::binary);
    myFile.write((char *)&level1, sizeof(Memory));
    myFile.close();



}

MemoryBuilder::~MemoryBuilder()
{
    //dtor
}
