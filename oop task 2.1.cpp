#include <iostream>
#include <cstdlib> 

class ArraySum {
private:
    int* arr;
    int size;
public:
    ArraySum(int argc, char* argv[]) {
        size = argc - 1;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = std::atoi(argv[i + 1]); 
        }
    }

    int calculateSum() {
        int sum = 0;
        int* ptr = arr;
        for (int i = 0; i < size; ++i) {
            sum += *(ptr + i); 
        }
        return sum;
    }

    ~ArraySum() {
        delete[] arr;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2> ... <numN>" << std::endl;
        return 1;
    }

    ArraySum arraySum(argc, argv);
    std::cout << "Sum of array elements: " << arraySum.calculateSum() << std::endl;
    
    return 0;
}

