// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include <string>
#include"Pair.h"
#include "Rightangled.h"

using namespace std;

int main(){
   setlocale(LC_CTYPE, "rus");
   // Класс Pair
   Pair a;
   cin >> a;
   cout << a;

   Rightangled b;
   cin >> b;
   cout << b;
  
   return 0;
}

// Запуск прою "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
