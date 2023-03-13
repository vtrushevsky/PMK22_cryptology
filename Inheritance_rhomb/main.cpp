#include <iostream>
#include <Windows.h>
#include <istream>
#include <fstream>

using namespace std;

class Car
{
protected:
	float motor_V;
	string name_car;
	string model_car;
public:

	Car() : motor_V(0), name_car(""), model_car("") {}
	Car(float a, string b, string c) : motor_V(a), name_car(b), model_car(c) {}

	virtual void print(ostream& os)const
	{
		os << " Назва "<<this->name_car << " Модель " << this->model_car << " Обєм Двигуна" << this->motor_V;
	}

	bool operator<(const Car& a)
	{
		return this->motor_V < a.motor_V;
	}
	bool comparison_model(const Car& a)
	{
		return this->model_car < a.model_car;
	}
};

class Benz_car : virtual public Car
{
protected:
	float bak;
public:

	Benz_car() : bak(0) {}
	Benz_car(float a, float s, string b, string c) :bak(a) 
	{
		this->motor_V = s;
		this->name_car = b;
		this->model_car = c;
	}

	void print(ostream& os) const override
	{
		Car::print(os);
		os << " Об'єм баку " << this->bak;
	}
};

class Elec_car : virtual public Car
{
protected:
	float s;
	float t_zar;
public:

	Elec_car(): s(0),t_zar(0) {}
	Elec_car( float s, string b, string c,float S,float t) : s(S),t_zar(t)
	{
		this->motor_V = s;
		this->name_car = b;
		this->model_car = c;
	}

	void print(ostream& os) const override
	{
		Car::print(os);
		os << " Даліність ходу на електро моторі " << this->s << " Час зарядки " << this->t_zar;
	}
};

class Comb_car : public Benz_car, public Elec_car
{
protected:
	float probig;
public:

	Comb_car(): probig(0) {}
	Comb_car(float a, float s, string b, string c, float S, float t, float p) : probig(p)
	{
		this->bak = a;
		this->motor_V = s;
		this->name_car = b;
		this->model_car = c;
		this->s = S;
		this->t_zar = t;
	}

	void print(ostream& os) const override
	{
		Benz_car::print(os);
		os << " Даліність ходу на електро моторі " << this->s << " Час зарядки " << this->t_zar;
	}
};

ostream& operator <<(ostream& os, const Car& a)
{
	a.print(os);
	return os;
}

size_t Partition(Car arr[], size_t low, size_t high) {
	Car pivot = arr[high];
	size_t i = (low - 1);
	for (size_t j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			Car temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	Car temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

void QuickSort(Car arr[], size_t low, size_t high) {
	if (low < high) {
		size_t pi = Partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

size_t Partition1(Car arr[], size_t low, size_t high) {
	Car pivot = arr[high];
	size_t i = (low - 1);
	for (size_t j = low; j <= high - 1; j++) {
		if (arr[j].comparison_model(pivot)) {
			i++;
			Car temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	Car temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

void QuickSort1(Car arr[], size_t low, size_t high) {
	if (low < high) {
		size_t pi = Partition1(arr, low, high);
		QuickSort1(arr, low, pi - 1);
		QuickSort1(arr, pi + 1, high);
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Benz_car a1(40.5,1.6,"Skoda","Octavia");
	Benz_car a2(45, 2.0, "Skoda", "Kodiaq");
	Elec_car a3(0,"Tesla","Model S",400,5.5);
	Elec_car a4(0, "Tesla", "Plaid", 500, 6);
	Comb_car a5(45, 1.8, "Toyota", "Prius", 25, 1.5, 950);
	Comb_car a6(40, 1.5, "Honda", "Insight", 5, 1.5, 900);
	Benz_car a7(50,3.0,"Porsche","911");

	Car** car = new Car*[7];

	car[0] = &a1;
	car[1] = &a2;
	car[2] = &a3;
	car[3] = &a5;
	car[4] = &a4;
	car[5] = &a7;
	car[6] = &a6;

	ifstream f("Car.txt");
	Car* array = new Car[7];
    size_t i = 0;
	while (!f.eof() && i < 7)
	{
		f >> array[i];
		i++;
	}
	f.close();

	QuickSort(*car, 0, 7);

	for (size_t i = 0; i < 7; i++)
		cout << *car[i] << endl;

	QuickSort1(*car, 0, 7);

	for (size_t i = 0; i < 7; i++)
		cout << *car[i] << endl;

	return 0;
}