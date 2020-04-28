#include <iostream>
using namespace std;
class Base
{
public:
    virtual ~Base()
    {
      cout<< "Hello form ~Base()" << endl;
    }
};
class Derived : public Base
{
public:
   virtual ~Derived()
   {
   // здась можно поставить очистку ресурсов
    cout << "Hello form ~Derived()" << endl;
   }
}
 
int main ()
{
 Base *obj = new Derived();
 delete obj;
}