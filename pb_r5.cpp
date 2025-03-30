//
// Created by Mircea Alex on 3/29/2025.
//
#include "Duck.h"
#include "Lane.h"
#include "OrderedSet.h"
#include <fstream>
#include<iostream>
bool comp_ducks(const Duck &d1, const Duck &d2) {
    if (d1.getResistance() > d2.getResistance())
        return false;
    else if (d1.getResistance() == d2.getResistance())
        if (d1.getSpeed() >d2.getSpeed())return false;
    return true;
}
float rezolvare_restrictie5(OrderedSet<Duck> &ducks, OrderedSet<Lane> & lanes, OrderedSet<Duck> &duckPos) {
    ducks.setComparator(comp_ducks);
    int d_len = ducks.size();
    int l_len = lanes.size();
    float maxtime = 0;

    for (int i = l_len - 1; i >= 0; i-- ) {
        int vmax = 0, vmax_poz = 0;

        for (int j = d_len - 1; j >= i; j--) {
            if (ducks.getElem(j).getSpeed() > vmax) {
                vmax = ducks.getElem(j).getSpeed();
                vmax_poz = j;
            }
        }

        duckPos.add(ducks.getElem(vmax_poz));
        float time = float((lanes.getElem(i).getLength() * 2.0)/ducks.getElem(vmax_poz).getSpeed());
        ///std:: cout << '\n' << "TIMPUL ESTE : " << '\n'<< time << '\n';
        if (time > maxtime)
            maxtime = time;
        d_len = vmax_poz ;
    }
    return maxtime;
}