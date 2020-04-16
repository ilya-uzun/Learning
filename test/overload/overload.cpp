#include "overload.h"

  Overload::Overload(int , int )
  {
    first = 1;
    second = 1;
  };
  int  Overload::get_first(){return first;};
  void Overload::set_first(int value){ first = value;};
  int  Overload::get_second(){return second;};
  void Overload::set_second(int value){second = value;};

  std::istream &operator >> (std::istream &in, Overload &t)
  {
    std::cout << "Введите первое число - " ;
    in >> t.first;
    std::cout << "Введите второе число - ";
    in >> t.second;
    return in;
  };

  std::ostream &operator << (std::ostream &out, const Overload &t)
  {
    return (out << "first - "<< t.first << " second - " << t.second);
  };
