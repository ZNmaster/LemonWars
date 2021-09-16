#include "Game.h"
#include "Scanner.h"
#include "LevelMap.h"
#include "Player.h"
#include "SpawnPoint.h"


Game::Game()
{
    //ctor
}

Game::Game(const char *filename)

{
    GPU_init();

    SpawnPoint *spawn = new SpawnPoint(650, 1200, &obj);
    obj.push_back (spawn);

    LevelMap *level = new LevelMap(filename);
    obj.push_back (level);

    Player *player = new Player(level, "app0:/assets/images/characters/tank_sprite.png", 2, 2, 100, 100);

    obj.push_back (player);
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
