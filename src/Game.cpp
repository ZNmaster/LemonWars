#include "Game.h"
#include "Scanner.h"
#include "LevelMap.h"


Game::Game()
{
    //ctor
    GPU_init();

    Scanner *scanner2 = new Scanner;
    scanner2->Scan();

    LevelMap *level = new LevelMap("app0:/assets/images/levels/1_1/Level1_1.png");
    obj.push_back (level);

    while (!draw_frame(obj))
    {

     if (scanner2)
     {
         scanner2->Scan();
     }

    }

    GPU_finish();
    free_textures(obj);

    if (scanner2)
    {
        delete scanner2;
    }


}


Game::~Game()
{
    //dtor
}
