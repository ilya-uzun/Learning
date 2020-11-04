#include <iostream>

using namespace std;

int number_1(int n, int m)
{
  return (m - (++n)); // первым выполняется ++n или (+1 + n)
}

int number_2(int n, int m)
{
  --n;
  ++m;
  if (n > m) return true;
  else return false;
}

bool number_3(int n, int m)
{
  --n;
  ++m;
  if (n < m) return true;
  else return false;
}

int main ()
{
int n, m;
cout << "Enter n : " << endl; 
cin >> n;
cout << "Enter m : " << endl;
cin >> m; // вводим m
cout << "m - (++n) = " << number_1(n, m) << endl;
cout << "(++m > --m)  = " << number_2(n, m) << endl;
cout << "(--n < ++m) = " << number_3(n, m) << endl;
// 0 , 1  = равнозначны false и true
}
