#include "SpawnPoint.h"

SpawnPoint::SpawnPoint()
{
    //ctor
}

SpawnPoint::SpawnPoint(int x, int y, std::vector<Entity *> *obj)
{
    image = vita2d_create_empty_texture(1, 1);
}

void SpawnPoint::go_move()
{

}

SpawnPoint::~SpawnPoint()
{
    //dtor
}
