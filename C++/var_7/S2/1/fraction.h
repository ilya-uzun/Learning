#pragma once
class fraction
{
private:
	double first; // коэффициент А
	double second;  // коэффициент В
    double x;
public:
	fraction(double, double, double);
	int Cost();  // вычисление  степени
	int Init();  // инициализация и проверка на корректность
	void Read(); // ввод с клавиатуры
	void Show(); // вывод на экран
    void Set_P(double, double, double);
    double Get_first();
    double Get_second();
    void function(double );
};
