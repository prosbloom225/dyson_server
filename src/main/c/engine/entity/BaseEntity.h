#ifndef BASEENTITY_H
#define BASEENTITY_H

#include <string>
#include <iostream>
#include "include/easylogging++.h"

class BaseEntity {
    public:
        BaseEntity(double hp) { this->hp = hp; };
        void setHp(double hp) { this->hp = hp; };
        double getHp(){ return hp; };
    protected:
        double hp;
};

#endif
