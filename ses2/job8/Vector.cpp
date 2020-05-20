#include "Vector.h"

//деструктор
Vector::~Vector(void)
{
	if(beg!=0) delete [] beg; // beg указатель на первый элемент
	beg=0;
}
//конструктор с параметрами
Vector::Vector(int n)
{
	beg = new Object*[n];
	cur = 0;
	size = n;
}
//добавление объекта, на который указывает указатель p в вектор
void Vector::Add()
{
	Object *p;
//выбор из объектов двух возможных классов
	std::cout <<" 1.Person " << std::endl;
	std::cout <<" 2.Abiturient " << std::endl;
	int y;
	std::cin >> y;
	if (y==1)//добавление объекта класса Car
	{
		Person *a = new Person;
		a -> Input();//ввод значений атрибутов
		p = a;
		if(cur < size)
		{
			beg[cur]=p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2) //добавление объекта класса Lorry
		{
			Abiturient *b = new Abiturient;
			b -> Input();
			p = b;
				if(cur<size)
				{
					beg[cur]=p;
					cur++;
				}
		}
	else return;
}//void Vector::Add()
//просмотр вектора
void Vector::Show()
{
	if (cur == 0) std::cout << " Empty " << std::endl;// Пустой
	Object **p = beg;//указатель на указатель типа Object
	for(int i=0; i < cur; i++)
	{
		(*p) -> Show();//вызов метода Show() (позднее связывание)
		p++;//передвигаем указатель на следующий объект
	}
}
//операция, которая возвращает размер вектора
int Vector::operator ()()
 {
	return cur;
 }
 //средний возраст 
void Vector::AverageAge()
 {
	int sum;
	Object *p2; 
	Abiturient *a2 = new Abiturient;
	a2 -> Input();
	p2 = a2;
	if (cur == 0) std::cout << " Empty average age " << std::endl;// Пустой
	for(int i = 0; i < cur; i++)
	{
		sum += a2->Get_age();
		a2++; //передвигаем указатель на следующий объект
	}
	sum /= size;
	std::cout << " Average Age = " << sum << std::endl;	
 }
//удаление элемента из вектора, память не освобождается!
void Vector::Del()
 {
	if(cur == 0) return;//пустой
 	cur--;
 }