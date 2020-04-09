#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Объявляем функцию
double f(const double& x)
{
	double fx = cos(x / 2) - 2 * sin(x / 3) + x;
  return fx;
}
// перемменная от функции
double fder1(const double& x)
{
	double fder = 1 - sin(x / 2) / 2 - 2 * cos(x / 3) / 3;
	return fder;
}

double fder2(const double& x)
{
	double fder = 2 * sin(x / 3) / 9 - cos(x / 2) / 4;
	return fder;
}

double Newton(double a, double b, double e, int* n1)
{
	double x = 0;
	if (f(a) * fder2(a) > 0) x = a;
	else x = b;

	while (abs(f(x) / fder1(x)) >= e)
  {
		x = x - (f(x) / fder1(x));
		(*n1)++;
  }
	return x;
}
// М половинчатого деления
 double Divison(double a, double b,  double e, int* n)
 {
	 double x = (a + b) / 2;

	 while (abs(a - b) >= e)
   {
		 if (f(x) * f(a) < 0) b = x;
		 else a = x;
		 x = (a + b) / 2;
		 (*n)++;
	  }
  return x;
  }

   double Iteration(double a, double b, double e, int* n2)
   {
  	 double x0 = (a + b) / 2;
  	 double xn = 2 * sin(x0 / 3) - cos(x0 / 2);

  	 while (abs(x0 - xn) >= e)
     {
  		 x0 = xn;
  		 xn = 2 * sin(x0 / 3) - cos(x0 / 2);
  		 (*n2)++;
  	 }
  	 return xn;
    }

  int main(){
  	setlocale(LC_CTYPE, "Russian");

  	const double a = -3.5, b = 2.5, e = 0.0001;
  	int n = 0;
  	int n1 = 0;
  	int n2 = 0;
  	cout << "Дано уравнение: f(x) = cos(x/2) - sin(x) + x" << "\n\n";
  	cout << "Методом половинного деления..."<< endl<< fixed << setprecision(6) << "x = "<< Divison(a, b, e, &n) << "\n\n";
  	cout << "Число N - " << n<< endl;
  	cout << "Методом Ньютона..." << endl << fixed << setprecision(6) << "x = "<< Newton(a, b, e, &n1) << "\n\n";
  	cout << "Число N - " << n1 << endl;
  	cout << "Метод простых итераций..."<< endl<< fixed << setprecision(6) << "x = "<< Iteration(a, b, e, &n2) << "\n\n";
  	cout << "Число N - " << n2 << endl;
  	system("pause");
  	return 0;
  }
