#include <iostream>
#include <functional>

class Engine {
private:
    bool isRunning;

public:
    Engine() : isRunning(false) {
        std::cout << "Engine created" << std::endl;
    }
    ~Engine() {
        std::cout << "Engine destroyed" << std::endl;
    }
    
    void start() {
        if (!isRunning) {
            isRunning = true;
            std::cout << "Engine started" << std::endl;
        } else {
            std::cout << "Engine is already running" << std::endl;
        }
    }
    
    void stop() {
        if (isRunning) {
            isRunning = false;
            std::cout << "Engine stopped" << std::endl;
        } else {
            std::cout << "Engine is already stopped" << std::endl;
        }
    }
};

class Car {
private:
    Engine engine; 
    std::string name;
    int id;

public:
    Car(std::string name, int id) : name(name), id(id) {
        std::cout << "Car " << name << " (ID: " << id << ") created" << std::endl;
    }
    ~Car() {
        std::cout << "Car " << name << " (ID: " << id << ") destroyed" << std::endl;
    }
    
    void startCar() {
        std::cout << "Car " << name << " is trying to start..." << std::endl;
        engine.start();
    }
    
    void stopCar() {
        std::cout << "Car " << name << " is trying to stop..." << std::endl;
        engine.stop();
    }
    
    std::string getName() const { return name; }
    int getId() const { return id; }
};

class Garage {
private:
    Car* parkedCar1 = nullptr;
    Car* parkedCar2 = nullptr;

public:
    void parkCar(Car* car) {
        if (!parkedCar1) {
            parkedCar1 = car;
        } else if (!parkedCar2) {
            parkedCar2 = car;
        } else {
            std::cout << "Garage is full!" << std::endl;
            return;
        }
        std::cout << "Car " << car->getName() << " (ID: " << car->getId() << ") parked in garage." << std::endl;
    }
    
    void listCars() const {
        std::cout << "Cars in the garage:" << std::endl;
        if (parkedCar1) {
            std::cout << "- " << parkedCar1->getName() << " (ID: " << parkedCar1->getId() << ")" << std::endl;
        }
        if (parkedCar2) {
            std::cout << "- " << parkedCar2->getName() << " (ID: " << parkedCar2->getId() << ")" << std::endl;
        }
    }
};

int main() {
    std::cout << "--- Composition Demonstration ---" << std::endl;
    {
        Car myCar("Toyota", 1);
        myCar.startCar();
        myCar.stopCar();
    } 
    
    std::cout << "\n--- Aggregation Demonstration ---" << std::endl;
    Car car1("Honda", 2);
    Car car2("Ford", 3);
    
    Garage myGarage;
    myGarage.parkCar(&car1);
    myGarage.parkCar(&car2);
    
    myGarage.listCars();
    return 0;
}
