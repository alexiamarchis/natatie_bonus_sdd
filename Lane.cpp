#include "Lane.h"

Lane::Lane() {
    this->id = 0;
    this->length = 0;
}

Lane::Lane(int id, int length) {
    this->id = id;
    this->length = length;
}

Lane::Lane(const Lane& other) {
    this->id = other.id;
    this->length = other.length;
}

Lane::~Lane() {

}

Lane& Lane::operator=(const Lane& other) {
    if (this != &other) {
        this->id = other.id;
        this->length = other.length;
    }
    return *this;
}

bool Lane::operator<(const Lane& other) const {
    return this->length < other.length;
}

bool Lane::operator>(const Lane& other) const {
    return other < *this; //using overload operator <
}

bool Lane::operator==(const Lane& other) const {
    return (this->id == other.id && this->length == other.length);
}

// Metode Getters
int Lane::getId() const {
    return this->id;
}

int Lane::getLength() const {
    return this->length;
}

// Metode Setters
void Lane::setId(int newId) {
    this->id = newId;
}

void Lane::setLength(int newLength) {
    this->length = newLength;
}
