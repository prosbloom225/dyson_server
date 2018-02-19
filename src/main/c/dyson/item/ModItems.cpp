#include "ModItems.h"

using json = nlohmann::json;

int ModItems::loadItem(int id, ModItem *item){
    int ret = ItemRegistry::addItem(id, item);
    return id;
}
void ModItems::loadItems(){
    LOG(DEBUG) << "Mod itemload called";
    /* std::ifstream i("./src/main/resources/dyson/item/ModItems.json"); */
    std::ifstream i(LibMisc::MODITEMS_JSON);
    json j;
    i >> j;
    i.close();
    for(unsigned int i=0;i < j.size();i++){
        ModItem *item = ModItemFactory(j[i]);
        loadItem(j[i]["id"], item);
    }
}

ModItem* ModItems::ModItemFactory(json json) {
    // base props
    std::string type = json["type"].get<std::string>();
    std::string name = json["name"].get<std::string>();
    double emcVal = json["emcVal"];
    int id = json["id"];
    int ilvl = json["ilvl"];

    //
    ModItem *item;

    if (type.compare("WEAPON") == 0) {
        LOG(DEBUG) << "Building Weapon item...";
        item = ModItemWeapon::Builder()
            .setAp(json["ap"])
            .setName(&name)
            .setEmcVal(emcVal)
            .setIlvl(ilvl)
            .build();
        LOG(DEBUG) << "Built item: " << static_cast<ModItemWeapon*>(item);
    } else if (type.compare("ARMOR") == 0) {
        LOG(DEBUG) << "Building Armor item...";
        item = ModItemArmor::Builder()
            .setPv(json["pv"])
            .setDv(json["dv"])
            .setName(&name)
            .setEmcVal(emcVal)
            .setIlvl(ilvl)
            .build();
        LOG(DEBUG) << "Built item: " << static_cast<ModItemArmor*>(item);
    } else {
        std::cout << "Default";
        item = ModItem::Builder()
            .setName(&name)
            .setEmcVal(emcVal)
            .setIlvl(ilvl)
            .build();
    }
    LOG(DEBUG) << "Loaded from json: " << id << " - " << item;
    return item;
}

