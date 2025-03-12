#include <iostream>
#include <string>
#include <vector>

class Student {
protected:
    std::string name;
    int rollNumber;

public:
    Student(const std::string& name, int rollNumber) : name(name), rollNumber(rollNumber) {}

    void displayStudentDetails() const {
        std::cout << "Name: " << name << "\nRoll Number: " << rollNumber << std::endl;
    }
};

class Marks : public Student {
protected:
    std::vector<int> marks;

public:
    Marks(const std::string& name, int rollNumber, const std::vector<int>& marks)
        : Student(name, rollNumber), marks(marks) {}

    void displayMarks() const {
        std::cout << "Marks Obtained: ";
        for (int mark : marks) {
            std::cout << mark << " ";
        }
        std::cout << std::endl;
    }
};

class Result : public Marks {
public:
    Result(const std::string& name, int rollNumber, const std::vector<int>& marks)
        : Marks(name, rollNumber, marks) {}

    void calculateTotalAndAverage() const {
        int total = 0;
        for (int mark : marks) {
            total += mark;
        }
        double average = static_cast<double>(total) / marks.size();
        std::cout << "Total Marks: " << total << "\nAverage Marks: " << average << std::endl;
    }
};

int main() {
    std::vector<int> marks = {85, 90, 78, 92, 88};
    Result result("John Doe", 12345, marks);

    result.displayStudentDetails();
    result.displayMarks();
    result.calculateTotalAndAverage();

    return 0;
}

