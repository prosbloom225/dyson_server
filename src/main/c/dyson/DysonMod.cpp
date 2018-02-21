#include "DysonMod.h"

DysonMod::DysonMod() {
    BaseMod::modName = this->modName;
    LOG(INFO) << this->getModName();
}

