#include <fstream>
#include <cstdint>
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

Game::Game(const char *LevelDataFilename)

{

    //open level data filename
    std::fstream myFile2;
    myFile2.open(LevelDataFilename, std::ios::in | std::ios::binary);
    myFile2.read((char *)&levelmem, sizeof(LevelData));
    myFile2.close();

    GPU_init(2);

    //lemon spawns

    LevelMap *level = new LevelMap(&levelmem);
    (*layers[0]).push_back (level);

    for (std::uint8_t i = 0; i < levelmem.number_of_spawn; i++)
    {
        SpawnPoint *spawn = new SpawnPoint(levelmem.spawn_coord_x[i], levelmem.spawn_coord_y[i], layers[1]);
        (*layers[0]).push_back (spawn);
        //save level map pointer in spawn point
        spawn->set_levelmap(level);

    }

    //player spawn
    Player *player = new Player(level, layers, "app0:/assets/images/characters/player.png", 2, 2, 150, 150);

    (*layers[1]).push_back (player);

}

bool Game::StartGame()

{

    Scanner scanner;
    scanner.Scan();

    while (!draw_frame(layers))
    {
         scanner.Scan();
    }

    //debug_file.log("Finished drawframe");

    GPU_finish();
    free_textures(*layers[0]);
    free_textures(*layers[1]);


    return 0;

}

Game::~Game()
{
    //dtor
}
