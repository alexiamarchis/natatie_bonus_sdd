
//
// Created by Miana on 29.03.2025.
//

#include <iostream>
#include <fstream>
#include "Duck.h"
using namespace std;

void setUniformSpeed(Duck duck[], int n)
{
    int fixedSpeed = duck[0].getSpeed();  // Viteza primei rate
    for (int i = 0; i < n; i++)
    {
        duck[i].setSpeed(fixedSpeed);  // Setam viteza pentru toate ratele
    }
}

bool checkEqualSpeeds(const Duck duck[], int n)
{
    int initialSpeed = duck[0].getSpeed();
    for (int i = 1; i < n; i++)
    {
        if (duck[i].getSpeed() != initialSpeed)
        {
            return false;  // Daca gasim o viteza diferita, returnam false
        }
    }
    return true;  // Daca toate au aceeasi viteza, returnam true
}

void CheckSpeeds()
{
    int n = 1000;
    Duck duck[1000];  // Presupunem un maxim de 1000 de rate

    setUniformSpeed(duck, n); // Impunem aceeasi viteza pentru toate ratele

    if (checkEqualSpeeds(duck, n))
    {
        cout << "All ducks have the same speed" << endl;
    }
    else
    {
        cout << "Not all ducks have the same speed" << endl;
    }
}
