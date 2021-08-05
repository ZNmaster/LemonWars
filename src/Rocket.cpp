#include "Rocket.h"
#include "Scanner.h"

Rocket::Rocket()
{
    //ctor
}
Rocket::Rocket(const char *filename)
        : GamePlayObj::GamePlayObj (filename)
{
  started = 0;
  pos_x = 700;
  pos_y = 300;
  delta = 1;
}

Rocket::~Rocket()
{
    //dtor
}

void Rocket::go_move()
{
        if (Scanner::start_pressed)
        {
            started = 1;
        }

        if (started)
    {
          pos_y -= delta;

            if (pos_y < -230)
           {
              terminated = 1;
           }
        delta += 1;

    }
}
