/* #define CATCH_CONFIG_RUNNER */
#define CATCH_CONFIG_MAIN
#include "include/catch.h"
#include "include/easylogging++.h"


INITIALIZE_EASYLOGGINGPP



/*
int main(int argc, char* argv[]) {
    LOG(INFO) << "Begin!";

    // This is really just a test main, will move to testRunner
    return Catch::Session().run( argc, argv );
}
*/

/*
TEST_CASE("Test adding basic items ", "[itemregistry]") {
    ItemRegistry *registry = new ItemRegistry();
    Item *item1 = new Item("testItem1");
    Item *item2 = new Item("testItem2");
    registry->addItem(0, item1);
    registry->addItem(1, item2);
    //registry->dumpRegistry();

    Item *tmpItem1 = registry->getItem(0);
    LOG(DEBUG) << tmpItem1;
    REQUIRE(0==0);
}

TEST_CASE("Test overriding existing item", "[itemregistry]"){
    ItemRegistry *registry = new ItemRegistry();
    Item *item1 = new Item("testItem1");
    Item *item2 = new Item("testItem2");
    registry->addItem(0, item1);
    registry->addItem(0, item2);
    //registry->dumpRegistry();
    std::cout << item1;
    REQUIRE(0==0);
}
*/


