
#include <iostream>
#include <string>
using namespace std;

class Route {
    //атрибуты
    string CPU; 
    int RAM; 
    int HDD; 
public:
    Route(); //конструктор без параметров
    Route(string, int, int);// конструктор с параметрами
    Route(const Route&);// конструктор копирования
    ~Route();//деструктор
    string get_CPU();//селектор
    int get_RAM();//селектор
    int  get_HDD();//селектор
    void set_CPU(string);//модификатор
    void set_RAM(int);//модификатор
    void set_HDD(int);//модификатор
    void show();//просмотр  атрибутов
};
