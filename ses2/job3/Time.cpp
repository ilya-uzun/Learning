
#include <iostream>
#include "Time.h"
using namespace std;

// перегрузка операции присваивания
Time &Time::operator=(const Time &t) {
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
	min = temp / 60;
	sec = temp % 60;
	return *this;
}

// перегрузка постфиксная операции инкремент
Time Time::operator ++ (int) {

	int temp = min * 60 + sec;
	temp++;
	Time t(min, sec);
	min = temp / 60;
	sec = temp % 60;
	return t;
}

//Перегрузка бинарной операции сложения
Time Time::operator+(const Time& t) {
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}

//Перегрузка глобальной функции-оператора ввода
istream& operator >> (istream& in, Time& t) {
	cout << "min ? ";
	in >> t.min;
	cout << "sec ? ";
	in >> t.sec;
	return in;
}

//перегрузка глобальной функции-оператора вывода
ostream& operator << (ostream& out, const Time& t) {
	return (out << t.min << ":" << t.sec );
}
