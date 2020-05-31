#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <algorithm> 
using namespace std;
// сохранения объектов класса Person
int make_file(const char* f_name)
{
    fstream stream(f_name, ios::out|ios::trunc);//открыть для записи
    if(!stream)return -1;//ошибка открытия файла
    int n;
    cout<<"Enter element base volume :";//Введите базу элементов объема
    cin >> n;
    vector<Person> vp;
    Person p;
    // запсть в вектор
    for(int i = 0; i < n; i++)
      {
        cin >> p;
        vp.push_back(p);//ввод атрибутов объекта из стандартного потока
      }
      // сортировака по имени
    sort(vp.begin(), vp.end(), [](Person &p1, Person &p2)
      {
         return  (p1.get_name() < p2.get_name());
      });
      // запись вектора в  файл
     for(int i = 0; i < vp.size(); i++)
      {
        stream << vp[i];
      }
    stream.close();//закрыть поток
    return n;//вернуть количество записанных объектов
}
// чтение объектов из потока
int print_file(const char*f_name)
{
    fstream stream(f_name,ios::in);//открыть для чтения
    if(!stream) return -1;//ошибка открытия файла
    vector<Person> vp;
    Person p; 
    int i = 0;
    while(stream >> p)
      {
        cout << p <<"\n";
        i++;
      }
    sort(vp.begin(), vp.end(), [](Person &p1, Person &p2)
    {
    return  (p1.get_name() < p1.get_name());
    }); 
    stream.close();
    return i;
}
// удаление объектов из потока
int del_file(const char*f_name, int k)
{
    fstream temp("temp", ios::out);//открыть для записи
    fstream stream(f_name, ios::in);//открыть для чтения
    if(!stream) return -1;//ошибка открытия файла
    int i = 0;
    Person p;
    while(stream >> p)//пока нет конца файла выполняем чтение объекта
      {
//если прочитан признак конца файла,то выход из цикла
        if (stream.eof()) break;
        i++;
//если номер объекта не равен k, то записываем его во вспомогательый файл
        if(i!=k) temp << p;
      }//while(stream>>p)
//закрыть файлы
    stream.close(); 
    temp.close();
    remove(f_name);//удалить старый файл
    rename("temp", f_name);// переименовать temp
    return i;//количество прочитанных
}
//добавить объект в поток
int add_file(const char*f_name, int k, Person pp)
{
    fstream temp("temp", ios::out);//открыть для записи
    fstream stream(f_name,ios::in);//открыть для чтения
    if(!stream)return -1;//ошибка открытия файла
    Person p; 
    int i=0, l=0;
    while(stream >> p)
      {
        if (stream.eof())break;
        i++;
        if(i==k)
          {
            temp << pp;//записать в temp новую запись
            l++;
          }
        temp<<p;
      }
    stream.close(); 
    temp.close();
    remove(f_name);
    rename("temp", f_name);
    return l;//количество добавленных
}
// добаление в середину файла
int add_end(const char*f_name, Person pp)
{
    fstream stream(f_name, ios::app);//открыть для добавления
    if(!stream)return -1;//ошибка открытия файла
    stream << pp; //записать новую запись
    return 1;
}
// изенение объектов в потоке
int change_file(const char*f_name, int k,Person pp)
{
    fstream temp("temp", ios::out);//открыть для записи
    fstream stream(f_name,ios::in);//открыть для чтения
    if(!stream)return -1;//ошибка открытия файла
    Person p; 
    int i=0;
    int l=0;
    char x;
    while(stream >> p)
      {
        if (stream.eof()) break;
        i++;
        if(i==k)
          {
            cout << p <<" - is changing... Continue[y/n]?\n";
            cin >> x;
            if(x=='n'||x=='N') break;
            temp<< pp;
            l++;
          }
        else temp<<p;
      }
    stream.close(); temp.close();
    remove(f_name);
    rename("temp", f_name);
    return l;//количество измененных элементов
}