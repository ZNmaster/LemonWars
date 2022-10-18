#include "Gamebooter.h"
#include "Menu.h"
#include "Rocket.h"



Gamebooter::Gamebooter()
{

    soundengine = &s;
    //ctor

    //GPU initialization
    GPU_init();


    // create obj title screen and rocket



    GamePlayObj * title_screen = new GamePlayObj ("app0:Title_screen.png");
    (*layers[0]).push_back (title_screen);

    Rocket *rocket = new Rocket("app0:/assets/images/titlescreen/rocket.png");
    (*layers[0]).push_back (rocket);


}

void Gamebooter::Play()
{
    //soloud

    //s.SoloudSound.play(background_music);

    Scanner *scanner = new Scanner;



    // draw a new frame until any game object tells us to stop
    while (!draw_frame(*layers[0]))
    {
     scanner->Scan();
    }

    GPU_finish();

    //deleting title screen objects and input scanner
    free_textures(*layers[0]);
    delete scanner;

    bool quit = 0;
    do
    {
      Menu MainMenu;
      quit = MainMenu.MenuRun();
    }
    while(!quit);



    return;
}


Gamebooter::~Gamebooter()
{
    free_textures(*layers[0]);
    //dtor

}
