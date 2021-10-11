#ifndef GAME_H
#define GAME_H

#include <Base_Init.h>


class Game : public Base_Init
{
    public:
        Game();
        Game(const char *MapFilename, const char *MemFilename);
        ~Game();

        bool StartGame();

    protected:

    private:
};

#endif // GAME_H
