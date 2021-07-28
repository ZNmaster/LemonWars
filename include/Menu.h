#ifndef MENU_H
#define MENU_H
#include "Base_Init.h"


class Menu : public Base_Init
{
    public:
        Menu();
        ~Menu();

        void MenuRun();

    protected:

    private:
        void StartPlay();
        void StartLoad();
        void StartCredits();
        void StartControls();
        void ActivatePlay();
        void ActivateLoad();
        void ActivateCredits();
        void ActivateControls();
        unsigned int MenuItem;

        // array of the start func pointers

        void (Menu::*MenuFuncPtr[3])();

        // func call pointer
        void ( Menu::*StartActiveMenuItem) ();
};

#endif // MENU_H
