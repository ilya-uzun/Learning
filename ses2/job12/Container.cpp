#include "Container.h"
//реализация методов
//конструктор без параметров
template <class T>
Container<T>::Container()
{
  len = 0;
}
//деструктор
template <class T>
Container<T>::~Container(void){}
//конструктор c параметрами
template <class T>
Container<T>::Container(int n)
{
  T a;
    for(int i=0; i<n; i++)
      {
        cin >> a;
        v[i] = a;//записать а в словарь
      }
    len = v.size();
}
//вывод контейнера
template <class T>
void Container<T>::Print()
{
    for(int i=0; i < v.size(); i++)
    cout <<i << " - " << v[i] <<" " << endl;
    cout << endl;
}
//вычисление среднего арифметического
// задание 3 
template<class T>
T Container<T>::Srednee()
{
    Time s = v[0]; //начальное значение суммы – первый элемент словаря
    //перебор словаря
    for(int i=1; i<v.size(); i++)
    s = s + v[i];
    int n = v.size();//количество элементов в словаре
    return s/n;
}
//добавление
template<class T>
void Container<T>::Add(int n, T el)
{
    v.insert(make_pair(n, el));//формируем пару и добавляем ее в словарь
}
// задание 4
template <class T>
int Container<T>::Max()
{
    map <int, T> i=v.begin();//итератор поставили на первый элемент
    int nom = 0, k = 0;
    Time m = (*i).second;//значение первого элемента
    while(i != v.end()) //пока нет конца контейнера
      {
        if(m < (*i).second)
          {
            m = (*i).second;
            nom = k;
          }
        i++;//итератор
        k++;//счетчик элементов
      }
    return nom;//номер max
}
template <class T>
void Container<T>::Del()
{
    int max=Max();
    cout << "max=" << v[max] << " nom=" << max << endl;
    v.erase(max);//удалить максимальный элемент
}
//задание 5
template<class T>
int Container<T>::Min()
{
    map<int, T> i=v.begin();
    int nom = 0, k = 0;
    Time m=(*i).second;//значение первого элемента
    while(i!=v.end())
      {
        //минимальный элемент не должен быть равен 0
        if((*i).second.get_min()!= 0 && (*i).second.get_sec() != 0)
        if(m>(*i).second)
          {
            m=(*i).second;
            nom = k;
          }
        i++;//итератор
        k++;//счетчик элементов
      }
    return nom;//номер min
}
template<class T>
void Container<T>::Delenie()
{
    T m = v[Min()];//найти минимальный элемент
    cout << "Min= " << m << endl;
    for(int i=0; i < v.size(); i++)
    v[i] = v[i]/m;
}