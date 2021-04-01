#include <iostream>
#include <cstdlib>
#include "fraction.h"
using namespace std;

fraction::fraction(double f, double s, double x_){
    first = f;
    second = s;
    x = x_;
}

void fraction::Read()
{
	cout <<  "\n Enter A - ";
	cin >> first;
	cout << "\n Enter B -  ";
	cin >> second;
}
// 
double  fraction::Cost()
{
	return (first * second);
}

double  fraction::Init()
{
  first = 0;
  second = 0;
    // проверка корректности ввода
  fraction::Read(); // вызов метода чтения
      if (cin.fail())
      {
        cout << "\n Input error, invalid data type! " << endl;//Ошибка ввода, неверный тип данных!
        system("pause");
        exit(1); //выход если ввод ошибочный
      }
  return 0;
}

void fraction::Show()
{

	cout <<" Value of goods = "<< fraction::Cost() << "\n ";//Стоимость товара 
	cout << "\n ";
}

void fraction::function(double x) {

  return (first*x+second);
}
