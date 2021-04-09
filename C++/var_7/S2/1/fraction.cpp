#include <iostream>
//#include <cstdlib>
#include "fraction.h"
using namespace std;

fraction::fraction(){
    first = 0;
    second = 0;
    x = 0;
}

void fraction::Read()
{
	cout <<  "\n Enter A - ";
	cin >> first;
	cout << "\n Enter B -  ";
	cin >> second;
	cout << "\n Enter x -  ";
	cin >> x;
}

double  fraction::Init()
{
   // проверка корректности ввода
  fraction::Read(); // вызов метода чтения
      if (cin.fail())
      {
        cout << "\n Input error, invalid data type! " << endl;//Ошибка ввода, неверный тип данных!
	return 1;
      }
  return 0;
}

void fraction::Show()
{

	cout <<"y=A*x+B= "<< fraction::function(x) << "\n ";//Стоимость товара 
	cout << "\n ";
}

double  fraction::function(double x_) {

  return (first * x_ + second);
}
