#pragma once
#include "Time.h"
//#include "Vector.h"
#include <iostream>
using namespace std;

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
	return out;
	}
	template <typename T1> friend std::istream& operator >> (std::istream& in, Vector<T1> &a)
	{
		for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
	}

	//Iterator first() { return beg; } //возвращает указатель на первый элемент
	//Iterator last() { return end; } // возвращает ук. следующий за последним

private:
	int size;//размер вектора
	T* data;// указатель на денамический массив значеий вектора
	//Iterator beg;//указатель на первый элемент
	//Iterator end;// уазатель на элемент следущий за последним

};
int main()
{
   //инициализация, ввод и вывод значений вектора
   Time t;
   cin>>t;
   cout<<t;
   Vector <int>  A(5,0);//создали вектор из 5 элементов, заполненые нулями 
   cout << "\n Input Vector A = " << A << endl;
   cin >> A;//ввели с клавиатуры значения элементов вектора(ошибка компиляции считает что cin вводит char)
   //cout << A << "\n";//вывели значения элементов вектора
   //  Vector <int> b(3);//создали вектор из 5 элементов, заполненые нулями 
   //  cout << "Input Vector B " << endl;
   //  cin >> b;//ввели с клавиатуры значения элементов вектора(ошибка компиляции считает что cin вводит char)
   //  //cout << b << "\n";//вывели значения элементов вектора
   //  Vector <int> c(2);
   //  c[0] = a[2]+b[1];// ввести у элемент вектора с сумму элементов векторов а и b
   //  cout << "Output Vector C sima A[2]+B[1]= "<< endl;
   //  cout <<  c << endl;
   //  // определение длины ектора
   //  cout << "Size Vector (C) = "<< endl;
   //  cout <<  c() << endl;
   //  cout << "\n";
    //разыменовываем значения, которое возвращает a.first() выводим его
    //cout << "First element Vektora A ="<< *(a.first()) << endl;
return 0;
}

