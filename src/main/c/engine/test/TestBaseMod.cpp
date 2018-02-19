#include "include/catch.h"
#include "engine/base/Items.h"

TEST_CASE("Test base mod item loading","[base]") {
    ItemRegistry::clear();
    Items::loadItems();
    // testModItem0
    Item *item = ItemRegistry::getItem(0);

    // require all properties here
    REQUIRE(strcmp(item->getName(), "testItem0") == 0);
    REQUIRE(strcmp(item->getModName(), "base") == 0);

    // testModItem1
    item = ItemRegistry::getItem(1);

    // require all properties here
    REQUIRE(strcmp(item->getName(), "testItem1") == 0);
    REQUIRE(strcmp(item->getModName(), "base") == 0);
    ItemRegistry::dumpRegistry();
    ItemRegistry::clear();
}
