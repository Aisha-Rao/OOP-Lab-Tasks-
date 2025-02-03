//Task 2: You are required to pass a single dimension array to a function (type of the array can be your
//choice) and perform add operations to each element. Return the array to the main function after
//completion. One small catch is that the arguments and the return type should be void*. (Create an array
//via the main arguments)

#include <iostream>
#include <cstdlib>

class ArrayProcessor {
private:
    int* arr;
    int size;
public:
    ArrayProcessor(int argc, char* argv[]) {
        size = argc - 1;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = std::atoi(argv[i + 1]);
        }
    }

    static void* addOperation(void* array) {
        int* arr = static_cast<int*>(array);
        for (int i = 0; i < 5; ++i) { 
            arr[i] += 10;
        }
        return static_cast<void*>(arr);
    }

    void processArray() {
        arr = static_cast<int*>(addOperation(static_cast<void*>(arr)));
    }

    void printArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~ArrayProcessor() {
        delete[] arr;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2> ... <numN>" << std::endl;
        return 1;
    }

    ArrayProcessor arrayProcessor(argc, argv);
    arrayProcessor.processArray();
    std::cout << "Processed array: ";
    arrayProcessor.printArray();
    
    return 0;
}
