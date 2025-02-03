//Task 3:
//Write a program that can resize a single dimension int array if the elements exceed the total size.
//Consider an int array of size 5 (uninitialized), you start adding items to the array and if the quantity of
//the elements exceeds double the array size. Once finished resizing the array again to the max quantity of
//the elements present in the array.

#include <iostream>
#include <cstdlib>

class DynamicArray {
private:
    int* arr;
    int capacity;
    int size;

    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    DynamicArray() {
        capacity = 5;
        size = 0;
        arr = new int[capacity];
    }

    void addElement(int value) {
        if (size >= capacity) {
            resize(capacity * 2);
        }
        arr[size++] = value;
    }

    void finalizeSize() {
        if (size < capacity) {
            resize(size);
        }
    }

    void printArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2> ... <numN>" << std::endl;
        return 1;
    }

    DynamicArray dynamicArray;
    for (int i = 1; i < argc; ++i) {
        dynamicArray.addElement(std::atoi(argv[i]));
    }
    
    dynamicArray.finalizeSize();
    std::cout << "Final resized array: ";
    dynamicArray.printArray();
    
    return 0;
}

