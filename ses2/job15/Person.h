#pragma once
#include <iostream>//библиотека для работы со стандартными потоками
#include <fstream> //библиотека для работы со файловыми потоками
#include <string>
using namespace std;
class Person
{
public:
    Person();
    Person(string, int, int);
    Person(const Person&);
    Person operator =(const Person&);
    // модификатор set
    void set_FIO(string);
    void set_simma(int);
    void set_account_number(int);
    // модификатор get
    const string &get_FIO() const;
    int get_simma(){return simma;}
    int get_account_number(){return account_number;}
    const string &getKey() const; // ключ
    // ввод вывод    
friend ostream& operator <<(ostream &out, const Person&p);
friend istream& operator>>(istream &in, Person &p);
// для работы с файлом
friend fstream& operator>>(fstream &fin, Person &p);
friend fstream& operator <<(fstream &fout, const Person&p);
public:
    ~Person();
private:
    string FIO; // ФИО
    int simma;  //
    int account_number; // № счёта
};