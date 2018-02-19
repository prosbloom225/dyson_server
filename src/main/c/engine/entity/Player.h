#ifndef PLAYER_H
#define PLAYER_H

#include "BaseEntity.h"
#include "actions/Attack.h"

class Player : public BaseEntity {
    public:
        Player(double hp, double mp);
        double getMp() { return mp; };
        void setMp(double mp) { this->mp = mp; };
        class Attack *attack;
    protected:
        double mp;
};


#endif
