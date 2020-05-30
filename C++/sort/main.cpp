#include <algorithm>//sort
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
 fstream myfile("data.txt");// открываем файл
 vector<double> x(istream_iterator<double>(myfile), {});
 sort(x.begin(), x.end());
 for(const auto& alem: x)
 {
    myfile << alem << " ";
    cout << alem << " "; 
 }
 
 myfile.close();// закрыть файл
}