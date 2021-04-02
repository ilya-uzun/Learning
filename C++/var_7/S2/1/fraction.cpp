#include <iostream>
#include <cstdlib>
#include "fraction.h"
using namespace std;

fraction::fraction(){
    fraction::set_P(0,0,0); 
}

void fraction::Read()
{
	cout <<  "\n Enter A - ";
	cin >> first;
	cout << "\n Enter B -  ";
	cin >> second;
}
/* 
double  fraction::Cost()
{
	return (first * second);
}
*/
double  fraction::Init()
{
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

	cout <<"y=A*x+B= "<< fraction::function(x) << "\n ";//Стоимость товара 
	cout << "\n ";
}

void Set_P(double f, double s, double x_)
{
    first = f;
    second = s;
    x = x_;

}


double  fraction::function(double x_) {

  return (first * x_ + second);
}
