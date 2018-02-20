#include "TimeUtils.h"


void TimeUtils::startClock() {
    tickrate = 1/TICKS_PER_SEC;
    tick = 0;
    start = std::chrono::high_resolution_clock::now();
}

void TimeUtils::stopClock() {
    tick = 0;
}

void TimeUtils::waitForClock(){
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    while (diff.count() < tickrate){
        std::this_thread::sleep_for(std::chrono::milliseconds(TIME_WAIT));
        diff = std::chrono::high_resolution_clock::now() - start;
    }
}

double TimeUtils::getAvgTps(int ticks) {
    double sum;
    int i = 0;
    while (i < tick)  {
        sum += tps_history[i];
        i++;
    }
    i--;
    LOG(INFO) << "Average TPS: " << (sum/i);
    return (sum/i);
}
