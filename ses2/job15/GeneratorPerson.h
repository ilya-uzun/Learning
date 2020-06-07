#pragma once
#include "Person.h"
// #include "Utilit.h"
#include <random>
#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <ios>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <regex>

using namespace std;

/**
 * Класс "Гереатор данных"
 * Имеет предопределенный набор составных частей данных
 * И процедурно генерирует поля для объекта класса "Данные"
 * на основе генератора случайных чисел.
 */
class GeneratorPerson {
private:
    random_device rd;  //Генератор случайных чисел
    mt19937 engine;    //Генератор случайных чисел
public:
    vector<string> surnames;      //Список фамилий
    vector<string> names;         //Список имен
    vector<string> patronymics;   //Список отчеств
    vector<string> summa;         //сумма
    vector<string> account_number;     //номер счёта

    GeneratorPerson();              //Конструктор без параметров

    static vector<string> makeSurnames();     //Статический метод инциализации списка фамилий
    static vector<string> makeNames();        //Статический метод инциализации списка имен
    static vector<string> makePatronymics();  //Статический метод инциализации списка отчеств
    // static vector<string> makeSumma();    //Статический метод инциализации списка адресов
    // static vector<string> makeAccount_number();    //Статический метод инциализации списка адресов
    unsigned int getRandomNumber(unsigned int from, unsigned int to);  //Метод получения случайного числа в заданном диапазоне

    string getFIO();            //Метод получения сегенерированного значения для поля "ФИО"
    string getSumma();       //Метод получения сегенерированного значения для поля "сумма"
    string getAccount_number(); //Метод получения сегенерированного значения для поля "Номер счёта"
    Person getData();             //Метод получения объекта типа "Данные" на основе сгенерированных полей

};

