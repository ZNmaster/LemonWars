#include "Entity.h"
#include <cmath>

Entity::Entity()
{
    abs_x = 0;
    abs_y = 0;
    pos_x = 0;
    pos_y = 0;

    //ctor

}

Entity::Entity(int a)
{
    abs_x = 0;
    abs_y = 0;

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

void Entity::go_move()
{

}
