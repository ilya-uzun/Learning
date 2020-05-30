#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
 fstream myfile("data.txt");// открывае файл
 vector<double> x(istream_iterator<double>(myfile), {});
 sort(x.begin(), x.end());
 for(const auto& alem: x)
 cout << alem << " ";
}