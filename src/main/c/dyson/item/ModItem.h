#ifndef MODITEM_H
#define MODITEM_H

#include "engine/item/Item.h"

class ModItem : public Item {
    public:
        class Builder;
    protected:
        ModItem(std::string const &modName, std::string const &itemName, int ilvl, double emcVal);
       double emcVal;
       unsigned int ilvl;

    public: 
        double getEmcVal(){ return emcVal;};
        unsigned int getIlvl(){ return ilvl;};
        friend std::ostream& operator<<(std::ostream& out, const ModItem *item){
            return out << "{\"ModItem\" : {"
                << "\"mod\" : \"" << item->modName->c_str() << "\","
                << "\"name\" : \"" << item->name->c_str() << "\","
                << "\"emcVal\" : " << item->emcVal<< ","
                << "\"ilvl\" : " << item->ilvl<< ""
                << "}}";
        }
};


class ModItem::Builder : public Item::Builder {
    protected:
        std::string name;
        std::string modName;
        double emcVal;
        unsigned int ilvl;

    public:
        static const constexpr char *defaultModName = "dyson";
        static const constexpr double defaultEmcVal = 0.0;
        static const constexpr int defaultIlvl = 0;

        Builder() : modName(std::string(defaultModName)), name(std::string(defaultName)), emcVal(defaultEmcVal), ilvl(defaultIlvl) { }


        // properties need to be overloaded else the builder returns the parent Item::Builder&
        // TODO - could maybe get away with casting as the child Builder???
        // Parent properties
        Builder& setName(std::string *name) { this->name= *name; return *this;}
        Builder& setName(const char *name) { this->name= name; return *this;}


        // Child properties
        Builder& setEmcVal(double emcVal) { this->emcVal = emcVal; return *this;}
        Builder& setIlvl(int ilvl) { this->ilvl = ilvl; return *this;}


        ModItem *build() {
            return new ModItem(this->modName, this->name, this->ilvl, this->emcVal);
        }
};

#endif
