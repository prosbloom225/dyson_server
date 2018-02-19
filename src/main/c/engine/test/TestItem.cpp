#include "include/catch.h"
#include "engine/item/Item.h"

TEST_CASE("Test basic item defaults", "[item]") {
    Item *item = Item::Builder()
        .build();

    // require all properties here
    REQUIRE(strcmp(item->getName(), "null") == 0);
    REQUIRE(strcmp(item->getModName(), "base") == 0);

    delete item;
}

TEST_CASE("Test basic item properties", "[item]") {
    Item *item = Item::Builder()
        .setModName("test")
        .setName("testItem0")
        .build();

    // require all properties here
    REQUIRE(strcmp(item->getName(), "testItem0") == 0);
    REQUIRE(strcmp(item->getModName(), "test") == 0);
    
    delete item;
}

