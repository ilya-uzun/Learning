
#include <iostream>
#include <string>
#include "Rightangled.h"

using namespace std;

int main(){

  // Класс Pair
  Pair a;
  cout << " Ввод параметров класса Rair "<< endl;
  cin >> a;
  cout << " Вывод результата класса Rair \n" << a << endl;
  cout << " Периметр класса Rair - " << a.perimeter() << endl;

  Rightangled b;
  cout << "\n Ввод параметров класса Rightangled "<< endl;
  cin >> b;
  cout << " \n Гипатенуза класса Rightangled  - " << b.Hypatenuse() << endl;
  cout << " Вывод результата класса Rightangled "<< endl;
  cout << b;

  return 0;
}

// Запуск прою "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
