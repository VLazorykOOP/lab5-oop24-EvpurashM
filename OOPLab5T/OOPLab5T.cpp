#include <iostream>
using namespace std;

// Base class
class Transport {
public:
    Transport() {
        cout << "Transport created.\n";
    }

    virtual ~Transport() {
        cout << "Transport destroyed.\n";
    }

    virtual void printInfo() const {
        cout << "This is a transport.\n";
    }
};

// Derived class - Car
class Car : public Transport {
public:
    Car() {
        cout << "Car created.\n";
    }

    ~Car() override {
        cout << "Car destroyed.\n";
    }

    void printInfo() const override {
        cout << "This is a car.\n";
    }
};

// Derived class - Truck
class Truck : public Transport {
public:
    Truck() {
        cout << "Truck created.\n";
    }

    ~Truck() override {
        cout << "Truck destroyed.\n";
    }

    void printInfo() const override {
        cout << "This is a truck.\n";
    }
};

// Derived class - Steamship
class Steamship : public Transport {
public:
    Steamship() {
        cout << "Steamship created.\n";
    }

    ~Steamship() override {
        cout << "Steamship destroyed.\n";
    }

    void printInfo() const override {
        cout << "This is a steamship.\n";
    }
};

// Derived class - Airplane
class Airplane : public Transport {
public:
    Airplane() {
        cout << "Airplane created.\n";
    }

    ~Airplane() override {
        cout << "Airplane destroyed.\n";
    }

    void printInfo() const override {
        cout << "This is an airplane.\n";
    }
};

// Testing program
int main() {
    Transport* vehicles[] = {
        new Car(),
        new Truck(),
        new Steamship(),
        new Airplane()
    };

    cout << "\nVehicle information:\n";
    for (Transport* v : vehicles) {
        v->printInfo();
    }

    cout << "\nReleasing memory:\n";
    for (Transport* v : vehicles) {
        delete v;
    }

    return 0;
}
