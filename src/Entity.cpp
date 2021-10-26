#include "Entity.h"
#include <cmath>

Entity::Entity()
{
    //reset flags
    abs_x = 0;
    abs_y = 0;
    pos_x = 0;
    pos_y = 0;
    part_x = 0;
    part_y = 0;
    partial = 0;
    scaled = 0;
    waved = 0;
    terminated = 0;
    dead = 0;

    //ctor

}

Entity::Entity(int a)
{

    //ctor

}

Entity::~Entity()
{
    //dtor

}

float Entity::distance(int x1, int y1)
{

    return sqrt(pow((abs_x-x1), 2) + pow((abs_y-y1), 2));
}

float Entity::distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
}

//interface
void Entity::go_move()
{

}
