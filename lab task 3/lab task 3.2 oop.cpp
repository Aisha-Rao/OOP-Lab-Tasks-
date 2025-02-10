//Create a class called Date that includes three pieces of information as instance variables—a month (typeint), a day
//(typeint) and a year (typeint). Provide a method displayDate that displays the month, day and year separated by
//forward slashes(/). Write a test application named DateTest that demonstrates classDate’s capabilities.

#include <iostream>
using namespace std;

class Date {
public:
    int month;
    int day;
    int year;
    
    Date(int m, int d, int y) : month(m), day(d), year(y) {}
    
    void displayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main() {
    Date date(2, 11, 2025);
    date.displayDate();
    
    return 0;
}
