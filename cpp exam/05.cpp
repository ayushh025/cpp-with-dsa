#include <iostream>
using namespace std;

// Abstract Base Class
class Vehicle {
public:
    // Pure virtual functions
    virtual void startEngine() = 0;
    virtual void drive() = 0;
};

// Derived Class
class Car : public Vehicle {
public:
    void startEngine() override {
        cout << "Car engine started.." << endl;
    }

    void drive() override {
        cout << "Car is going on the road.." << endl;
    }
};


class Bike : public Vehicle {
public:
    void startEngine() override {
        cout << "Bike engine started.." << endl;
    }

    void drive() override {
        cout << "Bike is going on the road.." << endl;
    }
};

int main() {

    // Array of Vehicle pointers
    Vehicle *vehicles[2];

    vehicles[0] = new Car();
    vehicles[1] = new Bike();

    for (int i = 0; i < 2; i++) {
        vehicles[i]->startEngine();  
        vehicles[i]->drive();        
        cout << endl;
    }

    // Clean up memory
    for (int i = 0; i < 2; i++) {
        delete vehicles[i];
    }

    return 0;
}

