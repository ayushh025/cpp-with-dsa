#include <iostream>
#include <string>
using namespace std;

// ---------------- Base Class ----------------
class Vehicle {
protected:
    string id, manufacturer, model;
    int year;

public:
    static int totalVehicles;

    Vehicle(){ 
		totalVehicles++; 
	}

    Vehicle(string id, string m, string mo, int y)
        : id(id), manufacturer(m), model(mo), year(y)
    {
        totalVehicles++;
    }

    ~Vehicle(){ 
		totalVehicles--; 
	}

    // Getters
    string getID() { return id; }

    virtual void display() {
        cout << "ID: " << id
             << " | Manufacturer: " << manufacturer
             << " | Model: " << model
             << " | Year: " << year;
    }
};

int Vehicle::totalVehicles = 0;

// ---------------- Derived Classes ----------------

// Single Inheritance
class Car : public Vehicle {
protected:
    string fuelType;
public:
    Car() {}
    Car(string id, string m, string mo, int y, string fuel)
        : Vehicle(id, m, mo, y), fuelType(fuel) {}

    void display() override {
        Vehicle::display();
        cout << "| Fuel: " << fuelType;
    }
};

// Multilevel Inheritance
class ElectricCar : public Car {
protected:
    int batteryCapacity;
public:
    ElectricCar() {}
    ElectricCar(string id, string m, string mo, int y, string fuel, int cap)
        : Car(id, m, mo, y, fuel), batteryCapacity(cap) {}

    void display() override {
        Car::display();
        cout << "| Battery: " << batteryCapacity << " kWh";
    }
};

// Base Class for Multiple Inheritance
class Aircraft {
protected:
    int flightRange;
public:
    Aircraft() {}
    Aircraft(int range) : flightRange(range) {}
};

// Multiple Inheritance
class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar() {}
    FlyingCar(string id, string m, string mo, int y, string fuel, int range)
        : Car(id, m, mo, y, fuel), Aircraft(range) {}

    void display() {
        Car::display();
        cout << "| Flight Range: " << flightRange << " km";
    }
};

// Multilevel from ElectricCar
class SportsCar : public ElectricCar {
protected:
    int topSpeed;
public:
    SportsCar() {}
    SportsCar(string id, string m, string mo, int y, string fuel,
              int cap, int speed)
        : ElectricCar(id, m, mo, y, fuel, cap), topSpeed(speed) {}

    void display() override {
        ElectricCar::display();
        cout << "| Top Speed: " << topSpeed << " km/h";
    }
};

// Hierarchical Inheritance
class Sedan : public Car {
public:
    Sedan(string id="", string m="", string mo="", int y=0, string fuel="")
        : Car(id, m, mo, y, fuel) {}
};

class SUV : public Car {
public:
    SUV(string id="", string m="", string mo="", int y=0, string fuel="")
        : Car(id, m, mo, y, fuel) {}
};

// ---------------- Vehicle Registry ----------------

class VehicleRegistry {
    Vehicle* list[100];
    int count;

public:
    VehicleRegistry() : count(0) {}

    void addVehicle(Vehicle* v) {
        if (count < 100) {
            list[count++] = v;
        }
    }

    void viewAll() {
        if (count == 0) {
            cout << "\nNo vehicles available.\n";
            return;
        }

        cout << "\n--- All Vehicles ---\n";
        for (int i = 0; i < count; i++) {
            list[i]->display();
            cout << endl;
        }
    }

    void searchByID(string id) {
        for (int i = 0; i < count; i++) {
            if (list[i]->getID() == id) {
                cout << "\nVehicle Found:\n";
                list[i]->display();
                cout << endl;
                return;
            }
        }
        cout << "\nVehicle not found.\n";
    }
};

// ---------------- Main Function (Menu) ----------------

int main() {
    VehicleRegistry reg;
    int choice;

    do {
        cout << "\n===== VEHICLE REGISTRY MENU =====\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search by ID\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "\nSelect Vehicle Type:\n";
            cout << "1. Car\n2. Electric Car\n3. Flying Car\n4. Sports Car\n5. Sedan\n6. SUV\n";
            cout << "Enter type: ";
            cin >> type;

            string id, m, mo, fuel;
            int y, cap, range, speed;

            cout << "ID: "; cin >> id;
            cout << "Manufacturer: "; cin >> m;
            cout << "Model: "; cin >> mo;
            cout << "Year: "; cin >> y;

            switch (type) {
                case 1:
                    cout << "Fuel Type: "; cin >> fuel;
                    reg.addVehicle(new Car(id, m, mo, y, fuel));
                    break;

                case 2:
                    cout << "Fuel Type: "; cin >> fuel;
                    cout << "Battery Capacity: "; cin >> cap;
                    reg.addVehicle(new ElectricCar(id, m, mo, y, fuel, cap));
                    break;

                case 3:
                    cout << "Fuel Type: "; cin >> fuel;
                    cout << "Flight Range: "; cin >> range;
                    reg.addVehicle(new FlyingCar(id, m, mo, y, fuel, range));
                    break;

                case 4:
                    cout << "Fuel Type: "; cin >> fuel;
                    cout << "Battery Capacity: "; cin >> cap;
                    cout << "Top Speed: "; cin >> speed;
                    reg.addVehicle(new SportsCar(id, m, mo, y, fuel, cap, speed));
                    break;

                case 5:
                    cout << "Fuel Type: "; cin >> fuel;
                    reg.addVehicle(new Sedan(id, m, mo, y, fuel));
                    break;

                case 6:
                    cout << "Fuel Type: "; cin >> fuel;
                    reg.addVehicle(new SUV(id, m, mo, y, fuel));
                    break;
            }

            cout << "\nVehicle Added!\n";
        }

        else if (choice == 2) {
            reg.viewAll();
        }

        else if (choice == 3) {
            string id;
            cout << "Enter ID to search: ";
            cin >> id;
            reg.searchByID(id);
        }

    } while (choice != 4);

    cout << "\nThank you for using Vehicle Registry System!\n";
    return 0;
}
