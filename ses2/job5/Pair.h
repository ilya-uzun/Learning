
#include <string>
#include <iostream>
#include "Object.h"

using namespace std;
class Pair:
public Object{
	// контструктор без параметров
public:
	Pair(void);
public:
	//деструктор
	virtual ~Pair(void);
	void Show(); // функция для просмотров класса с помощью указателя
	//конструктор с параметрами
	Pair(int, int);
	//конструктор копирования
	Pair(const Pair&);
	//селекторы
	int get_first() { return first; }
	int get_second() { return second; }
	//модификаторы
	int set_first(int);
	int set_second(int);
	// перегрузка опирации присваивания
	Pair& operator= (const Pair&);
	//глобальные  операторы функции ввода-вывода
	friend istream& operator >> (istream& in, Pair& pair);
	friend ostream& operator << (ostream& out, const Pair& pair);
	//атрибуты
protected:
	int first;
	int second;
};
