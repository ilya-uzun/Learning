#include <iostream>

using namespace std;


int main ()
{
  int n = 0;
  cout << "Enter :" << endl;
  cin >> n;

  long double an = 0.1;
  unsigned long long nn;
  for (int i = 0 ; i < n; i++)
  {
    an = an + an;
    nn = an;
    cout << "№ - " << i << " an - " << nn / 1000 <<" met " << nn / 1000000 << " km " << (nn / 1000) / 149597870700 <<" a.e" << endl;

  }; 
return 0;
}
