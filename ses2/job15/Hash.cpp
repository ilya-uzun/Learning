#include "Hash.h"
#include <stdexcept>

// Метод получения размера таблицы
int Hash::getSize() {
    return size;
}

//  Метод получения общего количества добавленных в таблицу элементов
int Hash::getFilledSize() {
    int sum = 0;

    for (auto &cell : table) {
        sum += cell.size();
    }

    return sum;
}

//  Метод проверки, является ли таблица пустой
bool Hash::isEmpty() {
    return getFilledSize() == 0;
}

//  Метод получения целочисленного ключа из строкового
int Hash::getIntKey(const string &key) {
    int value = 0;
    for (char i : key) {
        value = 37 * value + i;
    }
    return value;
}

//  Метод, вычисляющи и возвращающий хэш-сумму
//  на основе строкового ключа.
//  Работает по формуле:
// H(k)= [M (kAmod1)], 0<A<1, mod1 – получение дробной части, [] – получение целой части
 
int Hash::hash(const string &key) {
    int intKey = getIntKey(key);
    int M = size;
    long double A = (sqrt((long double) 5) - 1) / 2;
    long double kA = (long double) intKey * A;
    long double kAMod1 = (kA - floor(kA));
    return floor(M * kAMod1);
}

// Метод вставки новой записи в хэш-таблицу
void Hash::insert(const Person &value) {
    auto &key = value.get_FIO();
    int hashValue = hash(key);
    list<pair<string, Person>> &cell = table[hashValue];
    auto iter = cell.begin();
    bool keyExists = false;
    
    while (iter != cell.end()) {
        if (iter->first == key) {
            keyExists = true;
            iter->second = value;
            break;
        }
        iter++;
    }

    if (!keyExists) {
        cell.emplace_back(key, value);
    }
}

//  Метод удаления записи из хэш-таблицы
bool Hash::remove(const string &key) {
    int hashValue = hash(key);
    auto &cell = table[hashValue];
    auto iter = cell.begin();
    bool itemRemoved = false;

    while (iter != cell.end()) {
        if (iter->first == key) {
            itemRemoved = true;
            iter = cell.erase(iter);
            break;
        }
        iter++;
    }

    return itemRemoved;
}

//  Метод поиска записи в хэш таблице по ключу
Person Hash::search(const string &key) {
    int hashValue = hash(key);
    auto &cell = table[hashValue];
    auto iter = cell.begin();

    while (iter != cell.end()) {
        if (iter->first == key) {
            return iter->second;
        }
        iter++;
    }

    throw runtime_error("The element was not found!");// Элемент не был найден!
}

//  Метод поиска записей в хэш таблице по номеру
list<Person> Hash::search(const int pos) {
    auto &cell = table[pos - 1];

    if (!cell.empty()) {
        list<Person> result;
        for (auto & el : cell) {
            result.emplace_back(el.second);
        }
        return result;
    }

    throw runtime_error("The element was not found!");// Элемент не был найден!
}

//  Метод посчета коллизий
int Hash::getCollisionNum() {
    int sum = 0;

    for (auto &cell : table) {
        if (cell.size() > 1) {
            sum += cell.size() - 1;
        }
    }

    return sum;
}

// Метод вывода записей хэш-таблицы в консоль
void Hash::print() {
    if (getFilledSize() == 0) {
        throw runtime_error("The hash table is empty, there is nothing to print!");// Хэш-Таблица пустая, распечатывать нечего
    }

    for (int i = 0; i < size ; i++) {
        auto &cell = table[i];
        if (!cell.empty()) {
            cout << i + 1 << ") " << endl;
            for (auto & el : cell) {
                cout << "\tkey = " << el.first << ", value = {" << el.second << "}";
                cout << endl;
            }
        }
    }
}

//  Метод удаления всех записей их хэш-таблицы
void Hash::clear() {
    for (auto &cell : table) {
        cell.clear();
    }
}


