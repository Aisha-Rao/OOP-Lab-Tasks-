#include <iostream>
#include <string>

class Person {
protected:
    int employeeID;

public:
    void getData(int id) {
        employeeID = id;
    }

    void displayData() const {
        std::cout << "Employee ID: " << employeeID << std::endl;
    }
};

class Admin : public Person {
protected:
    std::string name;
    double monthlyIncome;

public:
    void getData(int id, const std::string& n, double income) {
        Person::getData(id);
        name = n;
        monthlyIncome = income;
    }

    void displayData() const {
        Person::displayData();
        std::cout << "Name: " << name << std::endl;
        std::cout << "Monthly Income: " << monthlyIncome << std::endl;
    }

    double bonus() const {
        return monthlyIncome * 0.05 * 12;
    }
};

class Accounts : public Person {
protected:
    std::string name;
    double monthlyIncome;

public:
    void getData(int id, const std::string& n, double income) {
        Person::getData(id);
        name = n;
        monthlyIncome = income;
    }

    void displayData() const {
        Person::displayData();
        std::cout << "Name: " << name << std::endl;
        std::cout << "Monthly Income: " << monthlyIncome << std::endl;
    }

    double bonus() const {
        return monthlyIncome * 0.05 * 12;
    }
};

int main() {
    Admin admin1;
    Accounts accounts1;

    admin1.getData(101, "John Doe", 5000);
    accounts1.getData(102, "Jane Smith", 4000);

    admin1.displayData();
    std::cout << "Annual Bonus: " << admin1.bonus() << std::endl << std::endl;

    accounts1.displayData();
    std::cout << "Annual Bonus: " << accounts1.bonus() << std::endl;

    return 0;
}

