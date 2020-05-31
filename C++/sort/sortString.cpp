#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string>
using namespace std;

class Person
{
 
public:
    Person(string n, double a)
    {
        this->name = n;
        this->age = a; 
    }
    bool operator()(const Person &p)
    {
        return p.age > 100;
    }
    string name;
    double age;
};

 
int main(void) {
    vector<Person> people
    {
        Person("Anton", 32),
        Person("Stas", 21),
        Person("Ilia", 20),
        Person("Egor", 29),
        Person("Andrey", 31),
    };
 
    for (auto element : people)
    {
        cout << element.name << endl;
    }
}
