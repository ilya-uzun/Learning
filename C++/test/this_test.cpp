#include <iostream>
using namespace std;

class cl {
	int i;
     public:
	void load_i(int val){this->i= val;}
	//this->i= val эквивалент i= var
	int get_i(){return this->i;}
	// эквивалент return i
};

int main()
{
	cl x;
	x.load_i (100);
	cout<<x.get_i();
	return 0;
}
