#ifndef BASEMOD_H
#define BASEMOD_H

#include <string>

class BaseMod {
    private:
        const char* modName = "base";
    public:
        void preInit(){};
        void init(){};
        void postInit(){};

        std::string getModName(){ return modName; }
};


#endif
