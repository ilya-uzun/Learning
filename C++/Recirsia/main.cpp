#include<iostream>

using namespace std;

void  F (int n)
{
    cout << n;
    if(n >= 3)
    {
        F(n / 2);
        F(n - 1);
    }
}

int main()
{
    int a;
    cout << "Imput - a  "<<endl;
    cin>>a;
    F(a);
};