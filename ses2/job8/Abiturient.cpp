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
Abiturient& Abiturient::operator=(const Abiturient&l)
{
    if (&l == this) return *this;
    mark = l.mark;
    power = l.power;
    cyl = l.cyl;
    return *this;
}
 void Abiturient::Show()
{
    std::cout << "\nMARK : " << mark;
    std::cout << "\nCYL : " << cyl;
    std::cout << "\nPOWER : " << power;
    std::cout << "\nGRUZ : " << gruz;
    std::cout << "\n";
}
void Abiturient::Input()
{
    std::cout<<"\nMark:";
    std::cin >> mark;
    std::cout<<"\nPower:"; 
    std::cin >> power;
    std::cout<<"\nCyl:"; 
    std::cin >> cyl;
    std::cout<<"\nGRUZ : ";
    std::cin >> gruz;
}