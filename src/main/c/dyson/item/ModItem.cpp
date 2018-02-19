#include "ModItem.h"

ModItem::ModItem(std::string const &modName, std::string const &itemName, int ilvl, double emcVal)
    : Item(modName, itemName) {
    this->emcVal = emcVal;
    this->ilvl = ilvl;
    LOG(DEBUG) << this;
}
