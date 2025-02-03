//Task 5:
//Write a program that creates N structures. Inside each struct are two entities, id and name. You are
//required to first sort this structure first via ID then via the first character of the name in ascending order.
//Print all the struct data in both formations.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
    int id;
    string name;

    Person(int id, string name) {
        this->id = id;
        this->name = name;
    }
};

bool compare(const Person &p1, const Person &p2) {
    if (p1.id == p2.id) {
        return p1.name[0] < p2.name[0]; 
    }
    return p1.id < p2.id; 
}

int main() {
    int N;

    cout << "Enter the number of persons: ";
    cin >> N;
    cin.ignore();

    vector<Person> persons;

    for (int i = 0; i < N; ++i) {
        int id;
        string name;

        cout << "Enter id and name for person " << (i + 1) << ": ";
        cin >> id;
        cin.ignore(); 
        getline(cin, name); 
        
        persons.push_back(Person(id, name));
    }

    sort(persons.begin(), persons.end(), compare);

    cout << "\nPersons sorted by ID and first character of the name:\n";
    for (const auto &person : persons) {
        cout << "ID: " << person.id << ", Name: " << person.name << endl;
    }

    return 0;
}

