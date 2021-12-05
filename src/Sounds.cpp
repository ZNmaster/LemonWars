#include "Sounds.h"

Sounds::Sounds()
{
    //ctor
    SoloudSound.init();
}

Sounds::~Sounds()
{
    SoloudSound.deinit();
    //dtor
}
