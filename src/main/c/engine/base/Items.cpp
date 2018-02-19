#include "Items.h"

using json = nlohmann::json;

int Items::loadItem(int id, Item *item){
    int ret = ItemRegistry::addItem(id, item);
    return id;
}

void Items::loadItems(){
    LOG(DEBUG) << "Base itemload called";
    std::ifstream i("./src/main/resources/engine/item/BaseItems.json");
    json j;
    i >> j;
    i.close();
    for(unsigned int i=0;i < j.size();i++){
        std::string name = j[i]["name"].get<std::string>();
        int id = j[i]["id"];
        Item *item = Item::Builder()
            .setName(&name)
            .build();
        loadItem(id, item);
    }
}
