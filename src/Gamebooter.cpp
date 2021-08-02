#include "Gamebooter.h"
#include <iostream>
#include "Menu.h"



Gamebooter::Gamebooter()
{
    //ctor

    //GPU initialization
    GPU_init();

    //Input scanner
    scanner1 = new Scanner;
    scanner1->Scan();

    // create obj title screen and rocket

    GamePlayObj * title_screen = new GamePlayObj ("app0:/Title_screen.png");
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



  // draw a frame until any game object tells us to stop
  while (!draw_frame(obj))
  {
   scanner1->Scan();
  }
  GPU_finish();

  free_textures(obj);

  //Menu MainMenu;


  return;
}


    //Menu MainMenu;
    //MainMenu.MenuRun();


Gamebooter::~Gamebooter()
{
    free_textures(obj);
    //dtor

}
