#pragma once
#include <iostream>
template <class T>
class Vector
{
public:
	//конструктор с параметрами: выделяет паметь под s элемент и заполняет ихзначение к
	 Vector(int s,T k);
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
	template <typename T1> friend std::ostream& operator << (std::ostream& out, const Vector<T1> &a);
	template <typename T1> friend std::istream& operator >> (std::istream& in, Vector<T1> &a);
private:
	int size;//размер вектора
	T* data;// указатель на денамический массив значеий вектора
};

#include "Vector.cpp"
