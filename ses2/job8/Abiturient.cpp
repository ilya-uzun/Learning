#include "Person.h"
#include "Abiturient.h"
Abiturient::Abiturient(void) : Person()
{
    person_ID = 0;
}
Abiturient::~Abiturient(void){}
Abiturient::Abiturient(std::string N, int A, int ID) : Person(N, A)
{
    person_ID = ID;
}
Abiturient::Abiturient(const Abiturient &L)
{
    name = L.name;
    age = L.age;
    person_ID = L.person_ID;
}
void Abiturient::Set_Person_ID(int G)
{
    person_ID = G;
}
Abiturient& Abiturient::operator=(const Abiturient &l)
{
    if (&l == this) return *this;
    name = l.name;
    age = l.age;
    person_ID = l.person_ID;
    return *this;
}
 void Abiturient::Show()
{
    std::cout << " Name : " << name << std::endl;
    std::cout << " Age : " << age << std::endl;
    std::cout << " Person_ID : " << person_ID << std::endl;
}
void Abiturient::Input()
{
    std::cout<<" Enter Name :" << std::endl;
    std::cin >> name;
    std::cout<<" Enter Age : " << std::endl;
    std::cin >> age;
    std::cout<<" Enter person_ID :" << std::endl;
    std::cin >> person_ID;
}