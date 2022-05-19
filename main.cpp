#include "Menu.h"
#include "Gamebooter.h"
#include "Wallbuilder.h"
#include "LevelMap.h"
#include "Init.ini"
#include "Debug_Log.h"

//int LevelMap::number_of_enemies = 12;

int main()
{

    //Scanner::start_pressed = 1;
    //Menu MainMenu;
    //MainMenu.MenuRun();

    try
    {
        Gamebooter Game1;

        Game1.Play();
    }

    catch (std::bad_alloc &e)
    {
        Debug_Log debug_file("ux0:/data/exception.txt");
        debug_file.log("bad allocation");
        debug_file.log (e.what());
        throw e;
    }

    catch (...)
    {
        Debug_Log debug_file("ux0:/data/exception.txt");
        debug_file.log("unknown exception");
        throw;
    }


    return 0;
}
