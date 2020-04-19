// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include"Pair.h"
#include "Rightangled.h"

using namespace std;

int main(){

  // Класс Pair
  Pair a;
  cout << " Ввод параметров класса Rair - "<< endl;
  cin >> a;
  cout << " Вывод результата класса Rair - "<< endl;
  cout << a;

  Rightangled b;
  cout << " Ввод параметров класса Rightangled - "<< endl;
  cin >> b;
  cout << " Вывод результата класса Rightangled - "<< endl;
  cout << b;

  return 0;
}

// Запуск прою "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
