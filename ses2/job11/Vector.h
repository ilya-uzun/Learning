#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Vector
{
	vector <T> v;//последовательный контейнер для хранения элементов вектора
	int len;
public:
	Vector(void);//конструктор без параметр
	Vector(int n);//конструктор с параметром
	//конструктор с параметрами: выделяет паметь под s элемент и заполняет ихзначение к
	Vector(int s,T k);
	//конструкор копирования 
	Vector(const Vector<T> &a);
	//конструктор с параметрами
	void Print();//печать
	~Vector();
	//деструктор
	Vector& operator=(const Vector<T> &a);
	//операция присваивания
	T& operator[](int index);
	//операция доступа по индексу
	Vector operator+(const T k);
	//операция для добавления константы
	int operator()();
	// задача 2 
	T Srednee();//вычисление среднего арифметического
	void Add(T el, int pos);//добавление элемента el на позицию pos
	// задание 3 для пятой задачи
	T Srednee_Tack5();//вычисление среднего арифметического
	void Add_Tack5(T el, int pos);//добавление элемента el на позицию pos
	// задача 3
	int Max();//найти номер максимальнго элемента
	T Max_Task5();
	void Del(int pos);//удалить элемент из позиции pos
	void Del_Task5(int pos);
	// задача 4
	int Min();//найти номер минимальнго элемента
	T Min_Task5();
	void Delenie();//деление на минимальный
	void Delenie_Task5();
	// перегруженные операции ввода-вывода
	template <typename T1> friend std::ostream& operator << (std::ostream& out, const Vector<T1> &a);
	template <typename T1> friend std::istream& operator >> (std::istream& in, Vector<T1> &a);
private:
	int size;//размер вектора
	T* data;// указатель на денамический массив значеий вектора
};

#include "Vector.cpp" // не компелировался проект
