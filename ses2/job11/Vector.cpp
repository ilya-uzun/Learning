#include "Vector.h"
#include <iostream>

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
	v.insert(v.begin() + pos, el);
}
//задание 3 для пятой задачи
template <class T>
T Vector<T>::Srednee_Tack5()
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
//добавление элемента el в стек на позицию pos
template <class T>
void Vector<T>::Add_Tack5(T el, int pos)
{
	vector <T> v;//вспомогательный вектор
	T t;
	int i=1;
	while(!s.empty())//пока стек не пустой
	  {
		t=s.top();//получить элемент из вершины стека
	//если номер элемента равен pos добавляем в вектор новый элемент
	if(i==pos) v.push_back(el);
	v.push_back(t);//добавляем t в вектор
	s.pop();//удаляем элемент из вершины стека
	i++;
}
s=copy_vector_to_stack(v);//копируем вектор в стек
}
//задача 3
//поиск максимального элемента
template <class T>
int Vector<T>::Max()
{
	T m=v[0];
	int n=0;
	for(int i=1; i < v.size(); i++)
	if(v[i]>m)
	  {
		m=v[i];	
		n=i;
		}
	return n;
}
// метод для пятой задачи
template <class T>
T Vector<T>::Max_Task5()
{
	T m=s.top();//m присвоить значение из вершины стека
	//в вектор скопировать элементы стека
	vector<T> v = copy_stack_to_vector(s);
	while(!s.empty())//пока стек не пустой
 	 {
	//сравниваем m и элемент в вершине стека
	if(s.top()>m) m = s.top();
	s.pop();//удаляем элемент из вершины стека
	 }
s = copy_vector_to_stack(v);//копируем вектор в стек
return m;
}
//удаление элемента из позиции pos
template<class T>
void Vector<T>::Del(int pos)
{
	v.erase(v.begin() + pos);
}
// метод для пятой задачи
template <class T>
void Vector<T>::Del_Task5()
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
	T m=v[0];
	int n=0;
	for(int i=1; i < v.size(); i++)
	if(v[i] < m)
	  {
		m=v[i];
		n=i;
		}
	return n;
}
// метод для пятой задачи
template <class T>
T Vector<T>::Min_Task5()
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
//
//деление всех элементов вектора на минимальный элемент
template <class T>
void Vector<T>::Delenie()
{
	int m = Min();
	T min = v[m];
	for(int i=0; i<v.size(); i++)
	v[i] = v[i] / min;
}
//деление всех элементов на минимальный
template <class T>
void Vector<T>::Delenie_Task5();
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


