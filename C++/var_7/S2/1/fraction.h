#pragma once
class fraction
{
private:
	double first; // коэффициент А
	double second;  // коэффициент В
public:
	void Read(); // метод для чтения значений полей
	int Cost();  // вычисление  степени
	int Init();  // инициализация и проверка на корректность
	void Show(); // метод для вызова значений полей
};
