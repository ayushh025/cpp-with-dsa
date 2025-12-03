#include <iostream>
using namespace std;

//Base Class
class Shape {
private:
    string color;
    double area;

public:
    //Setters
    void setColor(string c) {
        color = c;
    }

    void setArea(double a) {
        area = a;
    }

    //Getters
    string getColor() const {
        return color;
    }

    double getArea() const {
        return area;
    }

    // Virtual function to calculate area
    virtual void calculateArea() = 0;
};

//Derived Class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    void calculateArea() override {
        double result = 3.14 * radius * radius;
        setArea(result);
    }
};

//Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    void calculateArea() override {
        double result = length * width;
        setArea(result);
    }
};

int main() {
    Circle c(5);
    c.setColor("Red");
    c.calculateArea();

    cout << "Circle Color: " << c.getColor() << endl;
    cout << "Circle Area: " << c.getArea() << endl << endl;

    // Rectangle object
    Rectangle r(4, 6);
    r.setColor("Blue");
    r.calculateArea();

    cout << "Rectangle Color: " << r.getColor() << endl;
    cout << "Rectangle Area: " << r.getArea() << endl;

    return 0;
}

