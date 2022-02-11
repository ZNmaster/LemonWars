#ifndef ROTATOR_H
#define ROTATOR_H

#include "Timer.h"
#include "Angle.h"


class Rotator : public Angle
{
    public:
        Rotator();
        Rotator(float cur_angle, float sin_a, float cos_a, float ang_speed);

        float alt_angle(float ang);
        float get_angle();

        Timer timer;

        float speed;
        float target_angle;
        float current_angle;

        float direction;

        bool finished;

        virtual ~Rotator();

    protected:

    private:
};

#endif // ROTATOR_H
