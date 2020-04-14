#include <iostream>
#include "Time.h"
#include <windows.h>
using namespace std;


int main(){
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);
    Time a;//конструктор без параметров
    Time b;//конструктор без параметров
    Time c;//конструктор без параметров
    cin >> a;
    cin >> b;
    ++a;// префикная операция инкремент
    cout << a << endl;
    c = (a++) + b;// сложение и постфиксная операция инкремент
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    cout << "c= " << c << endl;

}
