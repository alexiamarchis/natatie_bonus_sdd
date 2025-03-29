//
// Created by HP on 29.03.2025.
//
#include "Lane.h"
#include "Duck.h"
#include "Lane.h"
#include "OrderedSet.h"


double task_2(int N, int M, const OrderedSet<Duck>&ducks, const OrderedSet<Lane>&lanes){

    double mx=0;
     for(int i=0; i<M; i++)
       {
        Duck d=ducks.getElem(i);  
        Lane l=lanes.getElem(i);
        double time=(2.0* l.getLength()/d.getSpeed());
        if(time>mx)
          mx=time;
}
return mx;
}
