#include "include/catch.h"
#include "engine/map/Map.h"

TEST_CASE("Test basic map generation", "[map]") {

    // require all properties here
    /* REQUIRE(strcmp(item->getModName(), "test") == 0); */
    Map *map = new Map();


    delete map;

}
