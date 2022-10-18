#ifndef MENUITEM_H
#define MENUITEM_H

#include <GamePlayObj.h>
#include <vector>


class MenuItem : public GamePlayObj
{
    public:
        MenuItem(const char *filename);
        void go_move();
        virtual void layer_moved(std::vector<Entity *> &target_lay);
        virtual ~MenuItem();
        int item_num;


    protected:

    private:
};

#endif // MENUITEM_H
