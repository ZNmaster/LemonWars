#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer
{
    public:
        Timer();
        ~Timer();
        std::chrono::high_resolution_clock::time_point starttime, endtime, delay_starttime, delay_endtime;
        void start();
        void stop();
        unsigned int delay_ms;
        int duration_int, delay_duration_int;
        float duration_float, delay_duration_float;

        void calculate_dur (const std::chrono::high_resolution_clock::time_point &starttime_point,
                            const std::chrono::high_resolution_clock::time_point &stoptime_point,
                            int &dur_mills, float &dur_sec);

        void delay_mills (unsigned int delay);
        bool expired();

    protected:

    private:
};

#endif // TIMER_H
