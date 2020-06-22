#include <iostream>
#include "Time.h"
using namespace std;


int main()
{
  Time a;//конструктор без параметров
  Time b;//конструктор без параметров
  Time c;//конструктор без параметров
  Time d;//конструктор без параметров

  cout << "Class a - " << endl; //
  cout << "Enter minutes - ";
  int min_a;
  cin >> min_a ; // объявление и инициализция новой перем.
  a.set_min(min_a);// ввод мин через set
  cout << "Enter seconds - " ;
  int sec_a;
  cin >> sec_a;
  a.set_sec(sec_a);

  cout << "Class b - " << endl;
  cin >> b;// ввод через потоки istream
  /*-------- Операции с классами --------*/
  a++;// префиксная операция инкремент
  cout << "Output the result after the increment operation a++ :  "  << a << '\n'; // Выведите Результат после операции инкремента
  c = a + b;
  cout << "Output the result after the addition operati a+b :  "  << c << '\n'; // Вывод результата после операции сложения
  a = b;
  cout << "Output the result after the assignment opera a=b :  "  << a << '\n'; // Вывод результата после операции присваивания
  cout << "Subtract seconds :  "; // вычесть секунды
  int sek_;
  cin >> sek_ ;
  d = a - sek_;// Перегружается operator -
  cout << "Output the result after subtracting seconds :  "  << d << '\n'; // Вывод результата после вычитания секунд
  return 0;
}
