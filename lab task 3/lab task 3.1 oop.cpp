//Create a class User with two public fields: int Age and string Name. In the Main method, create an object of class
//User and set Name to &quot;Teo&quot; and Age to 24. Then, output to the screen: &quot;My name is {Name} and I&#39;m {Age} years
//old.&quot; using object fields for Name and Age.

#include <iostream>
using namespace std;

class User {
public:
    int Age;
    string Name;
};

int main() {
    User user;
    user.Name = "Aisha Rao";
    user.Age = 19;
    
    cout << "My name is " << user.Name << " and I'm " << user.Age << " years old." << endl;
    
    return 0;
}


