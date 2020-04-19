
#include <iostream>
#include "Time.h"
using namespace std;

// перегрузка операции присваивания
Time &Time::operator=(const Time &t)
{
	//перегрузка на само присваивание
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

// перегрузка префиской операции инкремент
Time &Time::operator++() {

	int temp = min * 60 + sec;
	temp++;
	min = temp / 60;// целая часть при делении мин
	sec = temp % 60;// остаток при делении секунды
	return *this;
}

// перегрузка постфиксная операции инкремент
Time Time::operator ++ (int)
{
	int temp = min * 60 + sec;
	temp++;
	Time t(min, sec);
	min = temp / 60;
	sec = temp % 60;
	return t;
}

//Перегрузка бинарной операции сложения
Time operator+(const Time& x, const Time& y)
{
	int temp1 = x.min * 60 + x.sec;
	int temp2 = y.min * 60 + y.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}

//Перегрузка бинарной операции вычетния объектов
Time operator-( Time& t, int valuve)
{
	int temp = (t.min * 60 + t.sec) - valuve;
	Time p;
	if (temp > 0) // блокировка деления на ноль
		{
		p.min = temp / 60;
		p.sec = temp % 60;
		}
		else // при пытке вычесть больше секунд, чем есть выводим 0
 		{
		p.min = 0;
		p.sec = 0;
		}
		return p;
}

//Перегрузка глобальной функции-оператора ввода
istream& operator >> (istream& in, Time& t)
{
	cout << "min : ";
	in >> t.min;
	cout << "sec : ";
	in >> t.sec;
	return in;
}

//перегрузка глобальной функции-оператора вывода
ostream& operator << (ostream& out, const Time& t) {
	return (out << t.min << ":" << t.sec );
}
