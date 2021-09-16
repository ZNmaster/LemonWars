#ifndef MEMORY_H
#define MEMORY_H

struct Memory

{
    //the number of nav points on the map
    int number_of_points;

    //coordinates of the nav points on the map
    int coord_x[100];
    int coord_y[100];

    //distance between the nav points
    float distance[100][100];

    //path between the nav points
    int path[100][100];
};

#endif // MEMORY_H
