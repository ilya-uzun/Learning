
// ---------------- Часть 1 ---------------
#include<iostream>
#include <complex>

using namespace std;

int multiply(int& a, int& b){return a * b;}

complex<double> multiply(complex<double>& a, complex<double>& b)
{
	return a * b;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int a = 10, b = 17;
	complex<double> a_i(15, 3);
	complex<double> b_i(7, 7);

	cout << "умножения целых чисел  " << multiply(a, b)<< endl;
	cout << "умножения комплексных чисел "<< multiply(a_i, b_i) << endl;
	return 0;
}

// ---------------- Часть 2 ---------------

#include<iostream>
#include <cstdarg>
using namespace std;

int sum(int num, ...){
	int* a = &num;
	int sum = 0;
	for (; num != 0; num--){
		int b = *a;
		b--;
		sum += (*a) * b;}
	return sum;}

int main(){
	setlocale(LC_CTYPE, "Russian");
	cout << "S=a1*a2+a2*a3+a3*a4+. . . . . : "<< sum(5, 1, 2, 3, 4, 5) <<endl;
	cout << "S=a1*a2+a2*a3+a3*a4+. . . .+a9*a10 :"<< sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
	cout << "S=a1*a2+a2*a3+a3*a4+. . . .+a11*a12 :" << sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;
return 0;}
