#pragma once
#include <iostream>
#include <string>
#include "Event.h"
#include "Manager.h"
#include "structs.h"

/**
 * Класс для работы/диалога с пользователем.
 * Предоставляет меню действий с БД и обрабатывает
 * выбор пользователя, используя API Класса Manager
 */
class Dialog {
private:
    bool EndState;  //Состояние завершения работы диалога
    vector<string> menuItems;   //Список пунктов меню
    vector<unsigned short> allowedActions;  //Коды доступных пунктов меню
    Manager manager;    //Менеджер СУБД
public :
    Dialog();           //Контруктор
    virtual ~Dialog();  //Деструктор
    bool valid() const;             //Метод проверки необходимости продолжать работу
    void getEvent(TEvent &event);   //Метод получения события от пользователя через меню
    int execute();                  //Главный цикл работы диалога с пользователем
    void handleEvent(TEvent &event); //Обработчик событий
    virtual void activateEvent(TEvent &event) const;  //Метод активировации события
    virtual void clearEvent(TEvent &event);           //Метод деактивации (очищения) события
    void startExec();       //Запуск основного диалога
    void endExec();         //Обработка события «конец работы»
    MenuSet getMenuSet();   //Получение актуального меню для пользователя
};
