#pragma once
#include "Data.h"
#include "myUtilities.h"
#include <random>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

/**
 * Класс "Гереатор данных"
 * Имеет предопределенный набор составных частей данных
 * И процедурно генерирует поля для объекта класса "Данные"
 * на основе генератора случайных чисел.
 */
class DataGenerator {
private:
    random_device rd;  //Генератор случайных чисел
    mt19937 engine;    //Генератор случайных чисел
public:
    vector<string> surnames;      //Список фамилий
    vector<string> names;         //Список имен
    vector<string> patronymics;   //Список отчеств
    vector<string> addresses;     //Адреса

    DataGenerator();              //Конструктор без параметров

    static vector<string> makeSurnames();     //Статический метод инциализации списка фамилий

    static vector<string> makeNames();        //Статический метод инциализации списка имен

    static vector<string> makePatronymics();  //Статический метод инциализации списка отчеств

    static vector<string> makeAddresses();    //Статический метод инциализации списка адресов

    unsigned int getRandomNumber(unsigned int from, unsigned int to);  //Метод получения случайного числа в заданном диапазоне

    string getFIO();            //Метод получения сегенерированного значения для поля "ФИО"

    string getPassportNumber(); //Метод получения сегенерированного значения для поля "Номер паспорта"

    string getAddress();        //Метод получения сегенерированного значения для поля "Адрес"

    Data getData();             //Метод получения объекта типа "Данные" на основе сгенерированных полей
};

