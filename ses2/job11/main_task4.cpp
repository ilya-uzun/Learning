#include "Time.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef stack<Time>St;//стек
typedef vector<Time>Vec;//вектор

St make_stack(int n)
{
  St s;
  Time t;
  for(int i=0; i<n; i++)
    { cin>>t;//ввод переменной
      s.push(t);//добавление ее в стек
    }
  return s;//вернуть стек как результат функции
} 
// ункции для работы с вектором и стеком
//копирует стек в вектор
Vec copy_stack_to_vector(St s)
{
  Vec v;
  while(!s.empty())//пока стек не пустой
    {
    //добавить в вектор элемент из вершиы стека
      v.push_back(s.top());
      s.pop();
    }
return v; //вернуть вектор как результат функции
}
//копирует вектор в стек
St copy_vector_to_stack(Vec v)
{
  St s;
  for(int i=0;i<v.size();i++)
    {
      s.push(v[i]);//добавить в стек элемент вектора
    }
return s; //вернуть стек как результат функции
}
//задача 3
//вычисление среднего значения
Time Srednee(St s)
{
  Vec v = copy_stack_to_vector(s);//копируем стек в вектор
  int n = 1;
  Time sum = s.top();//начальное значениедля суммы
  s.pop();//удалить первый элемент из вектора
  while(!s.empty())//пока стек не пустой
    {
      sum = sum + s.top();//добавить в сумму элемент из вершины стека
      s.pop();//удалить элемент
      n++;
    }
  s = copy_vector_to_stack(v);//скопировать вектор в стек
  return sum / n; //вернуть среднее арифметическое
}
//добавление элемента в стек
void Add_to_stack(St &s,Time el,int pos)
{
  Vec v;
  Time t;
  int i=1;//номер элемента в стеке
  while(!s.empty())//пока стек не пустой
    {
      t = s.top();//получить элемент из вершины
      //если номер равен номеру позиции, на котоую добвляем элемент
      if(i == pos) v.push_back(el);//добавить новый элемент в вектор
      v.push_back(t);//добавить элемент из стека в вектор
      s.pop();//удалить элемент из стека
      i++;
    }
  s = copy_vector_to_stack(v);//копируем вектор в стек
}
//задание 4
//поиск максимального элемента в стеке
Time Max(St s)
{
  Time m = s.top();//переменной m присваиваем значение из вершины стека
  Vec v = copy_stack_to_vector(s);//копируем стек в вектор
  while(!s.empty())//пока стк не пустой
    {
      if(s.top() > m)m = s.top();//срвниваем m и элемнт в вершине стека
      s.pop();//удаляем элемент из стека
    }
  s = copy_vector_to_stack(v);//копиуем вектор в стек
  return m; //возвращаем m
}
//Удалить максимальный элемент из стека
void Delete_from_stack(St&s)
{
  Time m=Max(s);//находим максимальный элемент
  Vec v;
  Time t;
  while(!s.empty())//пока стек не пустой
    {
      t=s.top();//получаем элемент из вершины стека
      //если он не равен максимальному, заносим элемент в вектор
      if(t!=m) v.push_back(t);
      s.pop();//удаляем элемент из стека
    }
  s=copy_vector_to_stack(v);//копируем вектор в стек
}
// задание 5
//поиск минимального элемента
Time Min(St s)
{
  Time m=s.top();
  Vec v=copy_stack_to_vector(s);
  while(!s.empty())
    {
      if(s.top()<m)m=s.top();
      s.pop();
    }
    s=copy_vector_to_stack(v);
  return m;
}
//деление на минимальный
void Delenie(St &s)
{
  Time m=Min(s);//находим минимальный элемент
  Vec v;
  Time t;
  while(!s.empty())//пока стек не пустой
    {
      t = s.top();//получаем элемент из вершины
      v.push_back(t/m);//делим t на минимальный и добавляем в вектор
      s.pop();//удаляем элемент из вершины
    }
  s=copy_vector_to_stack(v);//копируем вектор в стек
}
void print_stack(St str)
{
  int k = 0;
  for(int i = 0; i < str.size(); i++) k++;
  cout << "Number of stack elements " << k << endl;
  cout << "Outputc top stack - "  << str.top()<< endl;
}

int main()
{
  Time t;
  St s;
  int n;
  cout <<"n?";
  cin >> n;
  s = make_stack(n);//создать стек
  print_stack(s);//печать стека
  t = Srednee(s);//вычисляем среднее
  cout << "Srednee=" << Srednee(s) << endl;
  cout << "Add srednee:" << endl;
  cout << "pos?";
  int pos;
  cin >> pos;//вводим позицию для добавления
  Add_to_stack(s, t, pos);//добавление элемента
  print_stack(s);//печать   
  //задание 4
  cout<<"Delete Max:"<<endl;
  Delete_from_stack(s);
  print_stack(s);
  //задание 5 
  cout<<"Delenie:"<<endl;
  Delenie(s);
  print_stack(s);
}