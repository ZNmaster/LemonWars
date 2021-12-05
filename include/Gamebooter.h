#ifndef GAMEBOOTER_H
#define GAMEBOOTER_H

#include <vector>

#include "Sounds.h"
#include "Base_Init.h"
#include "Entity.h"
#include "GamePlayObj.h"
#include "Rocket.h"


class Gamebooter : public Base_Init

{
    public:
        Gamebooter();
        ~Gamebooter();
        Sounds s; // Initialize SoLoud
        static Sounds *soundengine;
        SoLoud::Wav gWave;      // One wave file

    void Play ();



    protected:

    private:
};

#endif // GAMEBOOTER_H
