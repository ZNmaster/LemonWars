#ifndef MENU_H
#define MENU_H
#include "Base_Init.h"
#include "MenuItem.h"


class Menu : public Base_Init
{
    public:
        Menu();
        ~Menu();

        bool MenuRun();

    protected:

    private:

        //Menu item pointers array (interactable)
        MenuItem *menuitem[10];
        int menu_item_count;

        //the current number of selected menu item
        int current;

        void StartPlay();
        void StartLoad();
        void StartCredits();
        void StartControls();
        void StartExit();

        void ActivatePlay();
        void ActivateLoad();
        void ActivateCredits();
        void ActivateControls();

        //menu navigation method
        void navigate();


        unsigned int MenuItemO;


        // array of the start func pointers
        void (Menu::*MenuFuncPtr[6])();

        // func call pointer
        void ( Menu::*StartActiveMenuItem) ();

        //navigation input timer
        Timer navigate_timer;

        // level methods
        void level1_1();

        bool quit;



};

#endif // MENU_H
