#include <iostream>

using namespace std;

class Point{
public:
  Point(const Point& other){
      cout <<"Вызоа конструктора копирования"<<this << endl;
      this->x = other.x;
      this->y = other.y;
  }
  Point(){cout << "вызов конструктора объектов"<<this << endl;}
  Point(int px, int py) : x(px), y(py){
    cout << "Вызов конструктора объектов с 2-мя аругментами"<< this << endl;
  }
  ~Point() {cout << "Вызов деструктора объектов"<<this << endl;}

private:
    int x, y;

public:
    void setCoprd(int x, int y){
      this->x = x; 
      this->y = y;
      }
};

void foo(Point pt){
    cout << "Вывод функции foo" << endl;
}


int main ()
{
  Point a(1,2), b; // где при а(2,3)вызов конструктора с аргумнтами, а b - вызов конструктора по умолчанию
  foo(a);
};
