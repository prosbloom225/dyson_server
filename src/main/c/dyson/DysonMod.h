#ifndef DYSONMOD_H
#define DYSONMOD_H

#include <string>
#include "engine/base/BaseMod.h"

class DysonMod : public BaseMod {
    private:
    public:
        DysonMod();
        const char* modName = "dyson";
        void preInit();
        void init();
        void postInit();

        /* std::string getModName(){ return modName; } */
};


#endif
