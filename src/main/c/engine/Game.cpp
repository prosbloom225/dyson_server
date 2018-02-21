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
    while (true){
        // clock stuff
        TimeUtils::startClock();

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

        // sync
        TimeUtils::waitForClock();


        if (TimeUtils::getTick() >= TOTAL_TICKS) {
            LOG(INFO) << "lifecycle complete";
            LOG(INFO) << "TICK: " << TimeUtils::getTick();
            TimeUtils::getAvgTps(10);
            return;
        }
    };
}
