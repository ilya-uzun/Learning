class fraction
{
private:
	double first; // коэффициент А
	double second;  // коэффициент В
    double x;
public:
	fraction(){first = second = x = 0;}
	double Init();  // инициализация и проверка на корректность
	void Read(); // ввод с клавиатуры
	void Show(); // вывод на экран
    double function(double);
};
