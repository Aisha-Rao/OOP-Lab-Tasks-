#include <iostream>
#include <string>

class Vehicles {
protected:
    double price;

public:
    Vehicles(double price) : price(price) {}

    virtual void displayDetails() const = 0;

    virtual ~Vehicles() {}
};

class Car : public Vehicles {
protected:
    int seatingCapacity;
    int numberOfDoors;
    std::string fuelType;

public:
    Car(double price, int seatingCapacity, int numberOfDoors, const std::string& fuelType)
        : Vehicles(price), seatingCapacity(seatingCapacity), numberOfDoors(numberOfDoors), fuelType(fuelType) {}

    void displayDetails() const override {
        std::cout << "Price: " << price << "\nSeating Capacity: " << seatingCapacity
                  << "\nNumber of Doors: " << numberOfDoors << "\nFuel Type: " << fuelType;
    }
};

class Motorcycle : public Vehicles {
protected:
    int numberOfCylinders;
    int numberOfGears;
    int numberOfWheels;

public:
    Motorcycle(double price, int numberOfCylinders, int numberOfGears, int numberOfWheels)
        : Vehicles(price), numberOfCylinders(numberOfCylinders), numberOfGears(numberOfGears), numberOfWheels(numberOfWheels) {}

    void displayDetails() const override {
        std::cout << "Price: " << price << "\nNumber of Cylinders: " << numberOfCylinders
                  << "\nNumber of Gears: " << numberOfGears << "\nNumber of Wheels: " << numberOfWheels;
    }
};

class Audi : public Car {
private:
    std::string modelType;

public:
    Audi(double price, int seatingCapacity, int numberOfDoors, const std::string& fuelType, const std::string& modelType)
        : Car(price, seatingCapacity, numberOfDoors, fuelType), modelType(modelType) {}

    void displayDetails() const override {
        Car::displayDetails();
        std::cout << "\nModel Type: " << modelType << std::endl;
    }
};

class Yamaha : public Motorcycle {
private:
    std::string makeType;

public:
    Yamaha(double price, int numberOfCylinders, int numberOfGears, int numberOfWheels, const std::string& makeType)
        : Motorcycle(price, numberOfCylinders, numberOfGears, numberOfWheels), makeType(makeType) {}

    void displayDetails() const override {
        Motorcycle::displayDetails();
        std::cout << "\nMake Type: " << makeType << std::endl;
    }
};

int main() {
    Audi audi(50000, 5, 4, "Petrol", "A6");
    Yamaha yamaha(15000, 4, 5, 2, "YZF-R1");

    std::cout << "Audi Car Details:\n";
    audi.displayDetails();
    std::cout << std::endl;

    std::cout << "Yamaha Motorcycle Details:\n";
    yamaha.displayDetails();

    return 0;
}

