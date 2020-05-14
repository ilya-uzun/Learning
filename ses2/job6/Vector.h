#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class Vector;//дружеский класс
public:
	Iterator() { elem = 0; }//конструктор без параметров
	Iterator(const Iterator& it) { elem = it.elem; }//конструктор копирования
	//перегруженные операции сравнения
	bool operator ==(const Iterator& it) { return elem == it.elem; }
	bool operator !=(const Iterator& it) { return elem != it.elem; };
	//перегруженная операция  инкремент
	void operator ++() { ++elem; };
	//перегруженная операция декремент
	void operator --() { --elem; }
	//перегруженная операция разыменования
	int& operator *() const { return *elem; }
private:
	int* elem;// указатель на элемент типа int
};
class Vector
{
public:
	////конструктор с параметрами: выделяет память под s элемент и заполняет их значение к
	Vector(int s, int k = 0);
	//конструкор копирования
	Vector(const Vector& a);
	//конструктор с параметрами
	~Vector();
	//деструктор

	Vector& operator=(const Vector& a);
	//операция присваивания
	int& operator[](int index);
	//операция доступа по индексу
	Vector operator+(const int k);
	//операция для добавления константы
	int operator()();
	// перегруженные операции ввода-вывода
	friend ostream& operator << (ostream& out, const Vector& a);
	friend istream& operator >> (istream& in, Vector& a);

	Iterator first() { return beg; } //возвращает указатель на первый элемент
	Iterator last() { return end; } // возвращает ук. следующий за последним

private:
	int size;//размер вектора
	int* data;// указатель на динамический массив значений вектора
	Iterator beg;//указатель на первый элемент
	Iterator end;// указатель на элемент следящий за последним
};
