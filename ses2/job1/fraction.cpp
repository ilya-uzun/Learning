#include <iostream>
#include <cstdlib>
#include "fraction.h"
using namespace std;

void fraction::Read()
{
	cout <<  "\n Enter the product price - ";// Введите цену товара
	cin >> first;
	cout << "\n Enter the quantity of the product -  ";// Введите количество продукта
	cin >> second;
}
// стоимость товара
int fraction::Cost()
{
	return (first * second);
}

int fraction::Init()
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
