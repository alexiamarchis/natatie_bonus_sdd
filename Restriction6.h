
//
// Created by Miana on 29.03.2025.
//

#ifndef RESTRICTION6_H
#define RESTRICTION6_H

#include "Lane.h"
#include "OrderedSet.h"

float calculateDistance(Duck duck, Lane lane);
bool compareDuckResistance(const Duck &duck1, const Duck &duck2);
float bestNaturalTime(const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes);

#endif //RESTRICTION6_H
