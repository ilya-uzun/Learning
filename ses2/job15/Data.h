#pragma once
#include <string>
#include <iostream>

using namespace std;

/**
 * Класс "Данные"
 */
class Data {
private:
    string FIO;               //ФИО
    string passportNumber;    //Номер паспорта
    string address;           //Адресс
public:
    //КОНСТРУКТОРЫ
    Data(const string &fio, const string &passportNumber, const string &address);

    Data(const Data &data);

    Data();

    //ДЕСТРУКТОР
    virtual ~Data();

    //СЕЛЕКТОРЫ И МОДИФИКАТОРЫ полей
    const string &getFio() const;

    void setFio(const string &fio);

    const string &getPassportNumber() const;

    void setPassportNumber(const string &passportNumber_);

    const string &getAddress() const;

    void setAddress(const string &address_);

    const string &getKey() const;   //Метод получения ключа

    string toString() const;  //Метод, возвращающий строковое представление данного объекта

    friend ostream &operator<<(ostream &out, const Data &np);  //Перегруженный оператор вывода в консоль
};

