#ifndef ROCKET_H
#define ROCKET_H

#include <GamePlayObj.h>


class Rocket : public GamePlayObj
{
    public:
        Rocket();
        Rocket(const char *filename);
        virtual ~Rocket();
        void go_move();

    protected:

    private:
};

#endif // ROCKET_H
