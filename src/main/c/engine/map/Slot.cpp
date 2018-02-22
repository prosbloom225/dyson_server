#include "Slot.h"

bool Slot::isOccupied() {
    if (entity) {
    return true;
    } else {
        return false;
    }
}
