#include <iostream>
#include <vector>
#include <string>

class Employee {
protected:
    std::string id;
    std::string name;

public:
    Employee(const std::string& emp_id, const std::string& emp_name)
        : id(emp_id), name(emp_name) {}

    virtual void displayInfo() const {
        std::cout << "Employee ID: " << id << ", Name: " << name << std::endl;
    }

    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;  
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;  
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill() = 0;  
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(const std::string& emp_id, const std::string& emp_name)
        : Employee(emp_id, emp_name) {}

    void takeOrder() override {
        std::cout << name << " is taking the order." << std::endl;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "Role: Waiter" << std::endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(const std::string& emp_id, const std::string& emp_name)
        : Employee(emp_id, emp_name) {}

    void prepareOrder() override {
        std::cout << name << " is preparing the order." << std::endl;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "Role: Chef" << std::endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(const std::string& emp_id, const std::string& emp_name)
        : Employee(emp_id, emp_name) {}

    void generateBill() override {
        std::cout << name << " is generating the bill." << std::endl;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "Role: Cashier" << std::endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(const std::string& emp_id, const std::string& emp_name)
        : Employee(emp_id, emp_name) {}

    void takeOrder() override {
        std::cout << name << " is taking the order." << std::endl;
    }

    void generateBill() override {
        std::cout << name << " is generating the bill." << std::endl;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << "Role: Manager (Order Taker & Biller)" << std::endl;
    }
};

class Menu {
public:
    virtual double calculateTotal() = 0;  
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
private:
    std::vector<double> foodPrices;

public:
    void addFoodItem(double price) {
        foodPrices.push_back(price);
    }

    double calculateTotal() override {
        double total = 0;
        for (double price : foodPrices) {
            total += price;
        }
        return total;
    }
};

class BeverageMenu : public Menu {
private:
    std::vector<double> beveragePrices;

public:
    void addBeverageItem(double price) {
        beveragePrices.push_back(price);
    }

    double calculateTotal() override {
        double total = 0;
        for (double price : beveragePrices) {
            total += price;
        }
        return total * 1.10;  
    }
};

void demonstratePolymorphism(std::vector<Employee*> employees) {
    for (auto emp : employees) {
        emp->displayInfo();
        if (auto orderTaker = dynamic_cast<IOrderTaker*>(emp)) {
            orderTaker->takeOrder();
        }
        if (auto orderPreparer = dynamic_cast<IOrderPreparer*>(emp)) {
            orderPreparer->prepareOrder();
        }
        if (auto biller = dynamic_cast<IBiller*>(emp)) {
            biller->generateBill();
        }
        std::cout << std::endl;
    }
}

int main() {
    FoodMenu foodMenu;
    foodMenu.addFoodItem(5.0);
    foodMenu.addFoodItem(7.5);
    
    BeverageMenu beverageMenu;
    beverageMenu.addBeverageItem(2.5);
    beverageMenu.addBeverageItem(3.0);
    
    std::cout << "Total for food menu: " << foodMenu.calculateTotal() << std::endl;
    std::cout << "Total for beverage menu (with tax): " << beverageMenu.calculateTotal() << std::endl;

    Waiter waiter("W123", "John");
    Chef chef("C456", "Alice");
    Cashier cashier("CS789", "Bob");
    Manager manager("M000", "Charlie");

    std::vector<Employee*> employees = { &waiter, &chef, &cashier, &manager };

    demonstratePolymorphism(employees);

    return 0;
}

