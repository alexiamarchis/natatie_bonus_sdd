
#ifndef TASK4_H
#define TASK4_H
#include "Duck.h"
#include "Lane.h"
#include "OrderedSet.h"
void calculare_timp_optim(int n, int m, const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes, double timpi[]);
bool valid(double timp,int n, int m, const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes);
double cautare(int n, int m, const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes, double timpi[]);
void bubbleSort_timp(double timp[], int n);
#endif