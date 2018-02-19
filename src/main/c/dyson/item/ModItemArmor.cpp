#include "ModItemArmor.h"

ModItemArmor::ModItemArmor(std::string const &modName, std::string const &itemName, int ilvl, double emcVal, double pv, double dv)
    : ModItem(modName, itemName, ilvl, emcVal) {
    this->pv = pv;
    this->dv = dv;
    LOG(DEBUG) << this;
}
