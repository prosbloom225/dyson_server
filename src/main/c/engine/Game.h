#ifndef GAME_H
#define GAME_H

#include "engine/registry/ItemRegistry.h"
#include "engine/base/BaseMod.h"
#include "engine/entity/actions/IAction.h"
#include "engine/entity/actions/IAction.h"

#include "engine/util/TimeUtils.h"


#include "dyson/DysonMod.h"

#include <chrono>
#include <thread>

class Game {
    public:
        Game();
        static ItemRegistry registry;
        static BaseMod mods[2];
        static std::vector<IAction*> stack;

    private:
        const double TOTAL_TICKS = 10;
        /* static const signed int TIME_SCALER = 1; */
        void lifecycle();
        void loader();
};


#endif
