#include "Duck.h"

Duck::Duck() {
    id = 0;
    speed = 0;
    resistance = 0;
}

Duck::Duck(int id, int speed, int resistance) {
    this->id = id;
    this->speed = speed;
    this->resistance = resistance;
}

Duck::Duck(const Duck& other) {
    this->id = other.id;
    this->speed = other.speed;
    this->resistance = other.resistance;
}

Duck::~Duck() {
    // no dynamic allocation
}

Duck& Duck::operator=(const Duck& other) {
    if (this != &other) {
        this->id = other.id;
        this->speed = other.speed;
        this->resistance = other.resistance;
    }
    return *this;
}

bool Duck::operator<(const Duck& other) const {
    if (this->speed < other.speed) {
        return true;
    }
    else if (this->speed == other.speed) {
        return this->resistance < other.resistance;
    }
    return false;
}

bool Duck::operator>(const Duck& other) const {
    return other < *this;  //using overload operator <
}

bool Duck::operator==(const Duck& other) const {
    return (this->id == other.id &&
        this->speed == other.speed &&
        this->resistance == other.resistance);
}

int Duck::getId() const {
    return this->id;
}

int Duck::getSpeed() const {
    return this->speed;
}

int Duck::getResistance() const {
    return this->resistance;
}

void Duck::setId(int newId) {
    this->id = newId;
}

void Duck::setSpeed(int newSpeed) {
    this->speed = newSpeed;
}

void Duck::setResistance(int newResistance) {
    this->resistance = newResistance;
}
