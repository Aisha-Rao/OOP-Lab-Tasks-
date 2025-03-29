#include <iostream>
#include <vector>
#include <string>

class PolynomialUtils;

class Polynomial {
private:
    std::vector<int> coefficients;

public:
    Polynomial() {}

    Polynomial(const std::vector<int>& coeffs) : coefficients(coeffs) {
        while (coefficients.size() > 1 && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

    Polynomial operator+(const Polynomial& other) const {
        int max_size = std::max(coefficients.size(), other.coefficients.size());
        std::vector<int> result(max_size, 0);

        for (int i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }

        for (int i = 0; i < other.coefficients.size(); ++i) {
            result[i] += other.coefficients[i];
        }

        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        int max_size = std::max(coefficients.size(), other.coefficients.size());
        std::vector<int> result(max_size, 0);

        for (int i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }

        for (int i = 0; i < other.coefficients.size(); ++i) {
            result[i] -= other.coefficients[i];
        }

        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        int result_size = coefficients.size() + other.coefficients.size() - 1;
        std::vector<int> result(result_size, 0);

        for (int i = 0; i < coefficients.size(); ++i) {
            for (int j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) {
            os << "0";
            return os;
        }

        bool first_term = true;
        for (int i = p.coefficients.size() - 1; i >= 0; --i) {
            int coeff = p.coefficients[i];
            if (coeff == 0) continue;

            if (!first_term && coeff > 0) {
                os << " + ";
            } else if (coeff < 0) {
                os << " - ";
                coeff = -coeff;
            }

            if (i == 0 || coeff != 1) {
                os << coeff;
            }

            if (i > 0) {
                os << "x";
                if (i > 1) {
                    os << "^" << i;
                }
            }

            first_term = false;
        }
        return os;
    }

    friend class PolynomialUtils;
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        int power_of_x = 1;

        for (int coeff : p.coefficients) {
            result += coeff * power_of_x;
            power_of_x *= x;
        }

        return result;
    }

    static Polynomial derivative(const Polynomial& p) {
        std::vector<int> derivative_coeffs;

        for (int i = 1; i < p.coefficients.size(); ++i) {
            derivative_coeffs.push_back(p.coefficients[i] * i);
        }

        return Polynomial(derivative_coeffs);
    }
};

int main() {
    Polynomial p1({2, -3, 0, 5});
    Polynomial p2({1, 0, -4});

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    std::cout << "p1 + p2: " << sum << std::endl;
    std::cout << "p1 - p2: " << diff << std::endl;
    std::cout << "p1 * p2: " << prod << std::endl;

    int eval_p1_at_2 = PolynomialUtils::evaluate(p1, 2);
    std::cout << "p1 evaluated at x = 2: " << eval_p1_at_2 << std::endl;

    Polynomial derivative_p1 = PolynomialUtils::derivative(p1);
    std::cout << "Derivative of p1: " << derivative_p1 << std::endl;

    return 0;
}

