#include "GeneratorPerson.h"


    template<typename ... Args>
inline string string_format(const string &format, Args ... args) {
    size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
    if (size <= 0) { throw runtime_error("Error in the formatting process!"); }// Ошибка в процессе форматирования!
    unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args ...);
    return string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

//Конструктор без параметров

GeneratorPerson::GeneratorPerson() {
    engine = mt19937(rd());
    surnames = makeSurnames();
    names = makeNames();
    patronymics = makePatronymics();
}

//Метод получения случайного числа в заданном диапазоне
unsigned int GeneratorPerson::getRandomNumber(unsigned int from, unsigned int to) {
    uniform_int_distribution<unsigned int> dist(from, to);
    return dist(engine);
}

 //Метод получения сегенерированного значения для поля "ФИО"
string GeneratorPerson::getFIO() {
    return string_format("%s %s %s",
                         surnames[getRandomNumber(0, surnames.size() - 1)].c_str(),
                         names[getRandomNumber(0, names.size() - 1)].c_str(),
                         patronymics[getRandomNumber(0, patronymics.size() - 1)].c_str());
}


//Метод получения сегенерированного значения для поля "Номер счёта"
string GeneratorPerson::getSumma() {
    return string_format("%d%d%d%d",
                         getRandomNumber(1, 9), getRandomNumber(1, 9), 
                         getRandomNumber(1, 9), getRandomNumber(1, 9));
}

string GeneratorPerson::getAccount_number() {
    return string_format("%d%d.%d%d%d.%d%d%d",
                         getRandomNumber(1, 9), getRandomNumber(1, 9), 
                         getRandomNumber(1, 9), getRandomNumber(1, 9),
                         getRandomNumber(1, 9), getRandomNumber(1, 9), 
                         getRandomNumber(1, 9), getRandomNumber(1, 9), 
                         getRandomNumber(1, 9), getRandomNumber(1, 9));
}

//Метод получения объекта типа "Данные" на основе сгенерированных полей
Person GeneratorPerson::getData() {
    return Person(getFIO(),getSumma(), getAccount_number());
}

// списка фамилий
vector<string> GeneratorPerson::makeSurnames() {
    vector<string> surnames = {
            "Moore", "Taylor", "Garcia", "Jones", 
            "Lewis", "Hill", "Nelson", "Phillips", "Parker", 
            "Evans", "Smith", "Johnson", "Jones", "Brown"
    };
    return surnames;
}

// списка имен
vector<string> GeneratorPerson::makeNames() {
    vector<string> names = {
            "James", "Jonh", "David", "Andrey", 
            "Ilya", "Brian", "Mark", "Paul", 
            "Daniel", "William", "Stevan", "Kapl", 
            "Stanislav", "Georgiy", "Michael"
    };
    return names;
}

// списка отчеств
vector<string> GeneratorPerson::makePatronymics() {
    vector<string> patronymics = {
            "Ivanovich", "Petrovich", "Sidorovich", 
            "Nikolaevich", "Jonovich", "Albertovich", 
            "Isaakovich", "Robertovich", "Markovich", 
            "Iosifovich", "Vladimirovich", "Karlovich", 
            "Alekseevich", "Mihablovich", "Dmitrievich"
    };
    return patronymics;
}

