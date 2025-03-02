#include <iostream>

class Blend {
public:
    void blendJuice() {
        std::cout << "Blending juice..." << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "Blending... " << (i + 1) << " seconds" << std::endl;
            for (volatile int j = 0; j < 100000000; j++); // Simple delay loop
        }
        std::cout << "Blending complete!" << std::endl;
    }
};

class Grind {
public:
    void grindJuice() {
        std::cout << "Grinding juice..." << std::endl;
        for (volatile int i = 0; i < 500000000; i++); // Simple delay loop
        std::cout << "Grinding complete!" << std::endl;
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void makeJuice() {
        std::cout << "Starting juice making process..." << std::endl;
        blender.blendJuice();
        grinder.grindJuice();
        std::cout << "Juice is ready!" << std::endl;
    }
};

int main() {
    std::cout << "--- Juice Maker Demonstration ---" << std::endl;
    JuiceMaker myJuicer;
    myJuicer.makeJuice();
    return 0;
}

