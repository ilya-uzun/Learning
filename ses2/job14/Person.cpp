#include "Person.h"
Person::Person()
{
    name = ""; 
    age = 0;
}

Person::Person(string N,int A, int I)
{
    name = N; 
    age = A;
    number = I;
}

Person::Person(const Person&p)
{
    name = p.name;
    age = p.age;
    number = p.number;
}

Person Person::operator =(const Person&p)
{
if(&p==this) return *this;
    name = p.name;
    age = p.age;
    number = p.number;
return*this;
}
Person::~Person(){}

void Person::set_name(string Na)
{
    name = Na;
}
void Person::set_age(int a)
{
    age = a;
}
void Person::set_number(int N)
{
    number = N;
}
ostream& operator<<(ostream& out, const Person &p)
{
    out << "ID: " << p.number <<" name: "<<p.name<<" age:"<<p.age <<"\n";
    return out;
}
istream& operator>>(istream& in, Person&p)
{
    cout <<"Enter name: ";
    in >> p.name;
    cout << "Enter age: ";
    in >> p.age;
    cout << "Enter number element: ";
    in >> p.number;
return in;
}
// для работы с файлом
fstream& operator>>(fstream& fin, Person&p)
{
    fin >> p.number;
    fin >> p.name;
    fin >> p.age;
    return fin;
}
fstream& operator<<(fstream& fout, const Person &p)
{
    fout << p.number <<" " << p.name <<" "<< p.age <<"\n";
    return fout;
}