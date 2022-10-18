#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Init.ini"
#include "MemoryBuilder.h"
#include "LevelData.h"



int main()
{


    //MemoryBuilder aaa;
    //return 0;

    std::string name = "level1.dat";

    LevelData level1;
    strncpy(level1.filename0,"level1.dat", 100);

    std::cout << level1.filename0 <<  std::endl;

    std::fstream myFile2;
    myFile2.open(name.c_str(), std::ios::in | std::ios::binary);

    myFile2.read((char *)&level1, sizeof(LevelData));

    myFile2.close();

    for(int16_t to_ = 0; to_ < level1.number_of_points; to_ ++)
    {
        for(int16_t from_ = 0; from_ < level1.number_of_points; from_ ++)
        {

            std::cout << level1.distance[to_][from_] << " ";
        }
        std::cout << std::endl;
    }

    for(std::int16_t i = 0; i < level1.number_of_walls; i++)
    {
        std::cout << level1.wall_x_end[i] << " ";
    }
    std::cout << std::endl;


    //std::cout << str <<  std::endl;

    std::cout << level1.spawn_coord_x[1] <<  std::endl;
    std::cout << level1.spawn_coord_y[1] <<  std::endl;




  return 0;



}

