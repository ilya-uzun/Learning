
#include "constants.h"

/**
 * Перечисление "Тип события"
 */
enum EventType {
    EV_NOTHING=0, //пустое событие
    EV_MESSAGE=100 //непустое событие
};

/**
 * Структура "Событие"
 */
struct TEvent
{
    EventType what;//тип события
    union
    {
        MenuAction command; //код команды

        struct
        {
            int message; //сообщение
            int a;  //параметр команды
        };
    };

    //Конструктор без параметров
    TEvent() {
        what = EV_NOTHING;
        command = MENU_EXIT;
        message = 0;
        a = 0;
    }
};
