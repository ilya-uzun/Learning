// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>
#include "Route.h"
using namespace std;

// Функци для возврата объекта как результата
Route make_Route() {
	string s;
	string i;
	float d;
	cout << " Введите наименование : ";
	cin >> s;
	cout << " Введите количество : ";
	cin >> i;
	cout << " Введите стоимость : ";
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
	setlocale(LC_ALL, "russian");
	//конструкор без параметрами
	Route t1;
	t1.show();
	//конструкор с параметрами
	Route t2;
	t2.show();
	//конструкор копирования
	Route t3 = t2;
	t3.set_start("Perm 2");
	t3.set_finish("Moskow");
	t3.set_time_in_way(24.0);
	//конструкор копирования
	print_Route(t3);
	//конструкор копирования
	t1 = make_Route();
	t1.show();
}
