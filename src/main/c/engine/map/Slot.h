#ifndef SLOT_H
#define SLOT_H

#include "engine/entity/BaseEntity.h"

class Slot {
    private:
        std::shared_ptr<BaseEntity> entity;
    public:
        bool isOccupied();
};

#endif
