#include "Game.h"
#include "Scanner.h"
#include "LevelMap.h"
#include "Player.h"
#include "SpawnPoint.h"
#include "Common_Lemon.h"
#include "Projectile.h"




Game::Game()
{
    //ctor
}

Game::Game(const char *MapFilename, const char *MemFilename)

{


    GPU_init(2);

    SpawnPoint *spawn = new SpawnPoint(650, 1200, &obj);
    obj.push_back (spawn);

    SpawnPoint *spawn2 = new SpawnPoint(650, 1600, &obj);
    obj.push_back (spawn2);

    LevelMap *level = new LevelMap(MapFilename, MemFilename);
    obj.push_back (level);

    //save level map pointer in spawn point
    spawn->set_levelmap(level);
    spawn2->set_levelmap(level);

    Player *player = new Player(level, &obj, "app0:/assets/images/characters/player.png", 2, 2, 150, 150);

    obj.push_back (player);



    vita2d_texture *testim = vita2d_load_PNG_file("app0:/assets/images/projectiles/bullet.png");


    Point_int a;
    a.x =100;
    a.y = 200;
    Projectile * test = new Projectile(testim, a, level, &obj, 0);
    test->pos_x = 140;
    test->pos_y = 160;
    obj.push_back (test);

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
