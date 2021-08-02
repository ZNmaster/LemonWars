#include "Entity.h"
#include <iostream>
#include <cmath>

Entity::Entity()
{
    abs_x = 0;
    abs_y = 0;

    //ctor
    std::cout << "default constructor of entity" << std::endl;
}

Entity::Entity(int a)
{
    abs_x = 0;
    abs_y = 0;

    //ctor
    std::cout << "int a constructor of entity" << std::endl;
}

Entity::~Entity()
{
    //dtor
    std::cout << "destructor of entity" << std::endl;
}

float Entity::distance(int x1, int y1)
{

    return sqrt(pow((abs_x-x1), 2) + pow((abs_y-y1), 2));
}

void Entity::go_move()
{
std::cout << "move of entity" << std::endl;
}
