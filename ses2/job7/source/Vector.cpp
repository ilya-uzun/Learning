#include "Vector.h"
#include <iostream>

//конструктор с параметрами

template <class T>
Vector<T>::Vector(int s,T k)
{
size=s;
data=new T[size];
for(int i=0;i<size;i++)
data[i]=k;
}
//конструкор копирования
template <class T> 
Vector<T>::Vector(const Vector<T>& a) {
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++) 
		data[i] = a.data[i];
}
//деструктор
template <class T>
Vector<T>::~Vector() {
	delete[]data;
	data = 0;
}
//операция присваивания
template <class T>
Vector<T> &Vector<T>::operator = (const Vector<T> &a) 
{
	if (this == &a) return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}
//операция доспупа  по индексу
template <class T>
T& Vector<T>::operator[](int index)
{
if (index < size) return data[index];
else std::cout<<"\nError! Index > size";
}
//операция для добавления константы
template <class T>
Vector<T> Vector<T>::operator + (const T k) 
{
	Vector<T> temp(size, k);
	for (int i = 0; i < size; i++)
		temp.data[i] += data[i]+k;
	return temp;
}
//операция для присваивания констаты

//операция для получения длины вектора
template <class T>
int Vector<T>::operator ()() 
{
	return size;
}
//операция ввода-вывода
template< typename T>
std::ostream& operator << (std::ostream& out,const Vector<T> &a) 
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i]<< " ";
	return out;
}
template< typename T>
std::istream& operator >> (std::istream& in, Vector<T> &a) 
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}


