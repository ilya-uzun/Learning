#pragma once
class fraction
{
private:
	int first;
	int second;
public:
	void Read(); // метод для чтения значений полей
	int Cost();  // вычисление  степени
	int Init();  // инициализация и проверка на корректность
	void Show(); // метод для вызова значений полей
};
