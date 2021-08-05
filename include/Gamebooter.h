#ifndef GAMEBOOTER_H
#define GAMEBOOTER_H

#include <vector>
#include "soloud.h"
#include "soloud_wav.h"

#include "Base_Init.h"
#include "Entity.h"
#include "GamePlayObj.h"
#include "Rocket.h"

#include "Scanner.h"


class Gamebooter : public Base_Init

{
    public:
        Gamebooter();
        ~Gamebooter();

    void Play ();

    SoLoud::Soloud gSoloud; // SoLoud engine
    SoLoud::Wav gWave;      // One wave file




    Scanner *scanner1;


    protected:

    private:
};

#endif // GAMEBOOTER_H
