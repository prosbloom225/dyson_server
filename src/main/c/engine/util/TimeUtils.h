#ifndef TIMEUTILS_H
#define TIMEUTILS_H


#include <chrono>
#include <thread>


#include "engine/base/BaseMod.h"

class TimeUtils {
    public:
        void startClock();
        void stopClock();
        void waitForClock();
        int getTick();
        double getAvgTps(int ticks); // return average tps over the last *TICKS ticks
    private:
        /* const double TICKS_PER_SEC = 10; */ 
        const signed int TIME_WAIT = 10;  // ms to wait at end of tick to sync to clock
        double tps_history[10]; // TODO - this should be dynamic or set in config
        unsigned int tick;
        std::chrono::time_point<std::chrono::high_resolution_clock> start;

};


#endif
