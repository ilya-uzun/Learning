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
	// задача 3
	int Max();//найти номер максимальнго элемента
	void Del(int pos);//удалить элемент из позиции pos
	// задача 4
	int Min();//найти номер минимальнго элемента
	void Delenie();//деление на минимальный
	// перегруженные операции ввода-вывода
	template <typename T1> friend std::ostream& operator << (std::ostream& out, const Vector<T1> &a);
	template <typename T1> friend std::istream& operator >> (std::istream& in, Vector<T1> &a);
private:
	int size;//размер вектора
	T* data;// указатель на денамический массив значеий вектора
};

//конструктор с параметрами
//конструктор без параметра
template <class T>
Vector<T>::Vector()
{
	len=0;
}
//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for(int i=0; i<n; i++)
	  {
		cin >> a;
		v.push_back(a);
	  }
	len=v.size();
}
//конструктор с параметром
template <class T>
Vector<T>::Vector(int s,T k)
{
	size = s;
	data = new T[size];
	for(int i=0; i < size; i++)
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

//печать
template <class T>
void Vector<T>::Print()
{
	for(int i=0; i < v.size(); i++)
	cout << v[i] << " ";
	cout << endl;
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
//задача 2 или задание 3 для пятой задачи
//вычислить среднее арифметическое
template<class T>
T Vector<T>::Srednee()
{
	T s=v[0];
	for(int i=1; i<v.size(); i++)
	s= s + v[i];
	int n = v.size();
	return s/n;
}
//добавление элемента
template<class T>
void Vector<T>::Add(T el, int pos)
{
//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	int n=1;//количество элементов в стеке
	T sum = s.top();//начальное значение для суммы
	s.pop();//удаляем элемент из вершины стека
	while(!s.empty())//пока стек не пустой
	  {
		sum = sum + s.top();//добавляем в сумму элемент из вершины стека
		s.pop();//удаляем элемент из вершины стека
		n++;//увеличиваем количество элементов
      }
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
	return sum/n;
}
//задача 3
//поиск максимального элемента
template <class T>
int Vector<T>::Max()
{
	T m=s.top();//m присвоить значение из вершины стека
	//в вектор скопировать элементы стека
	vector<T> v = copy_stack_to_vector(s);
	while(!s.empty())//пока стек не пустой
 	 {
		//сравниваем m и элемент в вершине стека
		if(s.top() > m) m = s.top();
		s.pop();//удаляем элемент из вершины стека
	 }
	s = copy_vector_to_stack(v);//копируем вектор в стек
	return m;
}
// метод для пятой задачи
//удаление элемента из позиции pos
template<class T>
void Vector<T>::Del(int pos)
{
	T m=Max();//поиск максимального
	vector<T> v;
	T t;
	while(!s.empty())//пока стек не пустой
	  {
		t=s.top();//получить элемент из вершины стека
	//если t не равен максимальному, то добавить его в вектор
	if(t!=m) v.push_back(t);
	s.pop();//удалить элемент из стека
	  }
	//копируем вектор в стек
	s=copy_vector_to_stack(v);
}
//задача 4
template <class T>
int Vector<T>::Min()
{
	T m = s.top();
	vector<T> v = copy_stack_to_vector(s);
	while(!s.empty())
	  {
		if(s.top()<m) m = s.top();
		s.pop();
	  }
	s = copy_vector_to_stack(v);
	return m;
}

//деление всех элементов вектора на минимальный элемент
template <class T>
void Vector<T>::Delenie()
{
	T m=Min();
	vector<T> v;
	T t;
	while(!s.empty())
	  {
		t = s.top();
		v.push_back(t/m);
		s.pop();
		}
	s = copy_vector_to_stack(v);
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



