#include <iostream>

class Car {
public:
    int engine_horsepower;
    int seating_capacity;
    int no_of_speakers;

    Car(int hp, int seats, int speakers) : engine_horsepower(hp), seating_capacity(seats), no_of_speakers(speakers) {}
    
    void displayCarDetails() const {
        std::cout << "Engine Horsepower: " << engine_horsepower << std::endl;
        std::cout << "Seating Capacity: " << seating_capacity << std::endl;
        std::cout << "Number of Speakers: " << no_of_speakers << std::endl;
    }
    
    void modifyCarAttributes(int hp, int seats, int speakers) const {
        const_cast<Car*>(this)->engine_horsepower = hp;
        const_cast<Car*>(this)->seating_capacity = seats;
        const_cast<Car*>(this)->no_of_speakers = speakers;
    }
};

int main() {
    Car myCar(150, 5, 6);
    std::cout << "Initial Car Details:" << std::endl;
    myCar.displayCarDetails();
    
    myCar.modifyCarAttributes(200, 4, 8);
    std::cout << "\nModified Car Details:" << std::endl;
    myCar.displayCarDetails();
    
    return 0;
}
