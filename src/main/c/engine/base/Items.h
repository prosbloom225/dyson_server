#ifndef ITEMS_H
#define ITEMS_H

#include "include/json.h"

#include "engine/item/Item.h"
#include "engine/registry/ItemRegistry.h"

class Items {
    private:
        static int loadItem(int id, Item *item);
    public:
        static void loadItems();
};

#endif
