#include "RNG.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

RNG::RNG()
{
    //ctor
}

int RNG::int_random(int x_max)
{
    //random seed init
    srand (time(NULL));
    return rand() % (x_max + 1);


}

int RNG::int_random(int x_max, int x_min)
{
    return int_random(x_max - x_min) + (x_max - x_min);
}

RNG::~RNG()
{
    //dtor
}
