#include "include/catch.h"
#include "dyson/item/ModItems.h"

#include <typeinfo>

TEST_CASE("Test dyson mod item loading","[dyson]") {
    LOG(INFO) << "Test dyson mod item loading";
    ItemRegistry::clear();
    ModItems::loadItems();

    // testModItem0
    auto *item = ItemRegistry::getItem<ModItemWeapon>(10);

    // test typing
    LOG(WARNING) << "TYPE: " << typeid(item).name();
    REQUIRE(strcmp(typeid(item).name(), "P13ModItemWeapon") == 0);


    // require all properties here
    REQUIRE(strcmp(item->getName(), "testModItem0") == 0);
    REQUIRE(strcmp(item->getModName(), "dyson") == 0);
    REQUIRE(item->getIlvl() == 1);
    REQUIRE(item->getEmcVal() == 7.7);
    REQUIRE(item->getAp() == 7);

    // testModItem1
    auto *item1 = ItemRegistry::getItem<ModItemArmor>(11);

    // require all properties here
    REQUIRE(strcmp(item1->getName(), "testModItem1") == 0);
    REQUIRE(strcmp(item1->getModName(), "dyson") == 0);
    REQUIRE(item1->getIlvl() == 5);
    REQUIRE(item1->getEmcVal() == 33.0);
    /* REQUIRE(item1->getPv() == 2.1); */
    /* REQUIRE(item1->getDv() == 6.6); */

    //
    ItemRegistry::dumpRegistry();
}
