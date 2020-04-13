
#pragma once
#include <iostream>
using namespace std;
class Vector
{
public:
	//конструктор с параметрами: выделяет  паметь под s элемент и заполняет ихзначение к

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
	friend ostream &operator << (ostream& out, const Vector& a);
	friend iostream &operator >> (iostream& out, const Vector& a);


	Iterator first() { return beg; } //возвращает указатель на первый элемент
	Iterator last() { return end; } // возвращает ук. следующий за последним

private:
	int size;//размер вектора
	int* data;// указатель на денамический массив значеий вектора

	//int size;
	//int* data;
	Iterator beg;//указатель на первый элемент
	Iterator end;// уазатель на элемент следущий за последним

};

///----///----///----///----///----///----///----///----///

class Iterator
{
	friend class Vector;//дружеский класс

public:
	Iterator() { emel = 0; }//конструктор без параметров
	Iterator(const Iterator) { emel = it.elem; }//консруктор копирования
	//перегруженные операции сравнения
	bool operator ==(const Iterator& it) { return elem == it.elem; }
	bool operator !=(const Iterator& it) { return elem != it.elem; }
	//перегруженная операция  инкремент
	void operator ++() { ++elem; }
	//перегруженная операция декремент
	void operator --() { --elem; }
	//перегруженная операция разыменованя
	int& operator *() const { return *elem; }



private:
	int* elem;// указатель на элемент типа int


};