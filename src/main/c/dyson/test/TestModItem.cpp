
#include "include/catch.h"
#include "dyson/item/ModItem.h"
#include "dyson/item/ModItemWeapon.h"
#include "dyson/item/ModItemArmor.h"

#include <typeinfo>

TEST_CASE("Test ModItem builder defaults", "[moditem]") {
    LOG(INFO) << "Test ModItem builder defaults";
    ModItem *item = ModItem::Builder()
        .build();
    REQUIRE(strcmp(item->getModName(), "dyson") == 0);
    REQUIRE(strcmp(item->getName(), "null") == 0);
    REQUIRE(item->getEmcVal() == 0.0);
    REQUIRE(item->getIlvl() == 0);

    std::string s = typeid(item).name();
    LOG(WARNING) << s;

    delete item;
}

TEST_CASE("Test ModItem builder properties", "[moditem]") {
    LOG(INFO) << "Test ModItem builder properties";
    ModItem *item = ModItem::Builder()
        .setName("testModItem1")
        .setEmcVal(2.0)
        .setIlvl(2)
        .build();
    REQUIRE(strcmp(item->getModName(), "dyson") == 0);
    REQUIRE(strcmp(item->getName(), "testModItem1") == 0);
    REQUIRE(item->getEmcVal() == 2.0);
    REQUIRE(item->getIlvl() == 2);
    LOG(DEBUG) << item;
    
    delete item;
}

TEST_CASE("Test dyson mod Weapon building", "[moditem]") {
    LOG(INFO) << "Test dyson mod weapon building";
    ModItemWeapon *item= ModItemWeapon::Builder()
        .setName("testModItem1")
        .setEmcVal(2.0)
        .setIlvl(2)
        .setAp(5)
        .build();

    REQUIRE(strcmp(item->getModName(), "dyson") == 0);
    REQUIRE(strcmp(item->getName(), "testModItem1") == 0);
    REQUIRE(item->getEmcVal() == 2.0);
    REQUIRE(item->getAp() == 5);
    REQUIRE(item->getIlvl() == 2);
    LOG(DEBUG) << item;

    delete item;
}

TEST_CASE("Test dyson mod Armor building", "[moditem]") {
    LOG(INFO) << "Test dyson mod armor building";
    ModItemArmor *item= ModItemArmor::Builder()
        .setName("testModItem1")
        .setEmcVal(2.0)
        .setIlvl(2)
        .setPv(5.1)
        .setDv(8.8)
        .build();

    REQUIRE(strcmp(item->getModName(), "dyson") == 0);
    REQUIRE(strcmp(item->getName(), "testModItem1") == 0);
    REQUIRE(item->getEmcVal() == 2.0);
    REQUIRE(item->getIlvl() == 2);
    REQUIRE(item->getPv() == 5.1);
    REQUIRE(item->getDv() == 8.8);
    LOG(DEBUG) << item;

    delete item;
}
