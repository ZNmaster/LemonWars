#include "Timer.h"

Timer::Timer()
{
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

    auto dur = endtime - starttime;

    auto i_millis = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
    auto f_secs = std::chrono::duration_cast<std::chrono::duration<float>>(dur);

    duration_int = i_millis.count();
    duration_float = f_secs.count();
}

