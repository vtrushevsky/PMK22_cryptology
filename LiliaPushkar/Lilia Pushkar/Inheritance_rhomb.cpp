#include <iostream>
#include <fstream>

using namespace std;

class Car
{
protected:
	double engine_capacity;
	string name, mark;

public:
	Car() : engine_capacity(0), name(""), mark("") {}
	Car(double e, string n, string m) : engine_capacity(e), name(n), mark(m) {}

	string getName()const { return name; }
	string getMark()const { return mark; }
	double getEngineCapacity()const { return engine_capacity; }

	virtual void Print(ostream& out)const
	{
		out << this->engine_capacity << endl;
		out << this->name << endl;
		out << this->mark << endl;
	}

	void Input(istream& is)
	{
		is >> engine_capacity;
		is >> name;
		is >> mark;
	}

	Car& operator= (const Car& c)
	{
		engine_capacity = c.engine_capacity;
		name = c.name;
		mark = c.mark;

		return *this;
	}
};

class GasolineCar : virtual public Car
{
protected:
	double tank_volume;

public:
	GasolineCar(): tank_volume(0), Car() {}
	GasolineCar(double t, double e, string n, string m): tank_volume(t), Car(e,n,m){}

	void Print(ostream& out) const override
	{
		Car::Print(out);
		out << "The volume of the gasolie tank: " << this->tank_volume << endl;
	}

	void InputG(istream& is)
	{
		is >> tank_volume;
		is >> engine_capacity;
		is >> name;
		is >> mark;
	}


};

class ElectricCar : virtual public Car
{
protected:
	double charning_time;
	double max_time_mileage;
public:
	ElectricCar(): Car(), charning_time(0), max_time_mileage(0) {}
	ElectricCar(double c, double max, double e, string n, string m): charning_time(c), max_time_mileage(max), Car(e, n, m) {}

	void Print(ostream& out) const override
	{
		Car::Print(out);
		out << "Max time mileage: " << this->max_time_mileage << endl;
		out << "Charning time: " << this-> charning_time << endl;
	}
	void InputE(istream& is)
	{
		is >> charning_time;
		is >> max_time_mileage;
		is >> engine_capacity;
		is >> name;
		is >> mark;
	}
};

class Combined: public GasolineCar, public ElectricCar
{
	double gas_mileage;
	double electric_mileage;
public:
	Combined(): gas_mileage(0), electric_mileage(0){}
	Combined(double c, double max, double e, string n, string m, double t, double gas, double ele): Car(e,n,m), GasolineCar(t,e,n,m), ElectricCar(c,max,e,n,m), gas_mileage(gas), electric_mileage(ele){}

	void Print(ostream& out) const override
	{
		GasolineCar::Print(out);
		ElectricCar::Print(out);
	}

	void InputC(istream& is)
	{
		is >> tank_volume;
		is >> charning_time;
		is >> max_time_mileage;
		is >> gas_mileage;
		is >> electric_mileage;
		is >> engine_capacity;
		is >> name;
		is >> mark;
	}
};

ostream& operator <<(ostream& out, const Car& c)
{
	c.Print(out);
	return out;
}

void BubbleSortEngine(Car *arr, int n)
{
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n -1 - i; j++)
		{
			if (arr[j].getEngineCapacity() > arr[j + 1].getEngineCapacity())
			{
				auto temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void BubbleSortMark(Car* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j].getMark() > arr[j + 1].getMark())
			{
				auto temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int count = 1;
	Car** array = new Car * [4];

	GasolineCar gas(120, 3.5, "Passat", "Volkswagen");
	GasolineCar gas1(110, 3, "A6", "Audi");
	ElectricCar electric(200, 3, 2, "Etron", "Audi");
	Combined combi(280, 4.7, 2, "Q8", "Audi", 100, 200, 30);

	array[0] = &gas;
	array[1] = &gas1;
	array[2] = &electric;
	array[3] = &combi;

	ofstream out("outAll.txt");

	BubbleSortEngine(*array, 4);
	for (int i = 0; i < 4; i++)
	{
		out << array[i];
	}

	BubbleSortMark(*array, 4);
	for (int i = 0; i < 4; i++)
	{
		out << array[i];
	}


	//Запис марки яка повторюється три рази
	for (int i = 0; i < 4; i++)
	{
		if (array[i]->getMark() == array[i + 1]->getMark())
		{
			count++;
		}

		if (count == 3)
		{
			out << "A brand that is repeated 3 times: " << array[i]->getMark();
		}
	} 

	out.close();
	
	return 0;
}
