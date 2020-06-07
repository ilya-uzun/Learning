#pragma once
#include "Person.h"
#include "GeneratorPerson.h"
#include "Hash.h"
// #include "Utilit.h"

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
    Person getEditedElement(const Person& person);    //Метод для получения отредактированной записи от пользователя  (диалог ввода)
    string getStringFromDataList(const list<Person> &dataList) const;     //Метод для получения форматированного строкового представления записей хэш-таблицы
public:
    Manager();              //Конструктор
    void printHashPerson();  //Метод вывода записей хэш-таблицы в консоль
    void searchElement();   //Метод поиска записи в хэш-таблице
    void editElement();     //Метод редактирования записи хэш-таблицы
    void removeElement();   //Метод удаления записи хэш-таблицы
    void testCollisions();  //Метод тестирования хэш-таблицы на коллизии
};

template<typename ... Args>
inline string string_format(const string &format, Args ... args) {
    size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
    if (size <= 0) { throw runtime_error("Error in the formatting process!"); }//Ошибка в процессе форматирования!
    unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args ...);
    return string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

inline string trim_str(string &str) {
    str.erase(str.find_last_not_of(" \n\r\t") + 1);
    return str;
}

inline int getIntFromInput() {
    string str;
    int num;

    getline(cin, str);

    while (!regex_match(trim_str(str), regex(R"(^(\+|-)?\d+$)"))) {
        cout << "Invalid format of the real value! Enter again!\n";// Неверный формат целочисленного значения! Введите снова!
        getline(cin, str);
    }

    num = stoi(str);

    return num;
}

inline float getFloatFromInput() {
    string str;
    float num;

    getline(cin, str);

    while (!regex_match(trim_str(str), regex(R"(^[-+]?\d*\.?\d*$)"))) {
        cout << "Invalid format of the real value! Enter again!\n";// Неверный формат вещественного значения! Введите снова!
        getline(cin, str);
    }

    num = stof(str);

    return num;
}

inline double getDoubleFromInput() {
    string str;
    double num;

    getline(cin, str);

    while (!regex_match(trim_str(str), regex(R"(^[-+]?\d*\.?\d*$)"))) {
        cout << "Invalid format of the real value! Enter again!\n";// Неверный формат вещественного значения! Введите снова!
        getline(cin, str);
    }

    num = stof(str);

    return num;
}

inline int getInt(const string &title, int minValue, int maxValue) {
    int value;

    if (!title.empty()) {
        cout << title << endl;
    }

    value = getIntFromInput();

    while (value < minValue || value > maxValue) {
        cout << "The value must be from " << minValue << " do " << maxValue << "!" << endl;// Значение должно быть от
        value = getIntFromInput();
    }

    return value;
}

inline int getInt(const string &title, const vector<int> &codes, const string &outOfRangeMsg) {
    int value;

    if (!title.empty()) {
        cout << title << endl;
    }

    value = getIntFromInput();

    while (find(codes.begin(), codes.end(), value) == codes.end()) {
        if (!outOfRangeMsg.empty()) {
            cout << outOfRangeMsg << endl;
        }

        cout << "\nThe value must be within the allowed set:\n"; // Значение должно быть в пределах допустимого набора
        const vector<int>::const_iterator &iterator = codes.begin();
        for (int el : codes) {
            cout << el << " ";
        }
        cout << "\n\n";

        value = getIntFromInput();
    }

    return value;
}

inline string getString(const string &title) {
    string value;

    if (!title.empty()) {
        cout << title << endl;
    }

    getline(cin, value);
    trim_str(value);

    while (value.empty()) {
        cout << "The value must contain at least 1 character!" << endl; // Значение должно содержать минимум 1 символ!
        getline(cin, value);
    }

    return value;
}

inline string getString(const string &title, const string &regex_mask, const string &regexMismatchMsg) {
    string value;

    if (!title.empty()) {
        cout << title << endl;
    }

    getline(cin, value);
    bool valid = !value.empty() && regex_match(trim_str(value), regex(regex_mask));

    while (!valid) {
        if (value.empty()) {
            cout << "The value must contain at least 1 character!" << endl; // Значение должно содержать минимум 1 символ!
        }
        if (!regex_match(value.c_str(), regex(regex_mask))) {
            cout << regexMismatchMsg << endl;
        }
        getline(cin, value);
        valid = !value.empty() && regex_match(trim_str(value), regex(regex_mask));
    }

    return value;
}
