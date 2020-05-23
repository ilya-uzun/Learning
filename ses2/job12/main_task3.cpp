#include "Time.h"
#include "Container.h"
#include <iostream>
using namespace std;

int main()
{
  int n; //количество элементов в контейнере
  cout << "Enter int N :"; 
  cin >> n;
  Container <Time> v(n);//создать контенер
  v.Print();//напечатать контейнер
  // задание 3 
  Time t = v.Srednee();//найти среднее арифметическое
  cout << "Aveage =" << t <<endl;
  cout << "Add aveage" <<endl;
  cout << "Output pos - ";
  int pos;
  cin >> pos;//позиция для добавления
  v.Add(pos, t);//добавление
  v.Print();//печать
  // задаие 4
  cout << "Delete max: "<< endl;
  v.Del();  
  v.Print();
  //задание 5
  cout << "Division on min: " << endl;
  v.Delenie();
  v.Print();
}