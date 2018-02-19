#ifndef ATTACK_H
#define ATTACK_H

#include "IAction.h"
#include "engine/entity/BaseEntity.h"

class Attack : IAction {
    private:
        int ticks = 1;
        int amount = 0;
        BaseEntity *defender;
    public:
        ~Attack(){};
        Attack(BaseEntity *defender, double amount);
        void onTick(){};
        void execute();
};


#endif
