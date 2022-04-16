#include "Timer.h"

Timer::Timer()
{
    creation_time = std::chrono::high_resolution_clock::now();
    delay_mills(200);
    //ctor
}

Timer::~Timer()
{
    //dtor
}

void Timer::start()
{
    starttime = std::chrono::high_resolution_clock::now();
}
void Timer::stop()
{
    endtime = std::chrono::high_resolution_clock::now();

    calculate_dur (starttime, endtime, duration_int, duration_float);

}

void Timer::calculate_dur(const std::chrono::high_resolution_clock::time_point &starttime_point,
                            const std::chrono::high_resolution_clock::time_point &endtime_point,
                            unsigned int &dur_mills, float &dur_sec)
{
    auto dur = endtime_point - starttime_point;

    auto int_millis = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
    auto float_secs = std::chrono::duration_cast<std::chrono::duration<float>>(dur);

    dur_mills = int_millis.count();
    dur_sec = float_secs.count();
}

void Timer::delay_mills (unsigned int delay)
{
    delay_starttime = std::chrono::high_resolution_clock::now();
    delay_ms = delay;

}

bool Timer::expired()

{
    delay_endtime = std::chrono::high_resolution_clock::now();
    calculate_dur (delay_starttime, delay_endtime, delay_duration_int, delay_duration_float);

    if (delay_duration_int >= delay_ms)
    {
        return 1;
    }
    return 0;
}

void Timer::make_expired()
{
    delay_ms = 1;
    delay_starttime = creation_time;
}
