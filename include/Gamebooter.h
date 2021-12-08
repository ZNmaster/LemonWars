#ifndef GAMEBOOTER_H
#define GAMEBOOTER_H

#include "Sounds.h"
#include "Base_Init.h"



class Gamebooter : public Base_Init

{
    public:
        Gamebooter();
        ~Gamebooter();
        Sounds s; // Initialize SoLoud
        static Sounds *soundengine;


    void Play ();



    protected:

    private:
};

#endif // GAMEBOOTER_H
