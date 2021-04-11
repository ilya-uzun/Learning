#pragma once
#include <iostream>
#include <string>
#include "Route.h"
using namespace std;

// Функци для возврата объекта как результата
Route make_Route() {
	string s;
	int i;
	int d;
	cout << "Enter the name of the: ";// Введите наименование 
	cin >> s;
	cout << "Enter the quantity : ";//Введите количество
	cin >> i;
	cout << "Enter the cost : ";//Введите стоимость 
	cin >> d;
	Route t(s, i, d);
	return t;
}

//Функция для передачи объекта как параметра
void print_Route(Route t) 
{
	t.show();
}

int main(){

	//конструкор без параметрами
	Route t1;
	t1.show();
	//конструкор с параметрами
	Route t2;
	t2.show();
	//конструкор копирования
	Route t3 = t2;
	t3.set_CPU("ADM Ryzen 5 5600X");
	t3.set_RAM(8);
	t3.set_HDD(950);
	//конструкор копирования
	print_Route(t3);
	//конструкор копирования
	t1 = make_Route();
	t1.show();
}
