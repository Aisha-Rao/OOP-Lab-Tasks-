//Task - 01: Design a Matrix Class with Multiple Constructors
//Create a class Matrix that represents a 2D matrix of double values. It must handle row-major dynamic
//allocation internally.
//Details:

//o Constructors:
//1. Default constructor: Initializes a 0x0 matrix (rows = 0, cols = 0) or a nullptr-managed
//array.
//2. Parameterized constructor (rows, cols): Allocates a 2D matrix of size rows x cols.
//Initialize elements to 0.
//3. Copy constructor: Deep copy.
//4. Move constructor: Transfers ownership of the matrix data.
//5. Destructor: Deallocates the dynamic memory.
//o Member functions:
// getRows() and getCols() to return the dimensions.
// at(int r, int c): returns a reference to the element at row r, column c.
// fill(double value): fills the entire matrix with the provided value.
// transpose(): returns a new Matrix object that is the transpose of the current matrix. Make
//sure to print it as well.

#include <iostream>
#include <stdexcept>
class Matrix {
private:
    int rows, cols;
    double** data;
    void allocateMemory(int r, int c) {
        data = new double*[r];
        for (int i = 0; i < r; ++i) {
            data[i] = new double[c]{0}; 
        }
    }
    void deallocateMemory() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
public:
    Matrix() : rows(0), cols(0), data(nullptr) {}
    Matrix(int r, int c) : rows(r), cols(c) {
        allocateMemory(r, c);
    }
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocateMemory(other.rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(other.data) {
        other.rows = 0;
        other.cols = 0;
        other.data = nullptr;
    }
    ~Matrix() {
        if (data != nullptr) {
            deallocateMemory();
        }
    }
    int getRows() const {
        return rows;
    }
    int getCols() const {
        return cols;
    }
    double& at(int r, int c) {
        if (r >= rows || c >= cols || r < 0 || c < 0) {
            throw std::out_of_range("Index out of range");
        }
        return data[r][c];
    }
    void fill(double value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = value;
            }
        }
    }
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        result.print();
        return result;
    }
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};
int main() {
    
    Matrix m1;
    std::cout << "Matrix m1 (default constructor):" << std::endl;
    m1.print();
    Matrix m2(3, 3);
    std::cout << "\nMatrix m2 (3x3):" << std::endl;
    m2.print();
    m2.fill(5.0);
    std::cout << "\nMatrix m2 after filling with 5.0:" << std::endl;
    m2.print();
    Matrix m3 = m2;
    std::cout << "\nMatrix m3 (copied from m2):" << std::endl;
    m3.print();
    Matrix m4 = std::move(m2);
    std::cout << "\nMatrix m4 (moved from m2):" << std::endl;
    m4.print();
    Matrix m5 = m3.transpose();
    std::cout << "\nMatrix m5 (transpose of m3):" << std::endl;
    m5.print();

    return 0;
}
