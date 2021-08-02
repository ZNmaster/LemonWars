#ifndef TITLE_H
#define TITLE_H

#include <GamePlayObj.h>


class Title : public GamePlayObj
{
    public:
        Title();
        virtual ~Title();
        virtual void go_move();

    protected:

    private:
};

#endif // TITLE_H
