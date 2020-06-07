#include "Manager.h"

/**
 * Конструктор без параметров
 */
Manager::Manager() {
    initHashPerson(100);
}

// Метод инициализация хэш таблицы случайными значениями
void Manager::initHashPerson(unsigned int size) {
    hashPerson.clear();
    for (unsigned int i = 0; i < size; i++) {
        hashPerson.insert(generatorPerson.getData());
    }
}

//  Метод вывода записей хэш-таблицы в консоль
void Manager::printHashPerson() {
    cout << "The elements of the hash table:" << endl;// Элементы хэш-таблицы:
    hashPerson.print();
}

//  Метод поиска записи в хэш-таблице
void Manager::searchElement() {
    const string &key = getKey("\nEnter the key of the item you want to find!");// Введите ключ элемента, который, хотите найти!
    const Person &person = hashPerson.search(key);
    cout << "\nThe element is found:" << endl; //  Найденный элемент:
    cout << person << endl;
}

//  Метод получуения ключа от пользователя с консоли (диалог ввода)

string Manager::getKey(const string &title) const {
    return getString(title,
                     R"(\d{2} \d{2} \d{6})",
                     " The value must match the format ** ** ** ** **, where instead of \"*\" any number from 0 to 9 "); // "Значение должно соответствовать формату ** ** ******, где вместо \"*\" любое число от 0 до 9"
}

// Метод редактирования записи хэш-таблицы
void Manager::editElement() {
    list<Person> dataList;
    SearchType opt = SearchType(getInt(string_format("\nHow do you want to edit an element?\n%d - By key\n%d - By number", BY_KEY, BY_POS), BY_KEY, BY_POS));
    // Каким образом хотите отредактировать элемент?\n%d - По ключу\n%d - По номеру"
    switch (opt) {
        case BY_KEY: {
            const string &key = getKey("\n"); // Введите ключ элемента, который, хотите отредкатировать!
            dataList.emplace_back(hashPerson.search(key));
            break;
        }
        case BY_POS: {
            const int pos = getInt("\nEnter the key of the element you want to edit!", 1, hashPerson.getSize()); //Введите номер элемента, который, хотите отредактировать!
            dataList = hashPerson.search(pos);
            break;
        }
    }

    if (dataList.empty()) {
        throw runtime_error("The element was not found and therefore will not be edited!");// Элемент не был найден и поэтому не будет отредактирован!
    }

    Person person = getDataFromList(dataList, "\nSeveral elements were found, which one do you want to edit?" + getStringFromDataList(dataList));// Найдено несколько элементов, который из них вы хотите отредактировать?
    person = getEditedElement(person);
    hashPerson.insert(person);

    cout << "The element was successfully edited!" << endl; // Элемент был успешно отредактирован!
}

// Метод удаления записи хэш-таблицы
 
void Manager::removeElement() {
    list<Person> dataList;
    SearchType opt = SearchType(getInt(string_format("\nHow do you want to delete an item?\n%d - By key\n%d - By number", BY_KEY, BY_POS), BY_KEY, BY_POS));
    // Каким образом хотите удалить элемент?\n%d - По ключу\n%d - По номеру",
    switch (opt) {
        case BY_KEY: {
            const string &key = getKey("\nEnter the key of the item you want to delete!"); //Введите ключ элемента, который, хотите удалить!
            dataList.emplace_back(hashPerson.search(key));
            break;
        }
        case BY_POS: {
            const int pos = getInt("\nEnter the number of the item you want to delete!", 1, hashPerson.getSize()); // Введите номер элемента, который, хотите удалить!
            dataList = hashPerson.search(pos);
            break;
        }
    }

    if (dataList.empty()) {
        throw runtime_error("The element was not found and therefore will not be deleted!"); // Элемент не был найден и поэтому не будет удален!
    }

    Person person = getDataFromList(dataList, "\nMultiple items found, which one do you want to delete?" + getStringFromDataList(dataList)); // Найдено несколько элементов, который из них вы хотите удалить?
    hashPerson.remove(person.getKey());

    cout << "The element was successfully deleted!" << endl; // Элемент был успешно удален!
}

// Метод тестирования хэш-таблицы на коллизии

void Manager::testCollisions() {
    cout << "Test the number of collisions!" << endl << endl; // Тест количества коллизий!
    initHashPerson(40);
    cout << "With 40 elements, the number of collisions = " << hashPerson.getCollisionNum() << endl << endl;// При 40 элементах кол-во коллизий =
    initHashPerson(75);
    cout << "With 75 elements, the number of collisions = " << hashPerson.getCollisionNum() << endl << endl;// При 75 элементах кол-во коллизий =
    initHashPerson(90);
    cout << "With 90 elements, the number of collisions = " << hashPerson.getCollisionNum() << endl << endl;// При 90 элементах кол-во коллизий =
    initHashPerson(100);
}

// Метод для уточнения пользователем,
// какую именно запись выбрать из списка (диалог ввода)
 
Person Manager::getDataFromList(list<Person> &dataList, const string &title) const {
    if (dataList.empty()) {
        throw runtime_error("There is nothing to return, because the list is empty!");// Нечего возвращать, т.к. список пустой!
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

// Метод для получения форматированного
// строкового представления записей хэш-таблицы

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

// Метод для получения отредактированной записи от пользователя  (диалог ввода)

Person Manager::getEditedElement(const Person &person) {
    Person result = person;
    int field;
    string strValue;

    string title =
            "\n Which field should I change?" // Какое поле нужно поменять
            "\n1 - FIO" //  ФИО
            "\n2 - Summa"; //  Сумма

    string contOpt = "yY";
    string cont;

    bool done = false;

    cout << "\nCurrent state of the element:" << endl; //  Текущее состояние элемента
    cout << result << endl;

    do {
        field = getInt(title, 1, 2);
        switch (field) {
            case 1: {
                strValue = getString("\nNew value for the field \"FIO\" : "); // Новое значение для поля
                result.set_FIO(strValue);
                break;
            }
            case 2: {
                strValue = getString("\nNew value for the field \"Summa\":"); // Новое значение для поля 
                result.set_summa(strValue);
                break;
            }
            default:
                printf("\nThis field is not in the element!\n"); // Такого поля нет в элементе!
                break;
        }
        cout << "\nCurrent state of the element:" << endl;// Текущее состояние элемента:
        cout << result << endl;
        cont = getString("\nTo continue editing the record? (y/n)"); // Продолжить редактировать запись?
        if (contOpt.find(cont[0]) == string::npos) {
            done = true;
        }
    } while (!done);

    return result;
}
