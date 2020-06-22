#include "DataGenerator.h"

/**
 * Конструктор без параметров
 */
DataGenerator::DataGenerator() {
    engine = mt19937(rd());
    surnames = makeSurnames();
    names = makeNames();
    patronymics = makePatronymics();
    addresses = makeAddresses();
}

/**
 * Метод получения случайного числа в заданном диапазоне
 * @param from
 * @param to
 * @return
 */
unsigned int DataGenerator::getRandomNumber(unsigned int from, unsigned int to) {
    uniform_int_distribution<unsigned int> dist(from, to);
    return dist(engine);
}

/**
 * Метод получения сегенерированного значения для поля "ФИО"
 * @return
 */
string DataGenerator::getFIO() {
    return string_format("%s %s %s",
                         surnames[getRandomNumber(0, surnames.size() - 1)].c_str(),
                         names[getRandomNumber(0, names.size() - 1)].c_str(),
                         patronymics[getRandomNumber(0, patronymics.size() - 1)].c_str());
}

/**
 * Метод получения сегенерированного значения для поля "Номер паспорта"
 * @return
 */
string DataGenerator::getPassportNumber() {
    return string_format("%d%d %d%d %d%d%d%d%d%d",
                         getRandomNumber(1, 9), getRandomNumber(1, 9), getRandomNumber(1, 9), getRandomNumber(1, 9),
                         getRandomNumber(1, 9), getRandomNumber(1, 9), getRandomNumber(1, 9),
                         getRandomNumber(1, 9), getRandomNumber(1, 9), getRandomNumber(1, 9));
}

/**
 * Метод получения сегенерированного значения для поля "Адрес"
 * @return
 */
string DataGenerator::getAddress() {
    return addresses[getRandomNumber(0, addresses.size() - 1)];
}

/**
 * Метод получения объекта типа "Данные" на основе сгенерированных полей
 * @return
 */
Data DataGenerator::getData() {
    return Data(getFIO(), getPassportNumber(), getAddress());
}

/**
 * Статический метод инциализации списка фамилий
 * @return
 */
vector<string> DataGenerator::makeSurnames() {
    vector<string> surnames = {
            "Алексеев", "Иванов", "Петров", "Сидоров", "Семенов", "Тесла", "Маск", "Эйнштейн", "Ньютон", "Гук", "Кюри", "Сталин", "Ленин", "Маркс"
    };
    return surnames;
}

/**
 * татический метод инциализации списка имен
 * @return
 */
vector<string> DataGenerator::makeNames() {
    vector<string> names = {
            "Иван", "Петр", "Сидор", "Никола", "Илон", "Альберт", "Исаак", "Роберт", "Мария", "Иосиф", "Владимир", "Карл", "Алексей", "Михаил", "Дмитрий"
    };
    return names;
}

/**
 * Статический метод инциализации списка отчеств
 * @return
 */
vector<string> DataGenerator::makePatronymics() {
    vector<string> patronymics = {
            "Иванович", "Петрович", "Сидорович", "Николаевич", "Илонович", "Альбертович", "Исаакович", "Робертович", "Маркович", "Иосифович", "Владимирович",
            "Карлович", "Алексеевич", "Михаилович", "Дмитриевич"
    };
    return patronymics;
}

/**
 * Статический метод инциализации списка адресов
 * @return
 */
vector<string> DataGenerator::makeAddresses() {
    vector<string> addresses = {
            "Андрея Тарковского", "Берёзовая", "Боровская", "Герцена", "Гоголя", "Дачная", "Железнодорожная", "Ильинская", "Карла Маркса", "Кольцевая",
            "Ленина", "Лермонтова", "Ломоносова", "Маяковского", "Новоизваринская", "Октябрьская", "Первомайская", "Пушкина", "Роберта Рождественского",
            "Садовая", "Серафимовича", "Самуила Маршака", "Сказочная", "Трудовой переулок", "Чапаева", "Чехова", "Шоссейная", "Энгельса"
    };
    return addresses;
}