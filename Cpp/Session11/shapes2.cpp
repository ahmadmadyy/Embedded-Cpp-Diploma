#include <iostream>

class Shape {
public:
    virtual void draw(int x, int y) = 0; //pure virtual function
};

class Circle : public Shape {
public:
    void draw(int x, int y) override {
        std::cout << "Drawing a circle at position (" << x << ", " << y << ")" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw(int x, int y) override {
        std::cout << "Drawing a rectangle at position (" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Circle circle;
    Rectangle rectangle;

    Shape* shape1 = &circle;
    Shape* shape2 = &rectangle;

    shape1->draw(5, 10);
    shape2->draw(7, 15);

    return 0;
}
