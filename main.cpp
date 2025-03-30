#include <iostream>
#include <fstream>
#include "task1.h"
#include "task4.h"
//#include "task_2.h"
using namespace std;

bool compareDucks(const Duck& d1, const Duck& d2) {
    if (d1.getSpeed() != d2.getSpeed())
        return d1.getSpeed() > d2.getSpeed();
    return d1.getResistance() > d2.getResistance();
}

bool compareLanes(const Lane& l1, const Lane& l2) {
    if (l1.getLength() != l2.getLength())
        return l1.getLength() < l2.getLength();
    return l1.getId() < l2.getId();
}

bool all_resistances_all_eq(const OrderedSet<Duck>& ds, int N) {

    Duck d = ds.getElem(0);
    int val = d.getResistance();
    for (int i = 1; i < N; i++) {
        d = ds.getElem(i);
        if (val != d.getResistance())
            return false;

    }
    return true;
}

OrderedSet<Duck> readDucks(ifstream& inputFile, int N) {
    OrderedSet<Duck> ducks(compareDucks);
    int* speeds = new int[N];
    int* resistances = new int[N];

    for (int i = 0; i < N; i++) {
        inputFile >> speeds[i];
    }

    for (int i = 0; i < N; i++) {
        inputFile >> resistances[i];
    }

    for (int i = 0; i < N; i++) {
        ducks.add(Duck(i + 1, speeds[i], resistances[i]));
    }

    delete[] speeds;
    delete[] resistances;

    return ducks;
}

OrderedSet<Lane> readLanes(ifstream& inputFile, int K) {
    OrderedSet<Lane> lanes(compareLanes);
    int* lengths = new int[K];

    for (int i = 0; i < K; i++) {
        inputFile >> lengths[i];
    }

    for (int i = 0; i < K; i++) {
        lanes.add(Lane(i + 1, lengths[i]));
    }

    delete[] lengths;

    return lanes;
}

void printDucks(const OrderedSet<Duck>& ducks) {
    cout << "Ordered ducks:\n";
    for (int i = 0; i < ducks.size(); i++) {
        Duck d = ducks.getElem(i);
        cout << "Id: " << d.getId() << ", Speed: " << d.getSpeed()
            << ", Resistance: " << d.getResistance() << '\n';
    }
}

void printLanes(const OrderedSet<Lane>& lanes) {
    cout << "\nOrdered lanes:\n";
    for (int i = 0; i < lanes.size(); i++) {
        Lane l = lanes.getElem(i);
        cout << "Id: " << l.getId() << ", Length: " << l.getLength() << '\n';
    }
}
bool duckies(const Duck& d1, const Duck& d2)
{
    if (d1.getResistance() > d2.getResistance())
        return false;
    else if (d1.getResistance() == d2.getResistance())
        if (d1.getSpeed() > d2.getSpeed())
            return false;
    return true;
}
void optiuni()
{
    cout << "Task 1 :Vitezele tuturor rațelor sunt egale\n";
    cout << "Task 2 :Nivelul de rezistență al tuturor rațelor este acelaşi.\n";
    cout << "Task 3 :N-M=1\n";
    cout << "Task 4 :1 ≤ M ≤ N ≤ 100 și nivelul de rezistenţă al raţei i are valoarea i, 1 ≤ i ≤ N\n";
    cout << "Task 6 :Rezultatul este un număr natural\n";
    cout << "Task 7 :Fără restricții suplimentare.\n";

}
int main() {
    int N, K;
   
    ifstream inputFile("C:/Users/Brigitte/Desktop/problema/problema/data.txt");

    if (!inputFile.is_open()) {
        cerr << "Error while opening file!" << endl;
        return 1;
    }

    inputFile >> N >> K;
    
    OrderedSet<Duck> ducks = readDucks(inputFile, N);
    OrderedSet<Lane> lanes = readLanes(inputFile, K);


    double timpi[1000] = { 0 };
    ducks.setComparator(duckies);
    double raspuns = cautare(N, K, ducks, lanes, timpi);
    cout << raspuns << " ";
  

    return 0;
}
