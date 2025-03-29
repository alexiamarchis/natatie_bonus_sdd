//
// Created by diana on 3/29/2025.
//

#ifndef SUBTASK3_H
#define SUBTASK3_H
#include "Duck.h"
#include "Lane.h"
#include "OrderedSet.h"

float timeDistance(Duck duck, Lane lane);
bool compareDucksResistance(const Duck &duck1, const Duck &duck2);
float bestTime(const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes);

#endif //SUBTASK3_H
