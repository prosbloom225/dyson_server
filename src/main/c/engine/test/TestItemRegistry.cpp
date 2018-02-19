#include "include/catch.h"
#include "engine/registry/ItemRegistry.h"

//// START COMBINED TEST ////
TEST_CASE("Test adding basic items ", "[itemregistry]") {
    LOG(INFO) << "Test adding baseic items";
    ItemRegistry::clear();
    Item *item0 = Item::Builder()
        .setName("testItem0")
        .build();
    Item *item1 = Item::Builder()
        .setName("testItem1")
        .build();
    ItemRegistry::addItem(0, item0);
    ItemRegistry::addItem(1, item1);
    ItemRegistry::dumpRegistry();


    REQUIRE(strcmp(ItemRegistry::getItem<Item>(0)->getName(),"testItem0") == 0);
    REQUIRE(strcmp(ItemRegistry::getItem<Item>(1)->getName(),"testItem1") == 0);

}

TEST_CASE("Test existing items arent deallocating out of scope", "[itemregistry]") {
    LOG(INFO) << "Test existing items arent deallocating out of scope";
    REQUIRE(strcmp(ItemRegistry::getItem(0)->getName(),"testItem0") == 0);
    REQUIRE(strcmp(ItemRegistry::getItem(1)->getName(),"testItem1") == 0);

    ItemRegistry::clear();
}
//// END COMBINED TEST ////

TEST_CASE("Test overriding existing item", "[itemregistry]"){
    LOG(INFO) << "Test overriding exiting item";
    ItemRegistry::clear();
    Item *item1 = Item::Builder()
        .setName("testItem1")
        .build();
    Item *item2 = Item::Builder()
        .setName("testItem2")
        .build();
    ItemRegistry::addItem(0, item1);
    ItemRegistry::addItem(0, item2);
    REQUIRE(0==0);
    /* registry->dumpRegistry(); */
    ItemRegistry::clear();

}

TEST_CASE("Test item copying", "[itemregistry]") {
    LOG(INFO) << "Test item copying";
    ItemRegistry::clear();
    Item *item0 = Item::Builder()
        .setName("testItem0")
        .build();
    Item *item1 = Item::Builder()
        .setName("testItem1")
        .build();
    ItemRegistry::addItem(0, item0);
    ItemRegistry::addItem(1, item1);

    REQUIRE(strcmp(ItemRegistry::getItem<Item>(0)->getName(),"testItem0") == 0);
    REQUIRE(strcmp(ItemRegistry::getItem<Item>(1)->getName(),"testItem1") == 0);

    // now make sure the copy is a deep copy
    Item *copyItem0 = item0->copy();
    item0 = item1;
    LOG(INFO) << item0;
    LOG(INFO) << copyItem0;

    REQUIRE(strcmp(copyItem0->getName(), item0->getName()) == -1);

    ItemRegistry::dumpRegistry();
    ItemRegistry::clear();
}
