#pragma once

const int evNothing = 0;//пустое событие
const int evMessage = 100;//непустое событие
const int cmAdd = 1;//добавить объект в группу
const int cmDel = 2;//удалить объект из группы
const int cmGet = 3;//вывести атрибут всех объектов
const int cmShow = 4;//вывести всю группу
const int cmAverageAge = 5;//вывести всю группу
const int cmMake = 6;//создать группу
const int cmHelp = 7;//помощь
const int cmQuit = 101;//выход
//класс событие
struct TEvent
{
    int what;//тип события
    union
    {
        int command;//код команды
        struct
            {
                int message;
                int a;//параметр команды
            };
    };
};