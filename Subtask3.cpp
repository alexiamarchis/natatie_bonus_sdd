//
// Created by diana on 3/29/2025.
//

#include "Subtask3.h"
#include "OrderedSet.h"
#include "Duck.h"
#include "Lane.h"
#include <iostream>

using namespace std;


float timeDistance(Duck duck, Lane lane) {
    return (float(lane.getLength() * 2)) / duck.getSpeed();
}

bool compareDucksResistance(const Duck &duck1, const Duck &duck2) {
    if (duck1.getResistance() <= duck2.getResistance())
        return false;
    return true;
}

float bestTime(const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes) {
    OrderedSet<Duck> ducks_copy = ducks;
    ducks_copy.setComparator(compareDucksResistance); // sorting the copy array

    float min_time = 10000;

    for (int i = 0; i < ducks_copy.size(); i++) {

        ducks_copy.remove(ducks_copy.getElem(i));

        float max_time = 0;
        int pos_lane = 0;

        for (int j = 0; j < ducks_copy.size() && pos_lane < lanes.size(); j++) {
            float time = timeDistance(ducks_copy.getElem(i), lanes.getElem(j));
            if (time > max_time)
                max_time = time;
        }

        if (max_time < min_time)
            min_time = max_time;

        ducks_copy.add(ducks_copy.getElem(i));
    }
    return min_time;
}

