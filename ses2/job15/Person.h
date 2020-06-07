#pragma once
#include <iostream>//библиотека для работы со стандартными потоками
#include <fstream> //библиотека для работы со файловыми потоками
#include <string>
using namespace std;
class Person
{
public:
    Person();
    Person(string, string, string);
    Person(const Person&);
    Person operator =(const Person&);
    // модификатор set
    void set_FIO(string);
    void set_summa(string);
    void set_account_number(string);
    // модификатор get
    const string &get_FIO() const;
    const string &get_summa() const;
    const string &get_account_number() const;

    string toString() const;  //Метод, возвращающий строковое представление данного объекта
    const string &getKey() const; // ключ
    // ввод вывод    
friend ostream& operator <<(ostream &out, const Person&p);
friend istream& operator >> (istream &in, Person &p);
// для работы с файлом
friend fstream& operator >> (fstream &fin, Person &p);
friend fstream& operator <<(fstream &fout, const Person&p);
public:
    ~Person();
private:
    string FIO; // ФИО
    string summa;  //
    string account_number; // № счёта
};