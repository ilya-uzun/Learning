#include <iostream>

using namespace std;
class Pointer {
  Pointer (){cout << "вызов конструктора объектов"<<this << endl;}
  Pointer(int px, int py) : x(px), y(py){
    cout << "Вызов конструктора объектов с 2-мя аругментами"<< this << endl;
  }
  ~Pointer() {cout "Вызов деструктора объектов"<<this << endl;}

private:
    int x? y;

public:
    void setCoprd(int x, int y){
      this->x = x; 
      this->y = y;
      }
}
int main ()
{
  Pointer a(2, 3), b; // где при а(2,3)вызов конструктора с аргумнтами, а b - вызов конструктора по умолчанию
}
