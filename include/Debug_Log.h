#ifndef DEBUG_LOG_H
#define DEBUG_LOG_H
#include <fstream>
#include <chrono>
#include <string>


class Debug_Log
{
    private:
    uint64_t t0;

    public:

        Debug_Log();
        Debug_Log(std::string filename);

        std::ofstream myfile;

        void writedown();


        bool ignore_writedown;


        template<typename A> void log(A a)
        {
            uint64_t t1 = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count() - t0;
            myfile << t1 << " " << a << "\r\n";
        }

        template<typename A, typename B> void log(A a, B b)
        {
            uint64_t t1 = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count() - t0;
            myfile << t1 << " " << a << " " << b << "\r\n";
        }

        template<typename A, typename B, typename C> void log(A a, B b, C c)
        {
            uint64_t t1 = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count() - t0;
            myfile << t1 << " " << a << " " << b << " " << c << "\r\n";
        }

        template<typename A, typename B, typename C, typename D> void log(A a, B b, C c, D d)
        {
            uint64_t t1 = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count() - t0;
            myfile << t1 << " " << a << " " << b << " " << c << " " << d << "\r\n";
        }

        template<typename A, typename B, typename C, typename D, typename E> void log(A a, B b, C c, D d, E e)
        {
            uint64_t t1 = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count() - t0;
            myfile << t1 << " " << a << " " << b << " " << c << " " << d << " " << e << "\r\n";
        }

        ~Debug_Log();

    protected:

    private:

        bool closed;
        std::string filename;
        void openfile();
};

#endif // DEBUG_LOG_H
