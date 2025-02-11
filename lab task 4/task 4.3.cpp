//Task - 03: Implement a DynamicArray Class with the “Rule of Five”
//1. Overview:
//Create a class called DynamicArray that manages a dynamic array of integers.
//o The class should allocate and deallocate its own memory.
//o It must correctly handle copy and move operations.
//2. Details:
//o Provide these constructors and operators:
//1. Default constructor: Initializes an empty array or an array of size zero.
//2. Parameterized constructor: Accept an integer n that indicates the array size, allocate an
//array of that size, and default-initialize all elements to 0.
//3. Copy constructor: Performs a deep copy of the array.
//4. Move constructor: Efficiently transfers ownership of the dynamic array from an rvalue
//object (leaving the source in a valid but empty state).
//5. Copy assignment operator (operator=): Deep copies the array from one object to another,
//properly handling self-assignment.
//6. Move assignment operator (operator=): Transfers ownership from an rvalue object,
//deallocating any previously held memory.
//7. Destructor: Deallocates the dynamic array.
//o Provide additional member functions:
//? size(): returns the current size of the array.
//? at(int index): returns a reference to the element at index (and possibly a const version for
//read-only).
//? resize(int newSize): resizes the dynamic array to a new size, copying old data if newSize &gt;
//0.


#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* data;      
    int length;     
    void allocateMemory(int size) {
        data = new int[size]();  
        length = size;
    }
    void deallocateMemory() {
        delete[] data;
    }

public:
    DynamicArray() : data(nullptr), length(0) {}
    DynamicArray(int n) : data(nullptr), length(0) {
        if (n > 0) {
            allocateMemory(n);
        }
    }
    DynamicArray(const DynamicArray& other) : data(nullptr), length(0) {
        if (other.length > 0) {
            allocateMemory(other.length);
            for (int i = 0; i < other.length; ++i) {
                data[i] = other.data[i];
            }
        }
    }
    DynamicArray(DynamicArray&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr; 
        other.length = 0;
    }
    ~DynamicArray() {
        if (data != nullptr) {
            deallocateMemory();
        }
    }
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {  
            if (data != nullptr) {
                deallocateMemory();
            }
            if (other.length > 0) {
                allocateMemory(other.length);
                for (int i = 0; i < other.length; ++i) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
                length = 0;
            }
        }
        return *this;
    }
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) { 
            if (data != nullptr) {
                deallocateMemory();
            }
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }
    int size() const {
        return length;
    }
    int& at(int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    const int& at(int index) const {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    void resize(int newSize) {
        if (newSize == length) {
            return;
        }

        int* newData = new int[newSize](); 
        for (int i = 0; i < std::min(length, newSize); ++i) {
            newData[i] = data[i];
        }
        deallocateMemory();
        data = newData;
        length = newSize;
    }
    void print() const {
        for (int i = 0; i < length; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    DynamicArray arr1;
    std::cout << "arr1 size: " << arr1.size() << std::endl;
    DynamicArray arr2(5);
    std::cout << "arr2 size: " << arr2.size() << std::endl;
    arr2.at(0) = 10;
    arr2.at(1) = 20;
    arr2.print();
    DynamicArray arr3 = arr2;
    std::cout << "arr3 (copied from arr2): ";
    arr3.print();
    DynamicArray arr4 = std::move(arr2);
    std::cout << "arr4 (moved from arr2): ";
    arr4.print();
    arr4.resize(3);
    std::cout << "arr4 after resizing: ";
    arr4.print();
    DynamicArray arr5;
    arr5 = arr3;
    std::cout << "arr5 (after assignment from arr3): ";
    arr5.print();
    DynamicArray arr6;
    arr6 = std::move(arr5);
    std::cout << "arr6 (after move assignment from arr5): ";
    arr6.print();

    return 0;
}
