#pragma once
#include <iostream>
using namespace std;
// template <class T>
// class Iterator
// {
// 	friend class Vector;//дружеский класс
// public:
// 	Iterator() { elem = 0; }//конструктор без параметров
// 	Iterator(const Iterator& it) { elem = it.elem; }//консруктор копирования
// 	//перегруженные операции сравнения
// 	bool operator ==(const Iterator& it) { return elem == it.elem; }
// 	bool operator !=(const Iterator& it) { return elem != it.elem; };
// 	//перегруженная операция  инкремент
// 	void operator ++() { ++elem; };
// 	//перегруженная операция декремент
// 	void operator --() { --elem; }
// 	//перегруженная операция разыменованя
// 	int& operator *() const { return *elem; }
// private:
// 	int* elem;// указатель на элемент типа int
// };

template <class T>
class Vector
{
public:
	//конструктор с параметрами: выделяет паметь под s элемент и заполняет ихзначение к
	Vector(int s, T k = 0);
	//конструкор копирования 
	Vector(const Vector<T> &a);
	//конструктор с параметрами
	~Vector();
	//деструктор
	Vector& operator=(const Vector<T> &a);
	//операция присваивания
	T& operator[](int index);
	//операция доступа по индексу
	Vector operator+(const T k);
	//операция для добавления константы
	int operator()();
	// перегруженные операции ввода-вывода
	friend ostream& operator << <>(ostream& out, const Vector<T> &a);
	friend istream& operator >> <>(istream& in, Vector<T> &a);

	//Iterator first() { return beg; } //возвращает указатель на первый элемент
	//Iterator last() { return end; } // возвращает ук. следующий за последним

private:
	int size;//размер вектора
	T* data;// указатель на денамический массив значеий вектора
	//Iterator beg;//указатель на первый элемент
	//Iterator end;// уазатель на элемент следущий за последним

};