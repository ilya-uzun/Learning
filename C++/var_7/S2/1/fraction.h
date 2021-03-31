#pragma once
class fraction
{
private:
	double first; // коэффициент А
	double second;  // коэффициент В
public:
	
	int Cost();  // вычисление  степени
	int Init();  // инициализация и проверка на корректность
	void Read(); // ввод с клавиатуры
	void Show(); // вывод на экран
	void function(double);
};
