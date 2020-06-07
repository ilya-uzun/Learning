#pragma once
#include "Person.h"
#include "GeneratorPerson.h"
#include "Hash.h"
#include "myUtilities.h"

using namespace std;

/**
 *Перечисление "Тип поиска"
 */
enum SearchType {
    BY_KEY = 1,   //По ключу
    BY_POS = 2    //По позиции
};

/**
 * Класс "Мэнеджер"
 * Исполняет действия, выбранные польщователем в меню,
 * обращаясь к функционалу генератора данных и хэш таблицы.
 */
class Manager {
private:
    GeneratorPerson generatorPerson;  //Генератор данных
    Hash hashPerson;          //Хэш-Таблица
private:
    void initHashPerson(unsigned int size);      //Метод инициализация хэш таблицы случайными значениями
    string getKey(const string &title) const;   //Метод получуения ключа от пользователя с консоли (диалог ввода)
    Person getDataFromList(list<Person> &dataList, const string &title) const;  //Метод для уточнения пользователем, какую именно запись выбрать из списка (диалог ввода)
    Person getEditedElement(const Person& data);    //Метод для получения отредактированной записи от пользователя  (диалог ввода)
    string getStringFromDataList(const list<Person> &dataList) const;     //Метод для получения форматированного строкового представления записей хэш-таблицы
public:
    Manager();              //Конструктор
    void printHashPerson();  //Метод вывода записей хэш-таблицы в консоль
    void searchElement();   //Метод поиска записи в хэш-таблице
    void editElement();     //Метод редактирования записи хэш-таблицы
    void removeElement();   //Метод удаления записи хэш-таблицы
    void testCollisions();  //Метод тестирования хэш-таблицы на коллизии
};
