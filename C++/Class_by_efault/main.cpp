#include <iostream>

using namespace std;
class Student
{
    int age;
public:
    int set_age(int a)
    {
        age = a;
        return age;
    }

};
int main()
{

    Student  r; 
    cout << r; 
	return 0;
}
