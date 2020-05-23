#include "Time.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<Time> TVector;
Time s;
//формирование вектора
TVector make_vector(int n)
{
Time a;
TVector v;
  for(int i=0; i < n; i++)
    {
      cin >> a;
      v.push_back(a);
   }
  return v;
}
//печать вектора
void print_vector(TVector v)
{
    for(int i=0; i<v.size(); i++)
    cout << v[i] << endl;
    cout << endl;
}

struct Greater_s //больше, чем s
{
    bool operator()(Time t)
      {
        if (t>s) return true; 
        else return false;
      }
};

Time srednee(TVector v)
{
    Time s = v[0];
    //перебор вектора
    for(int i=1;i<v.size();i++)
    s = s + v[i];
    int n = v.size();//количество элементов в векторе
    return s/n;
}

struct Comp_less // для сортировки по убыванию
{
public:
    bool operator()(Time t1,Time t2)
      {
        if(t1 > t2) return true;
        else return false;
      }
};

struct Equal_s
{
    bool operator()(Time t)
      {
        return t == s;
      }
};
// задание 7
void del(Time& t)
{
    t = t / s;
}

void main()
{
    int n;
    cout << "Enter N :";
    cin >> n;
    TVector v;
    v = make_vector(n);
    print_vector(v);
    //задание 3
    TVector::iterator i;
    //поставили итератор i на максимальный элемент
    i=max_element(v.begin(),v.end());
    cout << "max=" <<*(i) << endl;
    Time m=*(i);
    s = srednee(v);//нашли среднее арифметическое вектора
    cout<<"sred="<<s<<endl;
    //замена с использованием предиката
    replace_if(v.begin(),v.end(), Greater_s(),m);
    cout << "Replacement" << endl; //замена
    print_vector(v);
    //задание 4
    //по убыванию
    cout << "Sortirovka po ubivaniu:" << endl;
    sort(v.begin(), v.end(), Comp_less());
    print_vector(v);
    //по возрастанию
    cout << "Sortirovka po vozrasaniu:" << endl;
    sort(v.begin(), v.end());
    print_vector(v);
    //задание 5
    cout<<"POISK"<<endl;
    cin>>s;
    //поиск элементов, удовлетворяющих условию предиката
    i=find_if(v.begin(), v.end(), Equal_s());
    if(i != v.end())//если нет конца вектора
    cout << *(i) << endl;
    else
    cout << "Not such element!" << endl;
    //задание 6
    cout << "UDALENIE" << endl;
    i = min_element(v.begin(), v.end());
    s = *i;
    //переместили элементы совпадающие с min в конец вектора
    i = remove_if(v.begin(), v.end(), Equal_s());
    //удалили элементы, начиная с i и до конца вектора
    v.erase(i, v.end());
    print_vector(v);
    // задание 7
    cout << "DELENIE" << endl;
    i = max_element(v.begin(), v.end());
    s = *i;
    //для каждого элемента вектора вызывается функция del
    for_each(v.begin(), v.end(), del);
    print_vector(v);
}