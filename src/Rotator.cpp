#include "Rotator.h"

#include <cmath>

Rotator::Rotator()
{
    //ctor
    finished = 0;
}

Rotator::Rotator(float cur_angle, float sin_a, float cos_a, float ang_speed)

{
    finished = 0;
    speed = ang_speed;
    current_angle = cur_angle;
    target_angle = calcangle(sin_a, cos_a);
    float alt_targ = alt_angle(target_angle);
    //Check if alternative angle is better to use
    if (abs(target_angle - current_angle) > abs(alt_targ - current_angle))
    {
        target_angle = alt_targ;
    }

    direction = abs(target_angle - current_angle) / (target_angle - current_angle);
    timer.start();

}

float Rotator::get_angle()
{
    if (finished)
    {
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
