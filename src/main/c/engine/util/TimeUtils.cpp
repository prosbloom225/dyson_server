#include "TimeUtils.h"


signed int TimeUtils::tick;
std::chrono::time_point<std::chrono::high_resolution_clock> TimeUtils::start;
double TimeUtils::tps_history[10]; // TODO - this should be dynamic or set in config
const signed int TimeUtils::TIME_WAIT = 10;  // ms to wait at end of tick to sync to clock




int TimeUtils::getTick() {
    return tick;
}
void TimeUtils::startClock() {
    LOG(INFO) << "Starting clock";
    start = std::chrono::high_resolution_clock::now();
}

void TimeUtils::waitForClock(){
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;

    double tickrate = 0.1;

    while (diff.count() < tickrate){
        /* LOG(INFO) << "Waiting for clock..." << diff.count() << " " << tickrate; */
        std::this_thread::sleep_for(std::chrono::milliseconds(TIME_WAIT));
        diff = std::chrono::high_resolution_clock::now() - start;
    }
    LOG(INFO) << "TICK: " << tick << " - Time: " << diff.count();
    tps_history[tick] = diff.count();
    tick++;
    /* LOG(INFO) << "Wait complete!"; */
}

double TimeUtils::getAvgTps(int ticks) {
    double sum;
    int tick = 0;
    while (--ticks>0)  {
        sum += tps_history[tick++];
    }
    LOG(INFO) << "Average TPS: " << (sum/tick);
    return (sum/tick);
}
