//Task 6:
//Write a program that creates a dynamic array of not values but structures. Each struct would contain
//another struct and in that struct a variable of subject should exist. The outer structure should be an ID
//and an array (Fixed) for subjects. (Note you can utilize vectors for this question)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Subject {
public:
    string subject_name;

    Subject(string subject_name) {
        this->subject_name = subject_name;
    }
};

class Student {
public:
    int id;
    vector<Subject> subjects;  

    Student(int id) {
        this->id = id;
    }

    void addSubject(const string& subject_name) {
        subjects.push_back(Subject(subject_name));
    }

    void print() const {
        cout << "Student ID: " << id << endl;
        cout << "Subjects: ";
        for (const auto& subject : subjects) {
            cout << subject.subject_name << " ";
        }
        cout << endl;
    }
};

int main() {
    int N;
    
    cout << "Enter the number of students: ";
    cin >> N;

    vector<Student> students;

    for (int i = 0; i < N; ++i) {
        int id;
        cout << "\nEnter ID for student " << (i + 1) << ": ";
        cin >> id;

        Student student(id);

        int num_subjects;
        cout << "Enter number of subjects for student " << id << ": ";
        cin >> num_subjects;

        for (int j = 0; j < num_subjects; ++j) {
            string subject;
            cout << "Enter subject " << (j + 1) << ": ";
            cin.ignore();  
            getline(cin, subject);
            student.addSubject(subject);
        }

        students.push_back(student);
    }

    cout << "\nAll Students Information: \n";
    for (const auto& student : students) {
        student.print();
    }

    return 0;
}

