#include "Game.h"

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
        tick++;
        LOG(INFO) << tick%TIME_SCALER;
        if (tick%TIME_SCALER == 0){
            LOG(INFO)<<"TICK: " << tick;
        }
        char a;
        std::cin >> a;
        // q
        if (a == 113)
            break;
        else 
            std::cout << (int)a;
        // world server tick
        // world server actions tick
        for (auto &action : Game::stack){
            action->onTick();
        }
        // world server entities tick
        // updateTrackedEntities - dead/alive,garbage collection,etc

        // sanity
        if (tick > 20)
            break;
    };
}
