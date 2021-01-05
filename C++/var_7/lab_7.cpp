
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
//для чисел типа double
double min (double num, ...){
    va_list argList;// j,]объект типа va_list использует макросы va_start, va_arg
    va_start(argList, num);// Макрос va_start() инициализирует ap для последующего использования в va_arg()
    double min = va_arg(argList, double);

    for(size_t i = 1; i < num; ++i)
    {
        double val = va_arg(argList, double); //Макрос va_arg() раскрывается в выражение, 
        min = std::min(val, min); //используется для определения наименьшего числа, переданного ему. Возвращает первый из них, если их больше одного. 
    }
    va_end(argList);
    return min;
}
//для чисел типа int
int min (int num, ...){
    va_list argList;// j,]объект типа va_list использует макросы va_start, va_arg
    va_start(argList, num);// Макрос va_start() инициализирует ap для последующего использования в va_arg()
    int min = va_arg(argList, int);

    for(size_t i = 1; i < num; ++i)
    {
        int val = va_arg(argList, int); //Макрос va_arg() раскрывается в выражение, 
        min = std::min(val, min); //используется для определения наименьшего числа, переданного ему. Возвращает первый из них, если их больше одного. 
    }
    va_end(argList);
    return min;
}

int main(){

	cout << "min из (2, 2, 3, 5, 3): "<< min(5, 2, 2, 3, 5, 3) << endl;
	cout << "min из (10, 7, 4, 4, 4, 5, 6, 7, 8, 10, 2) :"<< min(10, 7, 4, 4, 4, 5, 6, 7, 8, 10, 2) << endl;
	cout << "min из (12.0, 3.0, 2.0, 3.0, 4.0, 5.0, 6.0, 2.0, 8.0, 9.0, 10.0, 12.0, 4.0) :" << min(12.0, 3.0, 2.0, 3.0, 4.0, 5.0, 6.0, 2.0, 8.0, 9.0, 10.0, 12.0, 4.0) << endl;
return 0;}
