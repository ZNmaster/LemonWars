#include "Rotator.h"

#include <cmath>

Rotator::Rotator()
{
    //ctor
    finished = 0;
}

Rotator::Rotator(float cur_angle, float sin_a, float cos_a, float ang_speed)

{
    //upd_count = 0;
    finished = 0;
    speed = ang_speed;
    current_angle = cur_angle;
    target_angle = calcangle(sin_a, cos_a);

    //reset big angle
    if (abs(current_angle) > 4)
        {
            current_angle = alt_angle(current_angle);
        }

    float alt_targ = alt_angle(target_angle);

    //Check if alternative angle is better to use
    if (abs(target_angle - current_angle) > abs(alt_targ - current_angle))
    {
        target_angle = alt_targ;
    }

    if (target_angle != current_angle)
    {

       direction = (target_angle > current_angle) ? 1 : -1;

       /*if ((target_angle - current_angle) > 0)
       {
           direction = 1;
       }

       else
       {
           direction = -1;
       }
       */

       timer.start();
    }
    else
    {
        finished = 1;
    }

}

float Rotator::get_angle()
{
    if (finished)
    {
        if (abs(current_angle) > 4)
        {
            current_angle = alt_angle(current_angle);
        }
        return current_angle;
    }

    timer.stop();
    timer.start();

    float delta = (speed*timer.duration_float)*direction;
    float new_current = current_angle + delta;

    if (direction > 0)
    {
        if (new_current > target_angle)
        {
            current_angle = target_angle;
            finished = 1;
        }
        else
        {
            current_angle = new_current;
        }
    }
    else
    {
        if (new_current < target_angle)
        {
            current_angle = target_angle;
            finished = 1;
        }
        else
        {
            current_angle = new_current;
        }
    }

    return current_angle;

}

float Rotator::alt_angle(float ang)
{
    float alt_angle;

    if (ang <= 0)
    {
        alt_angle = ang + 2*pi;
    }
    else
    {
        alt_angle = ang - 2*pi;
    }

    return alt_angle;
}

Rotator::~Rotator()
{
    //dtor
}
