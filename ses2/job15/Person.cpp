#include "Person.h"
Person::Person()
{
    FIO = ""; 
    summa = "";
    account_number = "";
}

Person::Person(string N,string A, string I)
{
    FIO = N; 
    summa = A;
    account_number = I;
}

Person::Person(const Person&p)
{
    FIO = p.FIO;
    summa = p.summa;
    account_number = p.account_number;
}

Person Person::operator =(const Person&p)
{
if(&p==this) return *this;
    FIO = p.FIO;
    account_number = p.account_number;
    summa = p.summa;
return*this;
}
Person::~Person(){}

void Person::set_FIO(string Na)
{
    FIO = Na;
}
void Person::set_summa(string a)
{
    summa = a;
}

void Person::set_account_number(string N)
{
    account_number = N;
}

const string &Person::get_FIO() const {
    return FIO;
}

const string &Person::get_account_number() const {
    return account_number;
}

const string &Person::get_summa() const {
    return summa;
}
//  Метод получения ключа
 
const string &Person::getKey() const {
    return get_FIO();
}

// Метод возвращающий строковое представление данного объекта.
// Просто делает форматированную строку из значений полей объекта.
 
string Person::toString() const {
    return string("FIO = " + get_FIO() + ", Account number = " + get_account_number() + ", Summa = " + get_summa());
}

ostream& operator<<(ostream& out, const Person &p)
{
    return out << p.toString();
}
istream& operator>>(istream& in, Person&p)
{
    cout <<"Enter FIO: ";
    in >> p.FIO;
    cout << "Enter account number: ";
    in >> p.account_number;
    cout << "Enter summa: ";
    in >> p.summa;
return in;
}
// для работы с файлом
fstream& operator>>(fstream& fin, Person&p)
{
    fin >> p.FIO;
    fin >> p.account_number;
    fin >> p.summa;
    return fin;
}
fstream& operator<<(fstream& fout, const Person &p)
{
    fout << p.FIO <<" "<< p.account_number <<" "<< p.summa <<"\n";
    return fout;
}