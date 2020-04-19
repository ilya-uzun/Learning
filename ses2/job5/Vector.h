#pragma once
#include "Object.h"
#include <string>
#include <iostream>

using namespace std;
class Vector
{
public:
	Vector(void);// кнтсруктор без параметров
	Vector(int);// контруктор копирования
public:
	~Vector(void);// деструктор
	void Add(Object*);//добавление элемента в вектор
	friend ostream& operator<< (ostream &out, const Vector&);// операция вывода
private:
	Object** beg;// указтель на первый элемент вектора
	int size;// размер
	int cur;// текущая позиция

};
