#pragma once
#include <iostream>
//using namespace std;
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
	 Vector(int s,T k)
	 {
		 size=s;
data=new T[size];
for(int i=0;i<size;i++)
data[i]=k;
	 }
	//конструкор копирования 
	 Vector(const Vector<T> &a)
	 {
		 	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++) 
		data[i] = a.data[i];
	 }
	//конструктор с параметрами
	~Vector()
	{
	delete[]data;
	data = 0;
	}
	//деструктор
	Vector& operator=(const Vector<T> &a)
	{
		if (this == &a) return (T)(*this);
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	// beg = a.beg;
	// end = a.end;
	return (T)(*this);	
	}
	//операция присваивания
	T& operator[](int index)
	{
		if (index<size) return (T) (data[index]);
		else std::cout<<"\nError! Index>size";
	}
	//операция доступа по индексу
	Vector operator+(const T k)
	{
	Vector<T> temp(size, k);
	for (int i = 0; i < size; i++)
		temp.data[i] += data[i]+k;
	return (T)temp;
	}
	//операция для добавления константы
	int operator()()
	{
		return size;
	}
	// перегруженные операции ввода-вывода
	template <typename T1> friend std::ostream& operator << (std::ostream& out, const Vector<T1> &a)
	{
			for (int i = 0; i < a.size; ++i)
		out << a.data[i]<< " ";
	return (T)out;
	}
	template <typename T1> friend std::istream& operator >> (std::istream& in, Vector<T1> &a)
	{
		for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return (T)in;
	}

	//Iterator first() { return beg; } //возвращает указатель на первый элемент
	//Iterator last() { return end; } // возвращает ук. следующий за последним

private:
	int size;//размер вектора
	T* data;// указатель на денамический массив значеий вектора
	//Iterator beg;//указатель на первый элемент
	//Iterator end;// уазатель на элемент следущий за последним

};