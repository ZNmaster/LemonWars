#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer
{
    public:
        Timer();
        ~Timer();
        std::chrono::high_resolution_clock::time_point starttime, endtime;
        void start();
        void stop();
        int duration_int;
        float duration_float;

    protected:

    private:
};

#endif // TIMER_H
