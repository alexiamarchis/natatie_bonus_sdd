//
// Created by Mircea Alex on 3/29/2025.
//
#include "pb_r5.h"
#include "Duck.h"
#include "OrderedSet.h"
#include "pbr5_test.h"
#include <assert.h>

void testCompFunc() {
    Duck d1(1,4,5);
    Duck d2(2,5,2);
    Duck d3(3,3,2);
    Duck d4(4,6,6);
    Duck D[4]{d1,d2,d3,d4};
    for (int i = 0; i < 3; i++)
        for (int j = i+1; j < 4; j++)
            if (comp_ducks(D[i],D[j]) == false) {
                Duck copy = D[i];
                D[i] = D[j];
                D[j] = copy;
            }
    assert(D[0] == d3 && D[1] == d2 && D[2] == d1 && D[3] == d4);
    Duck dd[4]{d1,d2,d3,d4};
    OrderedSet<Duck> d(dd,4,4);
    assert(d.getElem(0) == d1 && d.getElem(1) == d2 && d.getElem(2) == d3 && d.getElem(3) == d4);
    d.setComparator(comp_ducks);
    assert(d.getElem(0) == d3 && d.getElem(1) == d2 && d.getElem(2) == d1 && d.getElem(3) == d4);

}

void testRezEx() {
    Duck d1(1,4,5);
    Duck d2(2,5,2);
    Duck d3(3,3,2);
    Duck dd2[3]{d1,d2,d3};

    Lane l1(1,3 ), l2(2,7);
    Lane ll[2]{l1,l2};

    OrderedSet<Duck> ducks(dd2,3,3);
    OrderedSet<Lane> lanes(ll,2,2);

    assert(lanes.getElem(0) == l1 && lanes.getElem(1) == l2);

    OrderedSet<Duck> dkPos;
    float sol = rezolvare_restrictie5(ducks,lanes,dkPos);
    ///std:: cout << '\n' << "SOLUTIA ESTE" << '\n'<< sol << '\n';
    float b = 2.8;
    assert(sol == b);
    assert(dkPos.getElem(0) == d3 && dkPos.getElem(1) == d2);

}