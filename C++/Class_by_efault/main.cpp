#include <iostream>

using namespace std;
class Student
{
    int age;
public:
    int get_age()
    {
        age = 12;
        return age;
    }

};
int main()
{
    Student  r;   
    cout << r.get_age();
	return 0;
}
