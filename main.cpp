#include <iostream>
#include <fstream>
#include "OrderedSet.h"
#include "Duck.h"
#include "Lane.h"

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

int main() {
    int N, K;
    ifstream inputFile("data.txt");

    if (!inputFile.is_open()) {
        cerr << "Error while opening file!" << endl;
        return 1;
    }

    inputFile >> N >> K;

    OrderedSet<Duck> ducks = readDucks(inputFile, N);
    OrderedSet<Lane> lanes = readLanes(inputFile, K);

    printDucks(ducks);
    printLanes(lanes);
    print "\n";

    // Restriction 1
    CheckSpeeds();

    // Restriction 6
    cout << "Best time into natural number: " << bestNaturalTime(ducks, lanes) << endl;

    inputFile.close();

    return 0;
}
