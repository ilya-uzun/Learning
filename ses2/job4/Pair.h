#pragma once
#include <string>
#include <iostream>
//using namespace std;

class Pair {
	// контструктор без параметров
public:
	Pair(void);
	//деструктор
	virtual ~Pair(void);
	//конструктор с параметрами
	Pair(int, int);
	//конструктор копирования
	Pair(const Pair&);
	//селекторы
	int get_first(){ return first; }
	int get_second() { return second; }
	//модификаторы
	int set_first(int);
	int set_second(int);
	// перегрузка опирации присваивания
	Pair& operator= (const Pair&);
	//глобальные  операторы функции ввода-вывода
	friend std::istream& operator >> (std::istream &in, Pair& pair);
	friend std::ostream& operator << (std::ostream &out, const Pair& pair);
//атрибуты
protected:
	int first;
	int second;
};