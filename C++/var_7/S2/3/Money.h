//#pragma once
#include <iostream>

using namespace std;

class Money{
	int min, sec;

public:
	Money()
	{
		min = 0; sec = 0;
	}
	Money(int m, int s)
	{
		min = m; sec = s;
	}
	Money(const Money &t)
	{
		min = t.min; sec = t.sec;
	}
	~Money(){}

	int get_min() { return min; }
	int get_sec() { return sec; }
	void set_min(int m) { min = m; }
	void set_sec(int s) { sec = s; }

	//перегруженные операторы
	Money &operator = (const Money&); // опирация присваивания
	Money &operator ++ (); //
	Money operator ++ (int);// постфиксная операция
	// перегрузка вычтания
	friend Money operator - (Money&, int valuve);
	// перегрузка сложения через дружественную функцию
	friend Money operator + (const Money&, const Money&);
	//Перегрузить операции ввода и вывода объектов с помощью потоков.
	friend istream &operator >> (istream&in, Money &t);
	friend ostream &operator << (ostream&out, const Money& t);
};
