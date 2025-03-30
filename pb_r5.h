//
// Created by Mircea Alex on 3/29/2025.
//
#include "Duck.h"
#include "Lane.h"
#include "OrderedSet.h"
#ifndef PB_R5_H
#define PB_R5_H
bool comp_ducks(const Duck &d1, const Duck &d2) ;
float rezolvare_restrictie5(OrderedSet<Duck> &ducks, OrderedSet<Lane> & lanes, OrderedSet<Duck> &duckPos);
#endif //PB_R5_H
