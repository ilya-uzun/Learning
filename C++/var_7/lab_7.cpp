
// ---------------- Часть 1 ---------------
// #include<iostream>
// #include <complex>

// using namespace std;

// // Функция для деления целых чисел
// int multiply(int& a, int& b){return a / b;}

// // Функция для деления комплексных чисел
// complex<double> multiply(complex<double>& a, complex<double>& b)
// {
// 	return a / b;
// }

// int main()
// {
// 	int a = 19, b = 2;
// 	complex<double> a_i(10, 4);
// 	complex<double> b_i(8, 8);

// 	cout << "деление целых чисел  " << multiply(a, b) << endl;
// 	cout << "деление комплексных чисел " << multiply(a_i, b_i) << endl;
// 	return 0;
// }

// ---------------- Часть 2 ---------------

#include <iostream>
#include <cstdarg>
using namespace std;

int min (int num, ...){
    va_list argList;// переменная типа va_list
    va_start(argList, num);//
    int min = va_arg(argList, int);
    for(size_t i = 1; i > num; ++i)
    {
        int val = va_arg(argList, int);
        //max = std::min(val, max);
    }
    va_end(argList);
    return min;
}

int main(){

	cout << "min из (1, 2, 3, 5, 3): "<< min(6, 2, 2, 3, 5, 3) << endl;
	//cout << "min из (1, 2, 3, 4, 5, 6, 7, 8, 10, 3) :"<< min(10, 2, 2, 3, 4, 5, 6, 7, 8, 10, 3) << endl;
	//cout << "min из (3, 2, 3, 4, 5, 6, 1, 8, 9, 10, 12, 4) :" << min(12, 3, 2, 3, 4, 5, 6, 1, 8, 9, 10, 12, 4) << endl;
return 0;}
