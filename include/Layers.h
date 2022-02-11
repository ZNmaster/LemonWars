#ifndef LAYERS_H
#define LAYERS_H

#include "Entity.h"

#include <vector>

struct Layers

{
    //vector of pointers to gameplay objects (images)
    std::vector<Entity *> layer0_obj;
    std::vector<Entity *> layer1_obj;

    unsigned int layers_num = 2;
};

#endif // LAYERS_H
