//Task - 02: Implement a Polynomial Class
//1. Overview:
//A Polynomial can be represented by its coefficients. For example,

//a0?+a1?x+a2?x2+…+an?xn

//Create a class Polynomial that stores these coefficients dynamically.
//2. Details:
//o Data members:
//? A dynamically allocated array of double (for coefficients).
//? An int that represents the highest power (degree) of the polynomial.
//o Constructors:

//1. Default constructor: Creates a polynomial of degree 0 with a coefficient array of size 1 (initialized to 0).
//2. Parameterized constructor: Takes an int degree and an array of double for coefficients. Copies them
//dynamically.
//3. Copy constructor: Deep copy of the coefficients.
//4. Move constructor: Transfers ownership of the coefficient array.
//5. Destructor: Cleans up the allocated memory.

//o Member functions:
//? int getDegree() const: returns the polynomial’s degree.
//? double evaluate(double x) const: computes the polynomial value at x.
//? Polynomial add(const Polynomial&amp; other) const: returns a new Polynomial that is
//the sum of the current polynomial and other.
//? Polynomial multiply(const Polynomial&amp; other) const: returns a new Polynomial
//that is the product of the two polynomials.

#include <iostream>
#include <stdexcept>
#include <cmath>

class Polynomial {
private:
    double* coefficients;
    int degree;


    void allocateMemory(int deg) {
        coefficients = new double[deg + 1]{0};  
    }
    void deallocateMemory() {
        delete[] coefficients;
    }

public:
    Polynomial() : degree(0) {
        allocateMemory(degree);
    }
    Polynomial(int deg, const double* coeffs) : degree(deg) {
        allocateMemory(degree);
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeffs[i];
        }
    }
    Polynomial(const Polynomial& other) : degree(other.degree) {
        allocateMemory(degree);
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }
    Polynomial(Polynomial&& other) noexcept : coefficients(other.coefficients), degree(other.degree) {
        other.coefficients = nullptr;
        other.degree = 0;
    }
    ~Polynomial() {
        if (coefficients != nullptr) {
            deallocateMemory();
        }
    }
    int getDegree() const {
        return degree;
    }
    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * std::pow(x, i);
        }
        return result;
    }
    Polynomial add(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        double* resultCoeffs = new double[maxDegree + 1]{0};
        for (int i = 0; i <= degree; ++i) {
            resultCoeffs[i] += coefficients[i];
        }
        for (int i = 0; i <= other.degree; ++i) {
            resultCoeffs[i] += other.coefficients[i];
        }
        Polynomial result(maxDegree, resultCoeffs);
        delete[] resultCoeffs;
        return result;
    }
    Polynomial multiply(const Polynomial& other) const {
        int resultDegree = degree + other.degree;
        double* resultCoeffs = new double[resultDegree + 1]{0};
        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        Polynomial result(resultDegree, resultCoeffs);
        delete[] resultCoeffs;
        return result;
    }
    void print() const {
        for (int i = degree; i >= 0; --i) {
            if (i < degree && coefficients[i] >= 0) {
                std::cout << "+";
            }
            std::cout << coefficients[i];
            if (i > 0) {
                std::cout << "x^" << i << " ";
            }
        }
        std::cout << std::endl;
    }
};
int main() {
    Polynomial p1;
    std::cout << "Polynomial p1 (default): ";
    p1.print();
    double coeffs1[] = {1, 2, 3}; 
    Polynomial p2(2, coeffs1);
    std::cout << "Polynomial p2: ";
    p2.print();
    double x = 2.0;
    std::cout << "p2 evaluated at x = " << x << ": " << p2.evaluate(x) << std::endl;
    Polynomial p3 = p2;
    std::cout << "Polynomial p3 (copied from p2): ";
    p3.print();
    Polynomial p4 = std::move(p2);
    std::cout << "Polynomial p4 (moved from p2): ";
    p4.print();
    double coeffs2[] = {4, 5};  
    Polynomial p5(1, coeffs2);
    std::cout << "Polynomial p5: ";
    p5.print();
    Polynomial p6 = p3.add(p5);
    std::cout << "Polynomial p6 (p3 + p5): ";
    p6.print();
    Polynomial p7 = p3.multiply(p5);
    std::cout << "Polynomial p7 (p3 * p5): ";
    p7.print();

    return 0;
}

