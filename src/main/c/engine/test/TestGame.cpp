#include "include/catch.h"
#include "engine/Game.h"

// BEFORE

TEST_CASE("Test game constructor", "[game]") {
    LOG(INFO) << "Test game constructor";
    Game game = Game();
    REQUIRE(&game != NULL);
};
TEST_CASE("Test mod loader", "[game]") {
    LOG(INFO) << "Test mod loader";
    for (auto& mod : Game::mods){
        LOG(DEBUG) << mod.getModName();
        REQUIRE(mod.getModName().empty() == 0);
    }
};

