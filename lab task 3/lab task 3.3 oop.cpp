//We are prototyping a robot that refills glasses during dinner. Every glass holds 200 milliliters. During dinner,
//people either drink water or juice, and as soon as there is less than 100 ml left in the glass, the robot refills it back
//to 200 ml.
//Create a class Glass with one public int field LiquidLevel and methods public Drink(int milliliters) that takes the
//amount of liquid that a person drank and public Refill() that refills the glass to be 200 ml full. Both methods
//should not return any value. Initially set LiquidLevel to 200. In the Main method create an object of class Glass
//and read commands from the screen until the user terminates the program (see next). Don&#39;t forget to refill the glass
//when needed!

#include <iostream>
using namespace std;

class Glass {
public:
    int LiquidLevel;
    
    Glass() : LiquidLevel(200) {}
    
    void Drink(int milliliters) {
        if (milliliters > 0 && LiquidLevel >= milliliters) {
            LiquidLevel -= milliliters;
            cout << "Drank " << milliliters << " ml. Remaining: " << LiquidLevel << " ml." << endl;
        } else {
            cout << "Not enough liquid to drink that amount!" << endl;
        }
        
        if (LiquidLevel < 100) {
            Refill();
        }
    }
    
    void Refill() {
        LiquidLevel = 200;
        cout << "Glass refilled to 200 ml." << endl;
    }
};

int main() {
    Glass glass;
    string command;
    int amount;
    
    while (true) {
        cout << "Enter 'drink' followed by an amount, or 'exit' to stop: ";
        cin >> command;
        
        if (command == "exit") {
            break;
        } else if (command == "drink") {
            cin >> amount;
            glass.Drink(amount);
        } else {
            cout << "Invalid command!" << endl;
        }
    }
    
    return 0;
}

