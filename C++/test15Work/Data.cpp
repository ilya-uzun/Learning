#include "Data.h"

/**
 * Конструктор без параметров
 */
Data::Data() = default;

/**
 * Конструктор с параметрами
 * @param fio
 * @param passportNumber
 * @param address
 */
Data::Data(const string &fio, const string &passportNumber, const string &address) {
    this->FIO = fio;
    this->passportNumber = passportNumber;
    this->address = address;
}

/**
 * Конструктор копирования
 * @param data
 */
Data::Data(const Data &data) {
    this->FIO = data.FIO;
    this->passportNumber = data.passportNumber;
    this->address = data.address;
}

/**
 * Деструктор
 */
Data::~Data() = default;

/**
 * Метод получения ключа
 * @return
 */
const string &Data::getKey() const {
    return getPassportNumber();
}

/**
 * Метод получения значения поля "ФИО"
 * @return
 */
const string &Data::getFio() const {
    return FIO;
}

/**
 * Метод учтановки значения поля "ФИО"
 * @param fio
 */
void Data::setFio(const string &fio) {
    this->FIO = fio;
}

/**
 * Метод получения значения поля "Номер паспорта"
 * @return
 */
const string &Data::getPassportNumber() const {
    return passportNumber;
}

/**
 * Метод установки значения поля "Номер паспорта"
 * @param passportNumber_
 */
void Data::setPassportNumber(const string &passportNumber_) {
    this->passportNumber = passportNumber_;
}

/**
 * Метод получения значения поля "Адресс"
 * @return
 */
const string &Data::getAddress() const {
    return address;
}

/**
 * Метод установки значения поля "Адресс"
 * @param address_
 */
void Data::setAddress(const string &address_) {
    this->address = address_;
}

/**
 * Метод возвращающий строковое представление данного объекта.
 * Просто делает форматированную строку из значений полей объекта.
 * @return
 */
string Data::toString() const {
    return string("ФИО = " + getFio() + ", Номер паспорта = " + getPassportNumber() + ", Адрес = " + getAddress());
}

/**
 * Перегруженный оператор вывода в консоль
 * @param out
 * @param data
 * @return
 */
ostream &operator<<(ostream &out, const Data &data) {
    return out << data.toString();
}



