#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class BigInteger {
private:
    std::vector<int> digits;
    bool is_negative;

    void remove_leading_zeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            is_negative = false;
        }
    }

public:
    BigInteger() : is_negative(false) {
        digits.push_back(0);
    }

    BigInteger(const std::string& str) {
        is_negative = (str[0] == '-');
        for (int i = str.size() - 1; i >= (is_negative ? 1 : 0); --i) {
            digits.push_back(str[i] - '0');
        }
        remove_leading_zeros();
    }

    BigInteger operator+(const BigInteger& other) const {
        if (is_negative == other.is_negative) {
            BigInteger result;
            result.is_negative = is_negative;
            int carry = 0;
            int size = std::max(digits.size(), other.digits.size());
            for (int i = 0; i < size || carry != 0; ++i) {
                int sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            result.remove_leading_zeros();
            return result;
        } else {
            if (is_negative) {
                BigInteger positive_this = *this;
                positive_this.is_negative = false;
                return other - positive_this;
            } else {
                BigInteger positive_other = other;
                positive_other.is_negative = false;
                return *this - positive_other;
            }
        }
    }

    BigInteger operator-(const BigInteger& other) const {
        if (is_negative != other.is_negative) {
            BigInteger positive_other = other;
            positive_other.is_negative = !other.is_negative;
            return *this + positive_other;
        } else {
            if (*this < other) {
                BigInteger result = other - *this;
                result.is_negative = !is_negative;
                return result;
            }

            BigInteger result;
            result.is_negative = is_negative;
            int borrow = 0;
            int size = std::max(digits.size(), other.digits.size());
            for (int i = 0; i < size || borrow != 0; ++i) {
                int diff = digits[i] - borrow;
                if (i < other.digits.size()) diff -= other.digits[i];
                if (diff < 0) {
                    diff += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }
                result.digits.push_back(diff);
            }
            result.remove_leading_zeros();
            return result;
        }
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.is_negative = (is_negative != other.is_negative);
        result.digits.resize(digits.size() + other.digits.size(), 0);

        for (int i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (int j = 0; j < other.digits.size() || carry != 0; ++j) {
                int prod = result.digits[i + j] + digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                result.digits[i + j] = prod % 10;
                carry = prod / 10;
            }
        }
        result.remove_leading_zeros();
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return is_negative == other.is_negative && digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (is_negative != other.is_negative) {
            return is_negative;
        }
        if (digits.size() != other.digits.size()) {
            return is_negative ? digits.size() > other.digits.size() : digits.size() < other.digits.size();
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return is_negative ? digits[i] > other.digits[i] : digits[i] < other.digits[i];
            }
        }
        return false;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
        if (num.is_negative) os << "-";
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            os << num.digits[i];
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigInteger& num) {
        std::string str;
        is >> str;
        num = BigInteger(str);
        return is;
    }
};

int main() {
    BigInteger num1, num2;
    std::cin >> num1 >> num2;
    std::cout << "Sum: " << num1 + num2 << std::endl;
    std::cout << "Difference: " << num1 - num2 << std::endl;
    std::cout << "Product: " << num1 * num2 << std::endl;
    return 0;
}

