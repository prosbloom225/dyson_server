#include "include/catch.h"
#include "engine/entity/Player.h"

TEST_CASE("Test player constructor", "[player]") {
    LOG(INFO) << "Test player constructor";
    Player player = Player(20.0, 40.0);

    REQUIRE(player.getHp() == 20.0);
    REQUIRE(player.getMp() == 40.0);
}

TEST_CASE("Test basic player actions", "[player]") {
    Player player = Player(20.0, 40.0);
    BaseEntity defender = BaseEntity(10.0);

    //yaaa 
    player.attack = new Attack(&defender, 1);
    player.attack->execute();
    REQUIRE(defender.getHp() == 9.0);

    //yaaa 
    player.attack = new Attack(&defender, 2);
    player.attack->execute();
    REQUIRE(defender.getHp() == 7.0);
}
