#include <iostream>

using namespace std;


class master
{
  public:
	virtual void print()
	{
	  cout << "Первый метод" << endl;
	}
};


class slave : public master
{
  public:
	 void print()
	{
	  cout << "Второй метод" << endl;
	}
};


int main ()
{
	master M;
	slave S;
	master *po = &M;
	po->print();
	master *po1 = &S;
	po1->print();
	return 0;
};
