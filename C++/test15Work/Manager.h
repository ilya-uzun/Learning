#pragma once
#include "Data.h"
#include "DataGenerator.h"
#include "HashTable.h"
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
    DataGenerator dataGenerator;  //Генератор данных
    HashTable hashTable;          //Хэш-Таблица
private:
    void initHashTable(unsigned int size);      //Метод инициализация хэш таблицы случайными значениями
    string getKey(const string &title) const;   //Метод получуения ключа от пользователя с консоли (диалог ввода)
    Data getDataFromList(list<Data> &dataList, const string &title) const;  //Метод для уточнения пользователем, какую именно запись выбрать из списка (диалог ввода)
    Data getEditedElement(const Data& data);    //Метод для получения отредактированной записи от пользователя  (диалог ввода)
    string getStringFromDataList(const list<Data> &dataList) const;     //Метод для получения форматированного строкового представления записей хэш-таблицы
public:
    Manager();              //Конструктор
    void printHashTable();  //Метод вывода записей хэш-таблицы в консоль
    void searchElement();   //Метод поиска записи в хэш-таблице
    void editElement();     //Метод редактирования записи хэш-таблицы
    void removeElement();   //Метод удаления записи хэш-таблицы
    void testCollisions();  //Метод тестирования хэш-таблицы на коллизии
};
