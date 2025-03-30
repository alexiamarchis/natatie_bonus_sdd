//
#include "Lane.h"
#include "Duck.h"
#include "Lane.h"
#include "OrderedSet.h"

bool descendingLanes(const Lane& l1, const Lane& l2) {
    if (l1.getLength() != l2.getLength())
        return l1.getLength() > l2.getLength();
    return l1.getId() > l2.getId();
}

bool descendingDucks(const Duck& d1, const Duck& d2) {
    if (d1.getSpeed() != d2.getSpeed())
        return d1.getSpeed() > d2.getSpeed();
    return d1.getId() > d2.getId();
}

double task_2(int N, int M, const OrderedSet<Duck>& ducks, const OrderedSet<Lane>& lanes) {

    OrderedSet<Lane> sortedLanes(descendingLanes);
    for (int i = 0; i < M; i++) {
        sortedLanes.add(lanes.getElem(i));
    }


    OrderedSet<Duck> sortedDucks(descendingDucks);
    for (int i = 0; i < M; i++) {
        sortedDucks.add(ducks.getElem(i));
    }

    double mx = 0;
    for (int i = 0; i < M; i++) {
        Duck d = sortedDucks.getElem(i);
        Lane l = sortedLanes.getElem(i);
        double time = (2.0 * l.getLength()) / d.getSpeed();
        if (time > mx)
            mx = time;
    }

    return mx;
}