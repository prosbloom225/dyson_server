#include "Game.h"

typedef std::chrono::high_resolution_clock Clock;

BaseMod Game::mods[1];
std::vector<IAction*> Game::stack;

Game::Game() {
    // TODO - dynamic modloader
    // hardcoding mods for now
    mods[0] = BaseMod();
    for (auto& mod : mods) {
        LOG(DEBUG) << "Loading mod: " << mod.getModName();
    }
    loader();
    // TODO - pregame menu/etc .. maybe move to main?
    Game::tickrate = 1/TICKS_PER_SEC;
    // start the game loop
    lifecycle();


    // clean up
    ItemRegistry::clear();
}
void Game::loader() {
    // preInit
    for (auto& mod : mods) {
        LOG(DEBUG) << ">>>PREINIT<<<" << " - " << mod.getModName();
        mod.preInit();
    }
    // init
    for (auto& mod : mods) {
        LOG(DEBUG) << ">>>INIT<<<" << " - " << mod.getModName();
        mod.init();
    }
    // postInit
    for (auto& mod : mods) {
        LOG(DEBUG) << ">>>POSTINIT<<<" << " - " << mod.getModName();
        mod.postInit();
    }
}

void Game::lifecycle() {
    // main game loop
    tick = 0;
    while (true){
        // clock stuff
        /* auto clock = Clock::now(); */
        TimeUtils::startClock();
        tick++;
        LOG(INFO) << tick;

        /*
        char a;
        std::cin >> a;
        // q
        if (a == 113)
            break;
        else 
            std::cout << (int)a;
        */

        // world server tick
        // world server actions tick
        for (auto &action : Game::stack){
            action->onTick();
        }
        // world server entities tick
        // updateTrackedEntities - dead/alive,garbage collection,etc

        // TODO - MOVE to TimeUtils.h
        // sync with clock
        std::chrono::duration<double> diff = Clock::now() - clock;
        /*
        while (diff.count() < tickrate){
            std::this_thread::sleep_for(std::chrono::milliseconds(TIME_WAIT));
            diff = Clock::now() - clock;
        }
        */
        TimeUtils::waitForClock();

        LOG(INFO) << "Calculated TPS: ";
        LOG(INFO) << "DIFF: " << diff.count();
        LOG(INFO) << "TICK: " << tick;

        tps_history[tick] = diff.count();

        if (tick >= TICKS_PER_SEC) {
            LOG(INFO) << "lifecycle complete";
            LOG(INFO) << "OPTIMAL TICKRATE: " << tickrate;
            LOG(INFO) << "TICK" << tick;
            double sum;
            int i = 0;
            while (i < tick)  {
                sum += tps_history[i];
                i++;
            }
            LOG(INFO) << "Average TPS: " << (sum/--i);
            tick = 0;
            return;
        }
    };
}
