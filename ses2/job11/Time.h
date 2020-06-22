#include <iostream>

using namespace std;

class Time{
	int min, sec;
public:
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

	int get_min() { return min; }
	int get_sec() { return sec; }
	void set_min(int m) { min = m; }
	void set_sec(int s) { sec = s; }

	void simTime (int *minS, int *secS);
	//перегруженные операторы
	Time &operator = (const Time&); // операция присваивания
	Time &operator ++ (); //
	Time operator ++ (int);// постфиксная операция
	Time operator/(const Time&);
	Time operator/(const int&);
	bool operator >(const Time&);
	bool operator <(const Time&);
	bool operator !=(const Time&);
	// перегрузка сложения через дружественную функцию
	friend Time operator + (const Time&, const Time&);
	 // перегрузка вычетания
	friend Time operator - (Time&, int valuve);
	 // перегрузка вычетания
	friend Time operator + (Time&, int valuve);
	//Перегрузить операции ввода и вывода объектов с помощью потоков.
	friend istream &operator >> (istream&in, Time &t);
	friend ostream &operator << (ostream&out, const Time& t);
};
