#include "Gamebooter.h"
#include "Menu.h"
#include <vita2d.h>



Gamebooter::Gamebooter()
{
    //ctor

    //GPU initialization
    GPU_init();

    //Input scanner
    scanner = new Scanner;
    scanner->Scan();

    // create obj title screen and rocket



    GamePlayObj * title_screen = new GamePlayObj ("app0:Title_screen.png");
    obj.push_back (title_screen);

    Rocket *rocket = new Rocket("app0:/assets/images/titlescreen/rocket.png");
    obj.push_back (rocket);


}

void Gamebooter::Play()
{
    //soloud
    gSoloud.init(); // Initialize SoLoud
    gWave.load("app0:/music.ogg");
    gSoloud.play(gWave);


    // draw a new frame until any game object tells us to stop
    while (!draw_frame(obj))
    {
     scanner->Scan();
    }

    vita2d_wait_rendering_done();
    //GPU_finish();

    //deleting title screen objects and input scanner
    free_textures(obj);
    delete scanner;

    Menu MainMenu;
    MainMenu.MenuRun();


    return;
}


Gamebooter::~Gamebooter()
{
    free_textures(obj);
    //dtor

}
