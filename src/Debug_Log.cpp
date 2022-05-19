#include "Debug_Log.h"
//#include <fstream>

Debug_Log::Debug_Log()
{
    filename = "example.txt";
    openfile();

    //ctor
}

Debug_Log::Debug_Log(std::string filename) : filename (filename)
{
    openfile();
}

void Debug_Log::openfile ()
{
    ignore_writedown = 0;

    myfile.open (filename);
    closed = 0;
    t0 = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count();
}

void Debug_Log::writedown ()
{
    if (ignore_writedown) return;
    if (!closed) myfile.close();
    myfile.open (filename, std::fstream::app);
}

Debug_Log::~Debug_Log()
{
    if (!closed) myfile.close();
    //dtor
}
