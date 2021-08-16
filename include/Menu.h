#ifndef MENU_H
#define MENU_H
#include "Base_Init.h"
#include "Scanner.h"
#include "GamePlayObj.h"


class Menu : public Base_Init
{
    public:
        Menu();
        ~Menu();

        void MenuRun();

    protected:

    private:

        GamePlayObj *menuitem[10];

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

        unsigned int MenuItem;
        Scanner *scanner2;

        // array of the start func pointers

        void (Menu::*MenuFuncPtr[5])();

        // func call pointer
        void ( Menu::*StartActiveMenuItem) ();


};

#endif // MENU_H
