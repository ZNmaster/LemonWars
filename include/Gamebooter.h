#ifndef GAMEBOOTER_H
#define GAMEBOOTER_H

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include <vita2d.h>

#include "soloud.h"
#include "soloud_wav.h"


class Gamebooter
{
    public:
        Gamebooter();
        ~Gamebooter();

    void Play ();

    SoLoud::Soloud gSoloud; // SoLoud engine
    SoLoud::Wav gWave;      // One wave file

    SceCtrlData pad;
    //vita2d_pgf *pgf;
    vita2d_pvf *pvf;
    vita2d_texture *image;
    float rad = 0.0f;


    protected:

    private:
};

#endif // GAMEBOOTER_H
