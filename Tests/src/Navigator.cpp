#include "Navigator.h"
#include "LevelMap.h"
#include <array>
#include <iostream>
#include <fstream>
#include <cstring>

Navigator::Navigator()
{

            //nav points

            static const std::uint16_t max_number_of_nav_points = 150;

            std::int16_t number_of_points = 53;

            std::array<std::int16_t, max_number_of_nav_points> coord_x;
            std::array<std::int16_t, max_number_of_nav_points> coord_y;

  coord_x = {65, 110, 230, 260, 260, 260, 260, 260, 260, 400, 400, 400, 495, 495, 495, 630,
             630, 630, 630, 630, 790, 790, 790, 1010, 1010, 1010, 1010, 1010, 1260, 1260, 1260, 1260,
             1260, 1440, 1440, 1440, 1440, 1440, 1700, 1700, 1700, 1700, 1700, 1940, 1940, 1940, 1940,
             1940, 2100, 2100, 2100, 2100, 2100};

  coord_y = {170, 783, 170, 783, 1015, 1225, 1419, 1608, 1815, 170, 402, 783, 1060, 1225,
             1330, 1060, 1225, 1330, 1608, 1815, 1060, 1225, 1330, 1060, 1225, 1419, 1608, 1815, 1060,
             1225, 1419, 1608, 1815, 1060, 1225, 1419, 1608, 1815, 1060, 1225, 1419, 1608, 1815, 1060,
             1225, 1419, 1608, 1815, 1060, 1225, 1419, 1608, 1815};

             for(std::uint16_t i = 0; i < max_number_of_nav_points; i++)
              {
                level1.coord_x[i] = coord_x[i];
                level1.coord_y[i] = coord_y[i];
              }
             level1.number_of_points = number_of_points;


             //walls
             static const unsigned int max_number_of_walls = 70;
             std::uint16_t number_of_walls;

             // walls coordinates
             std::array<std::int16_t, max_number_of_walls> x_start;
             std::array<std::int16_t, max_number_of_walls> y_start;
             std::array<std::int16_t, max_number_of_walls> x_end;
             std::array<std::int16_t, max_number_of_walls> y_end;

             x_start = {0, 0, 460, 340, 63, 63, 333, 63, 180, 180, 333, 333, 396, 396, 861, 399, 399, 339, 339, 339, 936, 936, 2220};
             y_start = {30, 290, 30, 290, 648, 648, 867, 900, 900, 1905, 867, 1083, 960, 960, 960, 1407, 1293, 1293, 1293, 1488, 960, 960, 960};
             x_end = {460, 340, 460, 340, 340, 63, 460, 180, 180, 2220, 333, 396, 396, 861, 861, 861, 399, 399, 339, 936, 936, 2220, 2220};
             y_end = {30, 290, 867, 648, 648, 902, 867, 900, 1905, 1905, 1083, 1083, 1083, 960, 1407, 1407, 1407, 1293, 1488, 1488, 1488, 960, 1905};
             number_of_walls = 23;


             //setting walls
             level1.number_of_walls = number_of_walls;
             for(std::uint16_t i = 0; i < max_number_of_walls; i++)
             {
                 level1.wall_x_start[i] = x_start[i];
                 level1.wall_y_start[i] = y_start[i];
                 level1.wall_x_end[i] = x_end[i];
                 level1.wall_y_end[i] = y_end[i];
             }

             //set path and distance to 0

             for(std::uint16_t a = 0; a < max_number_of_nav_points; a++)
                {
                  for(std::uint16_t b = 0; b < max_number_of_nav_points; b++)
                    {

                    level1.path[a][b] = 0;
                    level1.distance[a][b] = 0;

                    }
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
   copies.fill(-100);

   level = new LevelMap(&level1);
   target_to_chase = Target(level);

   a.set_array(&level1);

   a.fill_all(&level1.distance, 32000);

   a.fill_all(&level1.path, -1111);

   a.call_owner_and_fill(this, -1);

   Load_Data(level2, "level1.dat");
   a.compare(&level2);

   a.find_copies(&level1.path, copies);


   std::cout << std::endl;

   int dist_changes;

   do
   {

    dist_changes = 0;


   for (int where_i_am = 0; where_i_am < level1.number_of_points; where_i_am++)
   {
       for (int i_go_to = 0; i_go_to < level1.number_of_points; i_go_to++)
       {

        int is_there_any_path = level1.path[i_go_to][where_i_am];

        //there is a path
        if (is_there_any_path > -2)
        {
            int via = i_go_to;

            for (int from_there_i_go_to = 0; from_there_i_go_to < level1.number_of_points; from_there_i_go_to++)
                {
                    int path_to_destination = level1.path[from_there_i_go_to][via];

                    if (path_to_destination == -1)
                    {
                         std::int16_t distance = level1.distance[from_there_i_go_to][where_i_am];
                         std::int16_t new_distance = level1.distance[via][where_i_am] + level1.distance[from_there_i_go_to][via];

                         if (level1.path[from_there_i_go_to][where_i_am] != -1 && new_distance < distance)
                         {
                             if (level1.path[via][where_i_am] != -1)
                             {
                                 level1.path[from_there_i_go_to][where_i_am] = level1.path[via][where_i_am];
                             }
                             else
                             {
                                 level1.path[from_there_i_go_to][where_i_am] = via;
                             }

                             level1.distance[from_there_i_go_to][where_i_am] = new_distance;

                             dist_changes ++;
                         }
                    }
                }

            }
        }
   }


   }

   while (dist_changes);
   a.recalc_distance();

   a.show_array(&level1.path);

   a.compare(&level2);


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

    if (from_ == to_)
    {
        level1.distance[to_][from_] = 0;
        return true;
    }

    float radius = 50;
    level->player_pos_x = level1.coord_x[to_];
    level->player_pos_y = level1.coord_y[to_];

    bool available = target_to_chase.direct_path_available(level1.coord_x[from_], level1.coord_y[from_], radius);

    if(available) level1.distance[to_][from_] = level->distance(level1.coord_x[to_], level1.coord_y[to_], level1.coord_x[from_], level1.coord_y[from_]);

    return available;

}

Navigator::~Navigator()
{

    if (level) delete level;

    //dtor
}
