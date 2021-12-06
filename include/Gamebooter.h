#ifndef GAMEBOOTER_H
#define GAMEBOOTER_H

#include "Sounds.h"
#include "Base_Init.h"
#include "soloud_wavstream.h"


class Gamebooter : public Base_Init

{
    public:
        Gamebooter();
        ~Gamebooter();
        Sounds s; // Initialize SoLoud
        static Sounds *soundengine;
        SoLoud::WavStream gWave;      // One wave file

    void Play ();



    protected:

    private:
};

#endif // GAMEBOOTER_H
