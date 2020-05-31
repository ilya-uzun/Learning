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
    void set_name(string);
    void set_age(int);
    void set_number(int);
    string get_name(){return name;}
    int get_age(){return age;}
    int get_number(){return number;}
friend ostream& operator <<(ostream &out, const Person&p);
friend istream& operator>>(istream &in, Person &p);
// для работы с файлом
friend fstream& operator>>(fstream &fin, Person &p);
friend fstream& operator <<(fstream &fout, const Person&p);
public:
    ~Person();
private:
    string name;
    int age;
    int number;
};