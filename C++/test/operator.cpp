#include <iostream>

using namespace std;

class op {
	int x, y, z;
public:
	op(){x = y = z = 0;}
	op(int i, int j, int k){x=i; y=j; z=k;}
	op operator+(op object);
	op operator=(op object);
	void show();
};

// перегрузка оператора +
op op::operator+(op  object)
{
        op temp;
	temp.x = x + object.x; 
	temp.y = y + object.y; 
	temp.z = z + object.z; 
	return temp;
}
// перегрузка оператора =
op op::operator=(op  object)
{
	x = object.x; 
	y = object.y; 
	z = object.z; 
	return *this;
}
// отображаем координаты x,y,z
void op::show()
{
	cout << x << ", ";
	cout << y << ", ";
	cout << z << '\n';
}

int main ()
{
op a(1,2,3), b(10,10,10), c;

a.show();
b.show();

c=a+b; 
c.show();

c=a+b+c; 
c.show();

c=b=a; //демонстрация множественного присваивания

c.show();
b.show();

return 0; 
}
