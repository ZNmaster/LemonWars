#include "Game.h"
#include "Scanner.h"
#include "LevelMap.h"


Game::Game()
{
    //ctor

}

Game::Game(const char *filename)

{
    GPU_init();

    LevelMap *level = new LevelMap(filename);
    obj.push_back (level);
}

bool Game::StartGame()

{

    scanner = new Scanner;
    scanner->Scan();



    while (!draw_frame(obj))
    {

     if (scanner)
     {
         scanner->Scan();
     }

    }

    GPU_finish();
    free_textures(obj);

    if (scanner)
    {
        delete scanner;
    }
    return 0;

}

Game::~Game()
{
    //dtor
}
