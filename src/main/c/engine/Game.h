#ifndef GAME_H
#define GAME_H

#include "engine/registry/ItemRegistry.h"
#include "engine/base/BaseMod.h"
#include "engine/entity/actions/IAction.h"
#include "engine/entity/actions/IAction.h"

#include "engine/util/TimeUtils.h"

#include <chrono>
#include <thread>

class Game {
    public:
        Game();
        static ItemRegistry registry;
        static BaseMod mods[1];
        static std::vector<IAction*> stack;

    private:
        const double TICKS_PER_SEC = 10;
        /* static const signed int TIME_SCALER = 1; */
        const signed int TIME_WAIT = 100;  //ms to wait at end of tick to sync to clock
        double tps_history[10];
        double tickrate;
        unsigned int tick;
        void lifecycle();
        void loader();
};


#endif
