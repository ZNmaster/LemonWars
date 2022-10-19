#include "Navigator.h"
#include "LevelMap.h"
#include <array>
#include <iostream>
#include <fstream>
#include <cstring>

Navigator::Navigator()
{

            //nav points

            std::int16_t number_of_points = 53;

            std::array<std::int16_t, 150> coord_x;
            std::array<std::int16_t, 150> coord_y;

  coord_x = {65, 110, 230, 260, 260, 260, 260, 260, 260, 400, 400, 400, 495, 495, 495, 630,
             630, 630, 630, 630, 790, 790, 790, 1010, 1010, 1010, 1010, 1010, 1260, 1260, 1260, 1260,
             1260, 1440, 1440, 1440, 1440, 1440, 1700, 1700, 1700, 1700, 1700, 1940, 1940, 1940, 1940,
             1940, 2100, 2100, 2100, 2100, 2100};

  coord_y = {170, 783, 170, 783, 1015, 1225, 1419, 1608, 1815, 170, 402, 783, 1060, 1225,
             1330, 1060, 1225, 1330, 1608, 1815, 1060, 1225, 1330, 1060, 1225, 1419, 1608, 1815, 1060,
             1225, 1419, 1608, 1815, 1060, 1225, 1419, 1608, 1815, 1060, 1225, 1419, 1608, 1815, 1060,
             1225, 1419, 1608, 1815, 1060, 1225, 1419, 1608, 1815};

             for(std::int16_t i = 0; i < number_of_points; i++)
              {
                level1.coord_x[i] = coord_x[i];
                level1.coord_y[i] = coord_y[i];
              }
             level1.number_of_points = number_of_points;


             //walls
             static const unsigned int max_array_size = 70;
             std::uint16_t array_size;

             // walls coordinates
             std::array<std::int16_t, max_array_size> x_start;
             std::array<std::int16_t, max_array_size> y_start;
             std::array<std::int16_t, max_array_size> x_end;
             std::array<std::int16_t, max_array_size> y_end;

             x_start = {0, 0, 460, 340, 63, 63, 333, 63, 180, 180, 333, 333, 396, 396, 861, 399, 399, 339, 339, 339, 936, 936, 2220};
             y_start = {30, 290, 30, 290, 648, 648, 867, 900, 900, 1905, 867, 1083, 960, 960, 960, 1407, 1293, 1293, 1293, 1488, 960, 960, 960};
             x_end = {460, 340, 460, 340, 340, 63, 460, 180, 180, 2220, 333, 396, 396, 861, 861, 861, 399, 399, 339, 936, 936, 2220, 2220};
             y_end = {30, 290, 867, 648, 648, 902, 867, 900, 1905, 1905, 1083, 1083, 1083, 960, 1407, 1407, 1407, 1293, 1488, 1488, 1488, 960, 1905};
             array_size = 23;


             level1.number_of_walls = array_size;
             for(std::int16_t i = 0; i < array_size; i++)
             {
                 level1.wall_x_start[i] = x_start[i];
                 level1.wall_y_start[i] = y_start[i];
                 level1.wall_x_end[i] = x_end[i];
                 level1.wall_y_end[i] = y_end[i];
             }

             strncpy(level1.filename0,"app0:/assets/images/levels/1_1/Level1_1.png", 100);


    // saving file
    std::fstream myFile;
    myFile.open("testlevel.dat", std::ios::out | std::ios::binary);
    myFile.write((char *)&level1, sizeof(LevelData));
    myFile.close();

    //ctor
}

Navigator::Navigator(const char *LevelDataFilename)
{
    Load_Data(level1, LevelDataFilename);

    //ctor
}

bool Navigator::Create()
{
   LevelMap mymap(&level1);

   a.set_array(&level1);
   //a.show_array();
   a.fill_all(&level1.path, -1111);
   a.show_array();
   a.call_owner_and_fill(this, 656);

   //a.show_array(&level1.distance);
   a.show_array(&level1.path);


   return false;
}

void Navigator::Load_Data (LevelData &dat, const char *LevelDataFilename)
{
    //open level data filename
    std::fstream myFile2;
    myFile2.open(LevelDataFilename, std::ios::in | std::ios::binary);
    myFile2.read((char *)&dat, sizeof(LevelData));
    myFile2.close();
}

bool Navigator::approved (int to_, int from_)
{
    if (from_ == 0) return false;
    if (to_ % from_) return false;
    return true;
}

Navigator::~Navigator()
{
    //dtor
}
