#include "ModItemWeapon.h"

ModItemWeapon::ModItemWeapon(std::string const &modName, std::string const &itemName, int ilvl, double cVal, int ap)
    : ModItem(modName, itemName, ilvl, cVal) {
    this->ap = ap;
    LOG(DEBUG) << this;
}
