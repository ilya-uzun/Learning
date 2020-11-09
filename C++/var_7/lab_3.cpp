#include <iostream>
#include <cmath>
#include <iomanip>// содержит функии setprecision, fixed

using namespace std;

int main()
{
    int n = 10;
    double e = 0.0001;
    double y=0, SM=0, SE=0, a=0, b=0;

    cout<< setw(40) << "Function evaluation" << endl;

    for(double x = 0.1; x <= 1; x += 0.09)
    {
        a = x;  //т.к. a(0) = x
        SM = a;

        for(int i = 0; i< n-1; i++)
        {
          // надо продиференцировать функцию
        a *= ((-1)*x*x / ((2*i + 2) * (2*i + 3)));
        SM += a;
        }

        b = x;
        SE = b;
        y = cos(x);

        for(int j = 0; abs(y - SE) > e; j++)
        {
        b *= ((-1)*x*x / ((2*j + 2) * (2*j + 3)));
        SE += b;
        }

        cout<< "X = " << fixed << setprecision(2) << x;
        cout<< setw(10) << fixed << setprecision(7) <<"SN = "<< SM;
        cout<< setw(10) << fixed << setprecision(7) <<"SE = " << SE;
        cout<< setw(10) << fixed << setprecision(7) <<"Y = " << y << endl;
    }
    return 0;
  }
