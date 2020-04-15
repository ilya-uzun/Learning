//#pragma once
#include <iostream>

using namespace std;

class Time{
	int min, sec;
	Time()
	{
		min = 0; sec = 0;
	}
	Time(int m, int s)
	{
		min = m; sec = s;
	}
	Time(const Time &t)
	{
		min = t.min; sec = t.sec;
	}
	~Time(){}
public:
	//int get_min() { return min; }
	//int get_sec() { return sec; }
	//void set_min(int m) { min = m; }
	//void set_sec(int s) { sec = s; }

	//перегруженные операторы
	Time& operator = (const Time&); // опирация присваивания
	Time& operator ++ (); //
	Time operator ++ (int);// постфиксная операция
	Time operator + (const Time&);
	//Перегрузить операции ввода и вывода объектов с помощью потоков.
	 istream &operator >> (istream&in, Time &t);
	 ostream &operator << (ostream&out, const Time& t);
};
