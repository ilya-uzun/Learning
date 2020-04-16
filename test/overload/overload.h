
#include <iostream>

using namespace std;
class Overload
  {
  	int first;
  	int second;


  public:
    Overload(){};
    Overload(int, int);
    ~Overload(){};
    // методы для ввода/вывода через get и set
    int  get_first();
    void set_first(int value);
    int  get_second();
    void set_second(int value);
    // методы для ввода/вывода через перегрузку функции
    friend std::istream &operator >> (std::istream &in, Overload &t);
    friend std::ostream &operator << (std::ostream &out, const Overload &t);
  };
