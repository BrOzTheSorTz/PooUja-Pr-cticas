//
// Created by admin on 03/05/2022.
//

#include "ItemApilableArrojable.h"
#include <sstream>


float ItemApilableArrojable::getDamage() const {
    return damage;
}

void ItemApilableArrojable::setDamage(float damage) {
    ItemApilableArrojable::damage = damage;
}
