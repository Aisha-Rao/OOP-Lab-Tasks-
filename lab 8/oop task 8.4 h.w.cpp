#include <iostream>

class Number {
private:
    int value;

public:
    Number(int val) : value(val) {}

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() const {
        std::cout << value << std::endl;
    }
};

int main() {
    Number num(16);

    num.display();

    --num;
    num.display();

    num--;
    num.display();

    return 0;
}

