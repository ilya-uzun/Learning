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

void Person::set_number(int N)
{
    number = N;
}
ostream& operator<<(ostream& out, const Person &p)
{
    out<<"number:" <<p.number<<"name: "<<p.name<<" age:"<<p.age <<"\n";
    return out;
}
istream& operator>>(istream& in, Person&p)
{
    cout <<"name? ";
    in >> p.name;
    cout << "age? ";
    in >> p.age;
    // cout << "number?";
    // in >> p.number;
return in;
}
// для работы с файлом
fstream& operator>>(fstream& fin, Person&p)
{
    // fin >> p.number;
    fin >> p.name;
    fin >> p.age;
    return fin;
}
fstream& operator<<(fstream& fout, const Person &p)
{
    fout << p.number <<" " << p.name <<" "<< p.age <<"\n";
    return fout;
}