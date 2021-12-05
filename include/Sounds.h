#ifndef SOUNDS_H
#define SOUNDS_H

#include "soloud.h"
#include "soloud_wav.h"


class Sounds
{
    public:
        Sounds();
        virtual ~Sounds();

        SoLoud::Soloud SoloudSound; // SoLoud engine


    protected:

    private:
};

#endif // SOUNDS_H
