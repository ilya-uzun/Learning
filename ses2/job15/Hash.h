#pragma once
#include <list>
#include <string>
#include <cmath>
#include "Person.h"

using namespace std;

// Хэш-таблица
 
class Hash {
private:
    static const int baseDegree = 10;               //Степень двойки для генерации размера таблицы
    static const int size = pow(2, baseDegree);     //Размер таблицы
    list<pair<string, Person>> table[size];           //Массив списков пар "ключ-значение", представляющий контейнерную часть хэш таблицы
private:
    int getIntKey(const string &key);               //Метод получения целочисленного ключа из строкового
    int hash(const string &key);                    //Метод - хэш-функция
    int getFilledSize();                            //Метод получения общего количества добавленных в таблицу элементов
public:
    static int getSize();                           //Метод получения размера таблицы
    bool isEmpty();                                 //Метод проверки, является ли таблица пустой
    int getCollisionNum();                          //Метод посчета коллизий
    Person search(const string &key);               //Метод поиска записи в хэш таблице по ключу
    list<Person> search(int pos);                   //Метод поиска записей в хэш таблице по номеру
    void insert(const Person &value);               //Метод вставки новой записи в хэш-таблицу
    bool remove(const string &key);                 //Метод удаления записи из хэш-таблицы
    void print();                                   //Метод вывода записей хэш-таблицы в консоль
    void clear();                                   //Метод удаления всех записей их хэш-таблицы
};

