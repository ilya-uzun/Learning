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
    std::cout << "\n Name : " << name;
    std::cout << "\n Age : " << age;
    std::cout << "\n Person_ID : " << person_ID;
}
void Abiturient::Input()
{
    std::cout<<"\n Enter Name :";
    std::cin >> name;
    std::cout<<"\n Enter Age : "; 
    std::cin >> age;
    std::cout<<"\n Enter person_ID :"; 
    std::cin >> person_ID;
}