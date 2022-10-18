#ifndef LEVELDATA_H
#define LEVELDATA_H
#include <cstdint>

struct LevelData

{
    //the number of nav points on the map
    std::uint16_t number_of_points;

    //coordinates of the nav points on the map
    std::int16_t coord_x[150];
    std::int16_t coord_y[150];

    //distance between the nav points
    std::int16_t distance[150][150];

    //path between the nav points
    std::int16_t path[150][150];


    //the number of walls
    std::uint16_t number_of_walls;

    //wall coordinates
    std::int16_t wall_x_start[70];
    std::int16_t wall_y_start[70];
    std::int16_t wall_x_end[70];
    std::int16_t wall_y_end[70];


    //spawn points
    std::uint8_t number_of_spawn;
    std::int16_t spawn_coord_x[20];
    std::int16_t spawn_coord_y[20];
    std::uint8_t enemy_type[300];

    //interactive objects
    std::uint8_t number_of_interactive;
    std::int16_t interact_coord_x[20];
    std::int16_t interact_coord_y[20];
    std::uint8_t interact_type[300];

    //player spawn coordinates
    std::uint8_t number_of_player_spawn;
    std::int16_t player_spawn_coord_x[10];
    std::int16_t player_spawn_coord_y[10];
    //point indexes
    std::uint8_t upstream_point;//where to spawn when going forward
    std::uint8_t downstream_point;//=255 if non existent (cannot come back)
    std::uint8_t teleport_point1;
    std::uint8_t teleport_point2;
    std::uint8_t teleport_point3;
    std::uint8_t teleport_point4;
    std::uint8_t teleport_point5;

    //image filenames
    char filename0[100];
    char filename1[100];
    char filename2[100];
    char filename3[100];
    char filename4[100];

};

#endif // LEVELDATA_INCLUDED
