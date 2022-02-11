#include "Entity.h"
#include <cmath>


Entity::Entity()
{
    //reset flags, factors and coordinates

    //int and float
    abs_x = 0;
    abs_y = 0;
    pos_x = 0;
    pos_y = 0;

    part_x = 0;
    part_y = 0;

    //bool flags
    partial = 0;
    scaled = 0;
    waved = 0;
    terminated = 0;
    enemy = 0;
    dead = 0;
    move_it = 0;


    angle = 0;

    //scaling factors
    k_x = 1;
    k_y = 1;

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

void Entity::hit(int hitpoints, float projectile_angle, int x, int y)
{

}

void Entity::layer_moved(std::vector<Entity *> &target_lay)
{

}
