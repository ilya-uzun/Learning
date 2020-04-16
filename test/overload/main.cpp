
#include <iostream>
#include "overload.h"

using namespace std;

int main()
  {
// Использование перегрузку операторов istream и ostream для вывода
  cout << "Class a - "<< endl;
  Overload a;
  cin >> a;
  cout << a << endl;
// Использование функций set и get
  cout << "Class b - "<< endl;
  Overload b;
  int first_b;
  int second_b;

  cin >> first_b; // вводим значение переменую
  b.set_first(first_b); // передаём значние в функцию set
  cout << "first - ";
  cout << b.get_first() << endl; // вывоодим

  cin >> second_b;
  b.set_second(second_b);
  cout << "second - ";
  cout << b.get_second() << endl;

  return 0;
  };
