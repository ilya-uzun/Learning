#pragma once
#include <iostream>
#include <iterator>
#include "Time.h"
#include <map> //словарь
using namespace std;
//параметризированный класс
template<class T>
class Container
{
  map<int, T> v; //контейнер словарь
    int len; //длина словаря
public:
    Container(void)
    {
      len = 0;
    } //конструктор без параметров

    Container(int n)
    {
      T a;
      for(int i=0; i<n; i++)
        {
         cin >> a;
          v[i] = a;//записать а в словарь
        }
      len = v.size();
    } //конструктор с параметрами

    void Print()
    {
      for(int i=0; i < v.size(); i++)
      cout << i << " - " << v[i] <<" " << endl;
      cout << endl;
    } //печать

    ~Container(void){} //деструктор
    
    T Srednee()
    {
      Time s = v[0]; //начальное значение суммы – первый элемент словаря
      //перебор словаря
      for(int i=1; i<v.size(); i++)
      s = s + v[i];
      int n = v.size();//количество элементов в словаре
      return s/n;
    }

    void Add(int n, T el)
    {
      v.insert(make_pair(n, el));//формируем пару и добавляем ее в словарь
    }

    int Max()
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

    int Min()
    {
    	T m = v[0];
	    int n = 0;
	    for(int i=1; i < v.size(); i++)
	    if(v[i] < m)
	      {
	      	m = v[i];
	      	n = i;
	     	}
      return n;
    }
    
    void Del()
    {
      int max = Max();
      cout << "max=" << v[max] << " nom=" << max << endl;
      v.erase(max);//удалить максимальный элемент
    }

    void Delenie()
    {
      T m = v[Min()];//найти минимальный элемент
      cout << "Min= " << m << endl;
      for(int i=0; i < v.size(); i++)
      v[i] = v[i]/m;
    }
};

