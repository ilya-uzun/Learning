#include <iostream>
using namespace std;

class cl {

  public:
	cl(){
	  cout << "konstructor cl" << '\n';
	}
    int i;
};

class c2 {

  public:
        c2(){
	  y = 12;
	  cout << "konstructor c2" << '\n';
	}
    int x,y;
};

int main()
{
	cl obj1;
	c2 obj2;
	cout << obj1.i << '\n';
        cout << obj2.x << '\n';
	cout << obj2.y << '\n';
	return 0;
}

