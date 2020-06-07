#include "Person.h"
Person::Person()
{
    FIO = ""; 
    simma = 0;
    account_number = 0;
}

Person::Person(string N,int A, int I)
{
    FIO = N; 
    simma = A;
    account_number = I;
}

Person::Person(const Person&p)
{
    FIO = p.FIO;
    simma = p.simma;
    account_number = p.account_number;
}

Person Person::operator =(const Person&p)
{
if(&p==this) return *this;
    FIO = p.FIO;
    simma = p.simma;
    account_number = p.account_number;
return*this;
}
Person::~Person(){}

void Person::set_FIO(string Na)
{
    FIO = Na;
}
void Person::set_simma(int a)
{
    simma = a;
}
void Person::set_account_number(int N)
{
    account_number = N;
}

const string &Person::get_FIO() const {
    return FIO;
}
/**
 * Метод получения ключа
 * @return
 */
const string &Person::getKey() const {
    return get_FIO();
}

ostream& operator<<(ostream& out, const Person &p)
{
    out << "FIO: " << p.FIO  <<" account_number:" << p.account_number <<" simma: "<< p.simma <<"\n";
    return out;
}
istream& operator>>(istream& in, Person&p)
{
    cout <<"Enter FIO: ";
    in >> p.FIO;
    cout << "Enter account number: ";
    in >> p.account_number;
    cout << "Enter simma: ";
    in >> p.simma;
return in;
}
// для работы с файлом
fstream& operator>>(fstream& fin, Person&p)
{
    fin >> p.FIO;
    fin >> p.account_number;
    fin >> p.simma;
    return fin;
}
fstream& operator<<(fstream& fout, const Person &p)
{
    fout << p.FIO <<" "<< p.account_number <<" "<< p.simma <<"\n";
    return fout;
}