#pragma once
#include <iostream>
#include <string>
using namespace std;

class Route {
    //атрибуты
    string start; // пункт  отправления
    string finish; // пункт  назначения
    float time_in_way; // время в пути

public:
    Route(); //конструктор без параметров
    Route(string, string, float);// конструктор с параметрами
    Route(const Route&);// конструктор копирования
    ~Route();//деструктор
    string get_start();//селектор
    string get_finish();//селектор
    float  get_time_in_way();//селектор
    void set_start(string);//модификатор
    void set_finish(string);//модификатор
    void set_time_in_way(float);//модификатор
    void show();//просмотр  атрибутов
};
