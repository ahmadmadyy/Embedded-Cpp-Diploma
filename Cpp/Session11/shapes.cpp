#include <iostream>

class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual void display() const = 0; // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        std::cout << "Circle with radius " << radius << ", Area: " << area() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void display() const override {
        std::cout << "Rectangle with width " << width << " and height " << height << ", Area: " << area() << std::endl;
    }

    double area2() {
        return width * height;
    }
};

int main() {
    // You cannot create an instance of Shape due to its pure virtual methods
    // Shape shape; // This will result in a compilation error

    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    circle.display();
    rectangle.display();

    return 0;
}
