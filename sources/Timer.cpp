#include "Timer.h"


namespace Timer
{
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;


    void StartTimer()
    {   
        t1 = high_resolution_clock::now();
    }

    double GetElapsedMs()
    {
        t2 = high_resolution_clock::now();
        
        duration<double , std::milli> time_span = duration_cast<duration<double>>(t2 - t1);

        return time_span.count();        
    }


};