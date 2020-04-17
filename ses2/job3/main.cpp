#include <iostream>
#include "Time.h"
#include <windows.h>
using namespace std;


int main()
{
  SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
  SetConsoleOutputCP(1251);
  Time a;//конструктор без параметров
  Time b;//конструктор без параметров
  Time c;//конструктор без параметров

  cout << "Класс a - " << endl;
  cout << "Введите минуты - "<< endl;
  a.get_min();
  cout << "Введите секунды - " << endl;
  a.get_sec();
  cin >> a;
  cout << "Класс b - " << endl;
  cin >> b;

  ++a;// префикная операция инкремент
  cout << a << endl;
  c = (a++) + b;// сложение и постфиксная операция инкремент
  cout << "a= " << a << endl;
  cout << "b= " << b << endl;
  cout << "c= " << c << endl;
  //cout << "d= " << d << endl;

/*----------   Компоненты set и get      ---------*/
  cout << " " << min_ <<'\n';
  Time d {10, 0};//конструктор без параметров
  d.set_min(32);// задание через модификаторы
  int min_ = d.get_min();
  cout << "вывод get_min " << min_ <<'\n';

}
