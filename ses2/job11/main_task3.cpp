#pragma once
#include "Time.h"
#include "Vector.h"
#include <iostream>
using namespace std;


int main()
{
  Vector <Time> vec(5);//создать вектор из 5 элементов
  vec.Print();//печать вектор
  Time s = vec.Srednee();//среднее ариметическое
  cout <<"Srednee=" << s <<endl;
  cout <<"pos?";
  int p;
  cin >> p;//ввести позицию для добавления
  vec.Add(s,p);//добавить элемент в вектор
  vec.Print();//печать вектора
  //задача 3
  p = vec.Max();//найти максимальный элемент
  vec.Del(p);//удаление
  vec.Print();//печать
  //задача 4
  vec.Delenie();//деление
  vec.Print();//печать   
}