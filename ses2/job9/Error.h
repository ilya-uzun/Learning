#pragma once
#include <string>
#include <iostream>
using namespace std;
//базовый класс
class Error
{
public:
    virtual void what(){};
};
// ошибка в индексе вектора
class IndexError : public Error 
{
protected:
    string msg;
public:
    IndexError(){msg="Index Error\n";}
virtual void what(){cout<<msg;}
};
//ошибка в размере вектора
class SizeError:public Error 
{
protected:
string msg;
public:
SizeError(){msg="size error\n";}
virtual void what(){cout<<msg;}
};
//превышение максимального размера
class MaxSizeError:public SizeError 
{
protected:
    string msg_;
public:
    MaxSizeError(){SizeError();msg_="size>MAXSIZE\n";}
virtual void what(){cout<<msg<<msg_;}
};
//удаление из пустого вектора
class EmptySizeError:public SizeError 
{
protected:
    string msg_;
public:
    EmptySizeError(){SizeError();msg_="Vector is empty\n";}
virtual void what(){cout<<msg<<msg_;}
};
//индекс меньше нуля
class IndexError1:public IndexError 
{
protected:
    string msg_;
public:
    IndexError1(){IndexError();msg_="index < 0\n";}
virtual void what(){cout << msg << msg_;}
};
//индекс больше текущего размера вектора
class IndexError2:public IndexError 
{
protected:
    string msg_;
public:
    IndexError2(){IndexError();msg_="index > size\n";}
virtual void what(){cout<<msg<<msg_;}
};