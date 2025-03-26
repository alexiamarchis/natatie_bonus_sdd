#pragma once

class Duck {
private:
    int id;
    int speed;
    int resistance;

public:
    // Constructors & Destructor
    Duck();
    Duck(int id, int speed, int resistance);
    Duck(const Duck& other);
    ~Duck();

    // Operator Overloads
    Duck& operator=(const Duck& other);
    bool operator<(const Duck& other) const;
    bool operator>(const Duck& other) const;
    bool operator==(const Duck& other) const;

    // Getters
    int getId() const;
    int getSpeed() const;
    int getResistance() const;

    // Setters
    void setId(int newId);
    void setSpeed(int newSpeed);
    void setResistance(int newResistance);
};
#pragma once
