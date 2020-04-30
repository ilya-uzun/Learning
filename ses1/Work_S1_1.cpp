#include <iostream>
#include <cmath>

using namespace std;

int main()
{
float a = 1000, b = 0.0001;
float c = pow((a + b), 3);
float d = pow(a, 3) + 3*a*a*b;
float e = 3*a*b*b + pow(b, 3);
float f = (c - d) / e;

cout <<"type float: "<< f << endl;

double r = 1000, g = 0.0001;
double h = pow((r + g), 3);
double j = pow(r, 3) + 3*r*r*g;
double k = 3*r*g*g + pow(g, 3);
double dr = (h - j) / k;

cout << "type double:" << dr << endl;

return 0;

}
