#include <iostream>
using namespace std;

//Base Class: Shape
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

    //Pure virtual functions
    virtual void calculateArea() = 0;
    virtual void displayDetails() const = 0;

};


//Derived Class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, string color) : radius(r) {
        setColor(color);
        calculateArea();
    }

    void calculateArea() override {
        double result = 3.14159 * radius * radius;
        setArea(result);
    }

    void displayDetails() const override {
        cout << "Shape: Circle\n";
        cout << "Color: " << getColor() << "\n";
        cout << "Radius: " << radius << "\n";
        cout << "Area: " << getArea() << "\n\n";
    }
};

//Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w, string color) : length(l), width(w) {
        setColor(color);
        calculateArea();
    }

    void calculateArea() override {
        double result = length * width;
        setArea(result);
    }

    void displayDetails() const override {
        cout << "Shape: Rectangle\n";
        cout << "Color: " << getColor() << "\n";
        cout << "Length: " << length << "\n";
        cout << "Width: " << width << "\n";
        cout << "Area: " << getArea() << "\n\n";
    }
};

int main() {

    Shape *shapes[3];
    shapes[0] = new Circle(5, "Red");
    shapes[1] = new Rectangle(4, 6, "Blue");
    shapes[2] = new Circle(3, "Green");

    cout << "Displaying Shape Details:\n\n";
    for (int i = 0; i < 3; i++) {
        shapes[i]->displayDetails();
    }

    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}

