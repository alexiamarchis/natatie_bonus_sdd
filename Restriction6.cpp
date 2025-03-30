
//
// Created by Miana on 29.03.2025.
//

#include <iostream>
#include <cmath>
#include "Duck.h"
#include "OrderedSet.h"
#include "Lane.h"
using namespace std;

float calculateDistance(Duck duck, Lane lane)
{
    return (float(lane.getLength() * 2)) / duck.getSpeed();
}

bool compareDuckResistance(const Duck &duck1, const Duck &duck2)
{
    return duck1.getResistance() < duck2.getResistance(); // Ordine crescătoare pentru rezistenta
}

float bestNaturalTime(const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes)
{
    // Facem o copie a setului de rate pentru a le modifica fara a afecta setul original
    OrderedSet<Duck> ducks_copy = ducks;
    ducks_copy.setComparator(compareDuckResistance);

    float minTime = 10000;

    // Iteram prin toate combinatiile de rate și linii
    for (int i = 0; i < ducks_copy.size(); i++)
    {
        Duck currentDuck = ducks_copy.getElem(i);
        float maxTimeForCurrentDuck = 0;  // Initializam timpul maxim pentru raaa curenta

        // Calculam timpul maxim pentru rata curenta, pe toate liniile
        for (int j = 0; j < lanes.size(); j++)
        {
            Lane currentLane = lanes.getElem(j);

            // Calculam timpul pe aceasta linie pentru rata curenta
            float time = calculateDistance(currentDuck, currentLane);

            // Luam timpul maxim pentru rata curenta
            maxTimeForCurrentDuck = max(maxTimeForCurrentDuck, time);
        }

        minTime = min(minTime, maxTimeForCurrentDuck);
    }

    return round(minTime);
}
