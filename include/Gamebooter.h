#ifndef GAMEBOOTER_H
#define GAMEBOOTER_H
#include "Base_Init.h"


#include "soloud.h"
#include "soloud_wav.h"


class Gamebooter : public Base_Init

{
    public:
        Gamebooter();
        ~Gamebooter();

    void Play ();

    SoLoud::Soloud gSoloud; // SoLoud engine
    SoLoud::Wav gWave;      // One wave file




    protected:

    private:
};

#endif // GAMEBOOTER_H
