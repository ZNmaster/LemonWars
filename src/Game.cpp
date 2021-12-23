#include "Game.h"
#include "Scanner.h"
#include "LevelMap.h"
#include "Player.h"
#include "SpawnPoint.h"
#include "Common_Lemon.h"




Game::Game()
{
    //ctor
}

Game::Game(const char *MapFilename, const char *MemFilename)

{


    GPU_init(2);

    //lemon spawns
    SpawnPoint *spawn = new SpawnPoint(650, 1200, &layers.layer1_obj);
    layers.layer0_obj.push_back (spawn);

    SpawnPoint *spawn2 = new SpawnPoint(650, 1600, &layers.layer1_obj);
    layers.layer0_obj.push_back (spawn2);

    LevelMap *level = new LevelMap(MapFilename, MemFilename);
    layers.layer0_obj.push_back (level);

    //save level map pointer in spawn point
    spawn->set_levelmap(level);
    spawn2->set_levelmap(level);
    //player spawn
    Player *player = new Player(level, &layers, "app0:/assets/images/characters/player.png", 2, 2, 150, 150);

    layers.layer1_obj.push_back (player);

}

bool Game::StartGame()

{

    scanner = new Scanner;
    scanner->Scan();


    while (!draw_frame(layers))
    {

     if (scanner)
     {
         scanner->Scan();
     }

    }

    GPU_finish();
    free_textures(layers.layer0_obj);
    free_textures(layers.layer1_obj);


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
