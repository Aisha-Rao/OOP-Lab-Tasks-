//Create a class called Employee that includes three pieces of information as instance variables—a first name (type
//String), a last name (type String) and a monthly salary (double). If the monthly salary is not positive, set it to 0.0.
//Write a test application named EmployeeTest that demonstrates class Employee’s capabilities. Create two
//Employee objects and display each object’s yearly salary. Then give each Employee a 10% raise and display each
//Employee’s yearly salary again.

#include <iostream>
using namespace std;

class Employee {
public:
    string firstName;
    string lastName;
    double monthlySalary;
    
    Employee(string fName, string lName, double salary) {
        firstName = fName;
        lastName = lName;
        monthlySalary = salary > 0 ? salary : 0.0;
    }
    
    double getYearlySalary() {
        return monthlySalary * 12;
    }
    
    void giveRaise(double percentage) {
        monthlySalary += monthlySalary * (percentage / 100);
    }
};

int main() {
    Employee emp1("John", "Doe", 3000);
    Employee emp2("Jane", "Smith", 4000);
    
    cout << "Yearly Salary of " << emp1.firstName << " " << emp1.lastName << ": $" << emp1.getYearlySalary() << endl;
    cout << "Yearly Salary of " << emp2.firstName << " " << emp2.lastName << ": $" << emp2.getYearlySalary() << endl;
    
    emp1.giveRaise(10);
    emp2.giveRaise(10);
    
    cout << "After 10% raise:" << endl;
    cout << "Yearly Salary of " << emp1.firstName << " " << emp1.lastName << ": $" << emp1.getYearlySalary() << endl;
    cout << "Yearly Salary of " << emp2.firstName << " " << emp2.lastName << ": $" << emp2.getYearlySalary() << endl;
    
    return 0;
}
#include <iostream>
using namespace std;

class Employee {
public:
    string firstName;
    string lastName;
    double monthlySalary;
    
    Employee(string fName, string lName, double salary) {
        firstName = fName;
        lastName = lName;
        monthlySalary = salary > 0 ? salary : 0.0;
    }
    
    double getYearlySalary() {
        return monthlySalary * 12;
    }
    
    void giveRaise(double percentage) {
        monthlySalary += monthlySalary * (percentage / 100);
    }
};

int main() {
    Employee emp1("John", "Doe", 3000);
    Employee emp2("Jane", "Smith", 4000);
    
    cout << "Yearly Salary of " << emp1.firstName << " " << emp1.lastName << ": $" << emp1.getYearlySalary() << endl;
    cout << "Yearly Salary of " << emp2.firstName << " " << emp2.lastName << ": $" << emp2.getYearlySalary() << endl;
    
    emp1.giveRaise(10);
    emp2.giveRaise(10);
    
    cout << "After 10% raise:" << endl;
    cout << "Yearly Salary of " << emp1.firstName << " " << emp1.lastName << ": $" << emp1.getYearlySalary() << endl;
    cout << "Yearly Salary of " << emp2.firstName << " " << emp2.lastName << ": $" << emp2.getYearlySalary() << endl;
    
    return 0;
}

