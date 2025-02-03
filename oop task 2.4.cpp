#include <iostream>
#include <cstring>

struct Employee {
    int employee_id;
    char name[50];
    double salary;
};

struct Organisation {
    char organisation_name[50];
    char organisation_number[20];
    Employee emp;
};

int main() {
    Organisation org;
    
    strcpy(org.organisation_name, "NU-Fast");
    strcpy(org.organisation_number, "NUFAST123ABC");
    org.emp.employee_id = 127;
    strcpy(org.emp.name, "Linus Sebastian");
    org.emp.salary = 400000;
    
    std::cout << "The size of structure organisation: " << sizeof(Organisation) << std::endl;
    std::cout << "Organisation Name: " << org.organisation_name << std::endl;
    std::cout << "Organisation Number: " << org.organisation_number << std::endl;
    std::cout << "Employee ID: " << org.emp.employee_id << std::endl;
    std::cout << "Employee Name: " << org.emp.name << std::endl;
    std::cout << "Employee Salary: " << org.emp.salary << std::endl;
    
    return 0;
}

