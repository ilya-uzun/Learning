#include "Dialog.h"

using namespace std;


//Конструктор
Dialog::Dialog() {
    //Приведения класса в рабочее состояние
    EndState = false;
    //Формирование сообщений для пунктов меню
    menuItems.emplace_back("\n%d - Распчечатать элементы из хэш таблицы!");
    menuItems.emplace_back("\n%d - Найти элемент по ключу!");
    menuItems.emplace_back("\n%d - Отредактировать элемент!");
    menuItems.emplace_back("\n%d - Удалить элемент!");
    menuItems.emplace_back("\n%d - Протестировать коллизии!");
    menuItems.emplace_back("\n%d - Выход!");
} 

//Деструктор
Dialog::~Dialog() = default;

/**
 * Метод формирует актуальное меню, пердлагая доступные варианты в зависимости от состояния системы,
 * которое получает от менеджера БД.
 * Возвращает значения типа MenuSet где хранится сформированное сообщение для пользователя
 * о доступных вариантах ввода и соотвествующие коды доступных действий.
 * @return MenuSet
 */
MenuSet Dialog::getMenuSet() {
    MenuSet result = MenuSet();

    string actionSetMsg = "\nВыберите действие!";

    actionSetMsg.append(string_format(menuItems[MENU_PRINT - 1], MENU_PRINT));
    result.codes.push_back(MENU_PRINT);

    actionSetMsg.append(string_format(menuItems[MENU_SEARCH - 1], MENU_SEARCH));
    result.codes.push_back(MENU_SEARCH);

    actionSetMsg.append(string_format(menuItems[MENU_EDIT - 1], MENU_EDIT));
    result.codes.push_back(MENU_EDIT);

    actionSetMsg.append(string_format(menuItems[MENU_REMOVE - 1], MENU_REMOVE));
    result.codes.push_back(MENU_REMOVE);

    actionSetMsg.append(string_format(menuItems[MENU_TEST_COLL - 1], MENU_TEST_COLL));
    result.codes.push_back(MENU_TEST_COLL);

    actionSetMsg.append(string_format(menuItems[MENU_EXIT - 1], MENU_EXIT));
    result.codes.push_back(MENU_EXIT);

    actionSetMsg.append("\n");

    result.msg = actionSetMsg;

    return result;
}

/**
 * Метод выводит на экран пользователю доступные пункты меню
 * и принимает от него выбранный вариант, на основе которого формирует
 * событие, которое далее уже будет обработано данной системой в основном цикле обработке.
 * @param event
 */
void Dialog::getEvent(TEvent &event) {
    try {
        const char *noOrUnavailable = "Такого действия нет в системе или оно не доступно в данный момент!";
        MenuSet menuSet = getMenuSet(); //Набор доступных кодов пунктов меню и соотвествующий текст
        int action;

        //МЕНЮ
        activateEvent(event);
        action = getInt(menuSet.msg, menuSet.codes, noOrUnavailable);
        auto menuAction = MenuAction(action);
        event.command = menuAction;
    } catch (exception& e) {
        cout << "Возникла ошибка!" << endl;
        cout << e.what() << endl;
        clearEvent(event);
    }
}

/**
 * Метод запускает и поддержитвает основной цикл обработки
 * и функционированния данной системы.
 * Обработка прекращается когда система будет переведена
 * в нерабочее состояние, например, по выбору полтзователя,
 * когда он выбрал пункт выхода из меню.
 * @return
 */
int Dialog::execute() {
    TEvent event;
    do {
        startExec();
        getEvent(event); //получить событие
        handleEvent(event); //обработать событие
    } while (valid());
    return EndState;
}

/**
 * Метод проверяет, находится ли система в рабочем состоянии
 * @return
 */
bool Dialog::valid() const { return !EndState; }

/**
 * Метод переводит событие в рабочеее состояние, т.е. в состояние,
 * в котором оно может быть обработано другими объектами
 * @param event
 */
void Dialog::activateEvent(TEvent &event) const {
    event.what = EV_MESSAGE;
}

/**
 * Метод "очищает" событие, т.е. переводит его в состояние,
 * когда его никто не может прочитать, т.н. состояние "Не для чтения/Пропустить"
 * @param event
 */
void Dialog::clearEvent(TEvent &event) {
    event.what = EV_NOTHING; //пустое событие
}

/**
 * Метод переводит систему в рабочее состояние
 */
void Dialog::startExec() { EndState = false; }

/**
 * Метод переводит систему в нерабочее состояние
 */
void Dialog::endExec() {
    EndState = true;
}

/**
 * Метод обрабатывает события.
 * Если событие находится в состоянии для чтения,
 * то считывается код его команды и выполняется соотвествующее
 * действие менеджером, после чего событие приводится
 * в состояние "Не для чтения/Пропустить"
 * @param event
 */
void Dialog::handleEvent(TEvent &event) {
    try {
        if (event.what == EV_MESSAGE) {
            switch (event.command) {
                case MENU_PRINT: {
                    manager.printHashTable();
                    break;
                }
                case MENU_SEARCH: {
                    manager.searchElement();
                    break;
                }
                case MENU_EDIT: {
                    manager.editElement();
                    break;
                }
                case MENU_REMOVE: {
                    manager.removeElement();
                    break;
                }
                case MENU_TEST_COLL: {
                    manager.testCollisions();
                    break;
                }
                case MENU_EXIT: {
                    endExec(); //выход
                    break;
                }
            }
            clearEvent(event);
        }
    } catch (exception& e) {
        cout << e.what() << endl;
        clearEvent(event);
    }
}

