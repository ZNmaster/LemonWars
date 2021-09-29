#include "RNG.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

RNG::RNG()
{
    //ctor

    //random seed init
    srand (time(NULL));
}

int RNG::int_random(int x_max)
{

    return rand() % (x_max + 1);


}

int RNG::int_random(int x_min, int x_max)
{
    return int_random(x_max - x_min) + x_min;
}

RNG::~RNG()
{
    //dtor
}
