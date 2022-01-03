#include "Gamebooter.h"
#include "Menu.h"
#include "Rocket.h"



Gamebooter::Gamebooter()
{

    soundengine = &s;
    //ctor

    //GPU initialization
    GPU_init();

    //Input scanner
    scanner = new Scanner;
    scanner->Scan();

    // create obj title screen and rocket



    GamePlayObj * title_screen = new GamePlayObj ("app0:Title_screen.png");
    layers.layer0_obj.push_back (title_screen);

    Rocket *rocket = new Rocket("app0:/assets/images/titlescreen/rocket.png");
    layers.layer0_obj.push_back (rocket);


}

void Gamebooter::Play()
{
    //soloud

    //s.SoloudSound.play(background_music);


    // draw a new frame until any game object tells us to stop
    while (!draw_frame(layers.layer0_obj))
    {
     scanner->Scan();
    }

    GPU_finish();

    //deleting title screen objects and input scanner
    free_textures(layers.layer0_obj);
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
    free_textures(layers.layer0_obj);
    //dtor

}
