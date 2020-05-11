
#include <iostream>
#include <string>
#include "Rightangled.h"

using namespace std;

int main(){

  // Класс Pair
  Pair a;
  cout << "  "<< endl;// Ввод параметров класса Rair 
  cin >> a;
  cout << "\n Entering parameters of the Rair class " << a << endl;// Вывод результата класса Rair
  cout << "\n Perimeter of the Rair class - " << a.perimeter() << endl;// Периметр класса Rair 

  Rightangled b;
  cout << "\n  "<< endl;// Ввод параметров класса Rightangled
  cin >> b;
  cout << "\n Entering parameters of the Rightangled class - " << b.Hypatenuse() << endl;// Гипатенуза класса Rightangled
  cout << "\n Output of the Rightangled class result "<< endl;// Вывод результата класса Rightangled
  cout << b;

  return 0;
}

// Запуск прою "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
