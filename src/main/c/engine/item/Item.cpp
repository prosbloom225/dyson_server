#include "Item.h"


Item::Item(std::string const &modName, std::string const &itemName){
    this->name = new std::string(itemName);
    this->modName = new std::string(modName);
    /* LOG(DEBUG) << this; */
}

Item::~Item() {
    delete modName;
    delete name;
}

Item *Item::copy() {
    Item *ret = this;
    // copy constructor does a deep copy?
    /* Item *ret; */
    /* memcpy(&ret, this, sizeof(this)); */
    void *a = this;
    LOG(DEBUG) << "address of original: " << a;
    LOG(DEBUG) << "address of new:      " << &ret;
    return ret;
}
