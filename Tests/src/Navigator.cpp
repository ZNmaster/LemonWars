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

    rectangles.clear();
    //ctor
}

Navigator::Navigator(const char *LevelDataFilename)
{
    Load_Data(level1, LevelDataFilename);
    rectangles.clear();

    //ctor
}

bool Navigator::Create()
{
   X_size = 2250;

   copies.fill(-100);

   level = new LevelMap(&level1);
   target_to_chase = Target(level);

   a.set_array(&level1);

   a.fill_all(&level1.distance, 32000);

   a.fill_all(&level1.path, -1111);

   a.call_owner_and_fill(this, -1);

   Load_Data(level2, "level1.dat");

   a.compare(&level2.path);

   a.find_copies(&level1.path, copies);

   std::cout << std::endl;


   calc_path();

   std::cout << "--------------------------------------------------- " << std::endl;


   std::int16_t ref_array[150][150];

   a.copy_array(&level1.distance, &ref_array);


   int ch2 = 0;


       ch2 = a.recalc_distance();
       std::cout << "Changes after recalc: " << ch2 << std::endl;

   for (auto p : a.points)
   {
       std::cout << "From " << p.y << " to " <<  p.x << " has been changed. " << " Was "<< ref_array[p.x][p.y] << " now " << level1.distance[p.x][p.y];
       if (abs(ref_array[p.x][p.y] - level1.distance[p.x][p.y]) < 2) std::cout << " OK!!!!" <<  std::endl;

   }

   std::cout << "Total distance before recalc: " << a.array_add(&ref_array) << std::endl;
   std::cout << "Total distance after recalc: " << a.array_add(&level1.distance) << std::endl;

   a.check_nav_table();

   try
   {
      access_map = new std::int8_t [X_size][Y_max];
   }
   catch (...)
   {
       std::cout << "Array problem \r\n";
       return 0;
   }

   reset_access_map();

   //player spawn position (100, 100)
   set_accessible(100, 100);


    //replace all initial -1 (not checked) by 0 (not accessible)
    for (int i = 0; i < X_size; i++)
    {
        for (int k = 0; k < Y_max; k++)
        {
            if (access_map[i][k] == -1) access_map[i][k] = 0;
        }
    }

    create_rectangles();
    std::cout << "Total rectangles: " << rectangles.size() << std::endl;

    for (std::vector<Line>::size_type m = 0; m < rectangles.size(); m++)
    {
        std::cout << "From: (" << rectangles[m].x_start << "," << rectangles[m].y_start << ") To: ("
                  << rectangles[m].x_end << "," << rectangles[m].y_end << ")" << std::endl;
    }


   return false;
}

int Navigator::calc_path()
{
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
   //std::cout << "Changes of path: " << dist_changes << std::endl;

   }
   while (dist_changes);

   return dist_changes;
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
    float radius = 50;

    if (from_ == to_)
    {
        level1.distance[to_][from_] = 0;
        return true;
    }


    //Do not use path available func, it is little different because here we need to check all possible pathes between all the points
    level->player_pos_x = level1.coord_x[to_];
    level->player_pos_y = level1.coord_y[to_];

    bool available = target_to_chase.direct_path_available(level1.coord_x[from_], level1.coord_y[from_], radius);

    if(available) level1.distance[to_][from_] = level->distance(level1.coord_x[to_], level1.coord_y[to_], level1.coord_x[from_], level1.coord_y[from_]);

    return available;

}

bool Navigator::path_available(int to_, int from_)
{
    float radius = 50;

    //to_ and from_ are the same point
    if (to_ == from_) return true;


    if (level1.path[to_][from_] == -1)
    {
        float coord_x_from = level1.coord_x[from_];
        float coord_y_from = level1.coord_y[from_];

        level->player_pos_x = level1.coord_x[to_];
        level->player_pos_y = level1.coord_y[to_];

        return target_to_chase.direct_path_available(coord_x_from, coord_y_from, radius);
    }
    else
    {
        return path_available(level1.path[to_][from_], from_) && path_available(to_, level1.path[to_][from_]);
    }
}

void Navigator::set_accessible(int x, int y)
{
    rec++;
    //std::cout << "\rRec depth " << rec << "             ";

    access_map[x][y] = 1;

    int x2, y2;
    x2 = x;
    y2 = y-1;
    if(accessible(x, y, x2, y2)) set_accessible(x2, y2);
    x2 = x-1;
    y2 = y;
    if(accessible(x, y, x2, y2)) set_accessible(x2, y2);
    x2 = x+1;
    y2 = y;
    if(accessible(x, y, x2, y2)) set_accessible(x2, y2);
    x2 = x;
    y2 = y+1;
    if(accessible(x, y, x2, y2)) set_accessible(x2, y2);

    rec--;
}

bool Navigator::accessible(int x1, int y1, int x2, int y2)
{
    if(x2 < 0 || y2 < 0 || x2 >= X_size || y2 >= Y_max) return 0;

    if(access_map[x2][y2] < 0)
    {
        bool visible = level->levelwalls.visible(x1, y1, x2, y2);
        if(!visible) access_map[x2][y2] = 0;

        return visible;
    }
    return 0;
}

void Navigator::reset_access_map()
{
    for (int i = 0; i < X_size; i++)
    {
        for (int k = 0; k < Y_max; k++)
        {
            access_map[i][k] = -1;
        }
    }
}

void Navigator::create_rectangles()
{
    //start coord x of the horizontal line (sequence of accessible points)
    int x_start = -1;
    int x_end = -1;

    for (int y = 0; y < Y_max; y++)
    {

        x_start = -1;
        x_end = -1;

        for (int x = 0; x < X_size; x++)
        {

            if (access_map[x][y] == 1)
            {
                if (x_start < 0)
                {
                    x_start = x;
                }

                //waiting for last accessible point in the line
                if (access_map[x+1][y] == 0)
                {
                    x_end = x;

                    bool changed = 0;
                    for (std::vector<Line>::size_type m = 0; m < rectangles.size(); m++)
                    {
                       //the line belongs to previously created rectangle
                       if ( (int)rectangles[m].x_start == x_start && (int)rectangles[m].x_end == x_end && (int)rectangles[m].y_end == (y-1))
                       {
                           rectangles[m].calcline(rectangles[m].x_start, rectangles[m].y_start, x_end, y);

                           changed = 1;
                       }
                       //creating a new rectangle

                    }

                    if (!changed) rectangles.push_back(Line (x_start, y, x_end, y));


                    x_start = -1;
                    x_end = -1;


                }

            }

        }

    }

}

Navigator::~Navigator()
{

    if (level) delete level;
    if (access_map) delete[] access_map;

    //dtor
}
