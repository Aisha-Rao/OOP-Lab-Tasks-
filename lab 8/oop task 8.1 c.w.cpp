#include <iostream>
#include <numeric>

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        if (denominator == 0) {
            std::cout << "Error: Denominator cannot be zero!" << std::endl;
            numerator = 0;
            denominator = 1;
            return;
        }

        int gcd = std::gcd(numerator, denominator);

        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        int commonDenom = denominator * other.denominator;
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        return Fraction(newNumerator, commonDenom);
    }

    Fraction operator-(const Fraction& other) const {
        int commonDenom = denominator * other.denominator;
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        return Fraction(newNumerator, commonDenom);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            std::cout << "Error: Cannot divide by a fraction with zero numerator!" << std::endl;
            return Fraction(0, 1);
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(other < *this);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(2, 4), f2(3, 6);
    std::cout << (f1 + f2) << std::endl;
    std::cout << (f1 - f2) << std::endl;
    std::cout << (f1 * f2) << std::endl;
    std::cout << (f1 / f2) << std::endl;

    std::cout << (f1 == f2) << std::endl;
    std::cout << (f1 != f2) << std::endl;

    Fraction f3(0, 1);
    std::cout << "Enter a fraction in the form numerator/denominator: ";
    std::cin >> f3;
    std::cout << "You entered: " << f3 << std::endl;
    
    return 0;
}

