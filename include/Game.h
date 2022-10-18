#ifndef GAME_H
#define GAME_H

#include <Base_Init.h>
#include "LevelData.h"


class Game : public Base_Init
{
    public:
        Game();
        Game(const char *LevelDataFilename);
        ~Game();

        bool StartGame();

    protected:

    private:
        LevelData levelmem;

};

#endif // GAME_H
