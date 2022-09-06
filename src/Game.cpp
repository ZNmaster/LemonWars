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
    //Debug_Log debug_file("ux0:/data/game.txt");
    //debug_file.log("Creating game");
    //debug_file.writedown();

    GPU_init(2);

    //lemon spawns
    SpawnPoint *spawn = new SpawnPoint(650, 1200, &layers.layer1_obj);
    layers.layer0_obj.push_back (spawn);

    //SpawnPoint *spawn2 = new SpawnPoint(650, 1600, &layers.layer1_obj);
    //layers.layer0_obj.push_back (spawn2); set levelmap!!!!!

    LevelMap *level = new LevelMap(MapFilename, MemFilename);
    layers.layer0_obj.push_back (level);

    //save level map pointer in spawn point
    spawn->set_levelmap(level);
    //spawn2->set_levelmap(level);

    //player spawn
    Player *player = new Player(level, &layers, "app0:/assets/images/characters/player.png", 2, 2, 150, 150);

    layers.layer1_obj.push_back (player);


}

bool Game::StartGame()

{
    //Debug_Log debug_file("ux0:/data/game.txt");
    //debug_file.log("Starting game");

    Scanner scanner;
    scanner.Scan();

    /*
    //debug
    Entity *test_ptr = nullptr;
    debug_file.log("Test nullptr: ", test_ptr);

    vita2d_texture *test_ptr2 = nullptr;
    debug_file.log("IMAGE Test nullptr: ", test_ptr2);


    for (auto objct : layers.layer0_obj)
    {
        debug_file.log("Layer0 obj pointer: ", objct);
        debug_file.log("Layer0 IMAGE pointer: ", objct->image);
    }

    for (auto objct : layers.layer1_obj)
    {
        debug_file.log("Layer1 obj pointer: ", objct);
        debug_file.log("Layer1 IMAGE pointer: ", objct->image);
    }


    debug_file.log("Created scanner", "Running drawframe");
    debug_file.writedown();*/


    while (!draw_frame(layers))
    {
         scanner.Scan();
    }

    //debug_file.log("Finished drawframe");

    GPU_finish();
    free_textures(layers.layer0_obj);
    free_textures(layers.layer1_obj);


    return 0;

}

Game::~Game()
{
    //dtor
}
