#include <iostream>
#include <cstdlib>
#include "fraction.h"
using namespace std;

void fraction::Read()
{
	cout <<  "\n Введите цену товара r- ";
	cin >> first;
	cout << "\n Введите количество товара -  ";
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
    cout << "\n Ошибка ввода, неверный тип данных! " << endl;
    system("pause");
    exit(1); //выход если ввод ошибочный
   }
  return 0;
}

void fraction::Show()
{

	cout <<" Стоимость товара = "<< fraction::Cost() << "\n ";
	cout << "\n ";
}
