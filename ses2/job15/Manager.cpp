#include "Manager.h"

/**
 * Конструктор без параметров
 */
Manager::Manager() {
    initHashPerson(100);
}

/**
 * Метод инициализация хэш таблицы случайными значениями
 * @param size
 */
void Manager::initHashPerson(unsigned int size) {
    hashPerson.clear();
    for (unsigned int i = 0; i < size; i++) {
        hashPerson.insert(generatorPerson.getData());
    }
}

/**
 * Метод вывода записей хэш-таблицы в консоль
 */
void Manager::printHashPerson() {
    cout << "Элементы хэш-таблицы:" << endl;
    hashPerson.print();
}

/**
 * Метод поиска записи в хэш-таблице
 */
void Manager::searchElement() {
    const string &key = getKey("\nВведите ключ элемента, который, хотите найти!");
    const Person &person = hashPerson.search(key);
    cout << "\nНайденный элемент: " << endl;
    cout << person << endl;
}

/**
 * Метод получуения ключа от пользователя с консоли (диалог ввода)
 * @param title
 * @return
 */
string Manager::getKey(const string &title) const {
    return getString(title,
                     R"(\d{2} \d{2} \d{6})",
                     "Значение должно соответствовать формату ** ** ******, где вместо \"*\" любое число от 0 до 9");
}

/**
 * Метод редактирования записи хэш-таблицы
 */
void Manager::editElement() {
    list<Person> dataList;
    SearchType opt = SearchType(getInt(string_format("\nКаким образом хотите отредактировать элемент?\n%d - По ключу\n%d - По номеру", BY_KEY, BY_POS), BY_KEY, BY_POS));

    switch (opt) {
        case BY_KEY: {
            const string &key = getKey("\nВведите ключ элемента, который, хотите отредкатировать!");
            dataList.emplace_back(hashPerson.search(key));
            break;
        }
        case BY_POS: {
            const int pos = getInt("\nВведите номер элемента, который, хотите отредактировать!", 1, hashPerson.getSize());
            dataList = hashPerson.search(pos);
            break;
        }
    }

    if (dataList.empty()) {
        throw runtime_error("Элемент не был найден и поэтому не будет отредактирован!");
    }

    Person person = getDataFromList(dataList, "\nНайдено несколько элементов, который из них вы хотите отредактировать?" + getStringFromDataList(dataList));
    person = getEditedElement(person);
    hashPerson.insert(person);

    cout << "Элемент был успешно отредактирован!" << endl;
}

/**
 * Метод удаления записи хэш-таблицы
 */
void Manager::removeElement() {
    list<Person> dataList;
    SearchType opt = SearchType(getInt(string_format("\nКаким образом хотите удалить элемент?\n%d - По ключу\n%d - По номеру", BY_KEY, BY_POS), BY_KEY, BY_POS));

    switch (opt) {
        case BY_KEY: {
            const string &key = getKey("\nВведите ключ элемента, который, хотите удалить!");
            dataList.emplace_back(hashPerson.search(key));
            break;
        }
        case BY_POS: {
            const int pos = getInt("\nВведите номер элемента, который, хотите удалить!", 1, hashPerson.getSize());
            dataList = hashPerson.search(pos);
            break;
        }
    }

    if (dataList.empty()) {
        throw runtime_error("Элемент не был найден и поэтому не будет удален!");
    }

    Person person = getDataFromList(dataList, "\nНайдено несколько элементов, который из них вы хотите удалить?" + getStringFromDataList(dataList));
    hashPerson.remove(person.getKey());

    cout << "Элемент был успешно удален!" << endl;
}

/**
 * Метод тестирования хэш-таблицы на коллизии
 */
void Manager::testCollisions() {
    cout << "Тест количества коллизий!" << endl << endl;
    initHashPerson(40);
    cout << "При 40 элементах кол-во коллизий = " << hashPerson.getCollisionNum() << endl << endl;
    initHashPerson(75);
    cout << "При 75 элементах кол-во коллизий = " << hashPerson.getCollisionNum() << endl << endl;
    initHashPerson(90);
    cout << "При 90 элементах кол-во коллизий = " << hashPerson.getCollisionNum() << endl << endl;
    initHashPerson(100);
}

/**
 * Метод для уточнения пользователем,
 * какую именно запись выбрать из списка (диалог ввода)
 * @param dataList
 * @param title
 * @return
 */
Person Manager::getDataFromList(list<Person> &dataList, const string &title) const {
    if (dataList.empty()) {
        throw runtime_error("Нечего возвращать, т.к. список пустой!");
    }

    Person person;

    if (dataList.size() == 1) {
        person = dataList.back();
    } else {
        int editPos = getInt(title, 1, dataList.size());
        int i = 1;
        for (auto &el: dataList) {
            if (i == editPos) {
                person = el;
                break;
            }
            i++;
        }
    }

    return person;
}

/**
 * Метод для получения форматированного
 * строкового представления записей хэш-таблицы
 * @param dataList
 * @return
 */
string Manager::getStringFromDataList(const list<Person> &dataList) const {
    string result;

    if (dataList.empty()) {
        return result;
    }
    
    int i = 1;
    for (auto &el : dataList) {
        result.append(string_format("\n%d) %s", i, el.toString().c_str()));
        i++;
    }

    return result;
}

/**
 * Метод для получения отредактированной записи от пользователя  (диалог ввода)
 * @param Person
 * @return
 */
Person Manager::getEditedElement(const Person &person) {
    Person result = person;
    int field;
    string strValue;

    string title =
            "\n Какое поле нужно поменять?"
            "\n1 - ФИО"
            "\n2 - Адрес\n";

    string contOpt = "yY";
    string cont;

    bool done = false;

    cout << "\nТекущее состояние элемента:" << endl;
    cout << result << endl;

    do {
        field = getInt(title, 1, 2);
        switch (field) {
            case 1: {
                strValue = getString("\nНовое значение для поля \"ФИО\":");
                result.set_FIO(strValue);
                break;
            }
            case 2: {
                strValue = getString("\nНовое значение для поля \"Адрес\":");
                result.set_account_number(strValue);
                break;
            }
            default:
                printf("\nТакого поля нет в элементе!\n");
                break;
        }
        cout << "\nТекущее состояние элемента:" << endl;
        cout << result << endl;
        cont = getString("\nПродолжить редактировать запись? (y/n)");
        if (contOpt.find(cont[0]) == string::npos) {
            done = true;
        }
    } while (!done);

    return result;
}
