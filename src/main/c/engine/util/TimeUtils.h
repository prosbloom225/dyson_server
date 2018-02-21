#ifndef TIMEUTILS_H
#define TIMEUTILS_H


#include <chrono>
#include <thread>


#include "engine/base/BaseMod.h"

class TimeUtils {
    public:
        static void startClock();
        static void waitForClock();
        static int getTick();
        static double getAvgTps(int ticks); // return average tps over the last *TICKS ticks
    private:
        static const signed int TIME_WAIT;  // ms to wait at end of tick to sync to clock
        static double tps_history[10]; // TODO - this should be dynamic or set in config
        static signed int tick;
        static std::chrono::time_point<std::chrono::high_resolution_clock> start;

};


#endif
