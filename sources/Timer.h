#ifndef TIMER_H
#define TIMER_H

#include <ctime>
#include <ratio>
#include <chrono>

namespace Timer
{
    using namespace std::chrono;
    extern high_resolution_clock::time_point t1;
    extern high_resolution_clock::time_point t2;

    void StartTimer();
    double GetElapsedMs();
    


};

#endif