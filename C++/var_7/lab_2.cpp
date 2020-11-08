#include <iostream>
#include <iomanip>

using namespace std;


int main ()
{
  
  double eps = 0.001; // погрешность, с которой будет вычисляться значение ряда
  double an, sum; // текущий an и текущая сумма ряда
  double n; // текущий номер
 
  an = 1;
  sum = 0;
  n = 0;
  // значение ряда будем вычислять в цикле while
  while (an > eps)
  {
  n = n + 1.0;
	an = 1 / ((3*n-2)*(3*n+1));
	sum = sum + an;
  }
  cout << sum << " - sum " << endl; // выводим сумму
  cout << fixed << setprecision(10) << an <<" - an "; // fixedпе

}
