#ifndef MENUITEM_H
#define MENUITEM_H

#include <GamePlayObj.h>


class MenuItem : public GamePlayObj
{
    public:
        MenuItem(const char *filename);
        void go_move();
        virtual ~MenuItem();

    protected:

    private:
};

#endif // MENUITEM_H
