#include <iostream>

class Shape {
private:
    double area;

public:
    Shape(double a) : area(a) {}

    double Area() const {
        return area;
    }

    Shape operator+(const Shape& other) {
        return Shape(this->area + other.area);
    }

    void display() const {
        std::cout << "Area: " << area << std::endl;
    }
};

int main() {
    Shape shape1(10.5);
    Shape shape2(20.3);

    shape1.display();
    shape2.display();

    Shape shape3 = shape1 + shape2;
    shape3.display();

    return 0;
}

