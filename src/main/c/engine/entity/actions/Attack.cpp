#include "Attack.h"

Attack::Attack(BaseEntity *defender, double amount){
    this->amount = amount;
    this->defender = defender;
}
void Attack::execute(){
    LOG(INFO) << "Attack: " << defender->getHp() << "-" << amount;
    defender->setHp(defender->getHp() - amount);
    delete this;
}
