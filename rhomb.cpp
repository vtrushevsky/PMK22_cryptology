#include <iostream>
#include <fstream>
using namespace std;

class Car
{
protected:
	double engineVolume;
	string name;
	string brand;
public:
	Car() : name(""), engineVolume(0), brand("") {}
	Car(string _name, double _volume, string _brand) : name(_name), engineVolume(_volume), brand(_brand) {}
	const string getName()const { return name; }
	const double getVolume()const { return engineVolume; }

	virtual void print(ostream& os)const
	{
		os << "Car name:" << this->name << endl;
		os << "Brand:" << this->brand << endl;
		os << "Engine volume:" << this->engineVolume << endl;
	}
    const virtual string getCarType() = 0 {}

	void input(istream& is)
	{
		is >> name;
		is >> brand; 
		is >> engineVolume;
	}
	bool operator <(const Car& other) const
	{
		return this->engineVolume < other.engineVolume; 
	}
};
class FuelCar : virtual public Car
{
protected:
	double tankVolume;
public:
	FuelCar() : Car(), tankVolume(0)  {}
	FuelCar(int _maxSpeed, string _name, double _volume, string _brand) : Car(_name, _maxSpeed, _brand), tankVolume(_maxSpeed) {}
	void print(ostream& os) const override
	{
		Car::print(os);
		os << "Tank Volume:" << this->tankVolume << endl;
	}
	void input(istream& is)
	{
		is >> tankVolume;
		is >> name;
		is >> engineVolume;
	}
	const string getCarType()
	{
		return "FuelCar";
	}
};
class ElectroCar : virtual public Car
{
protected:
	int maxSpeed;
	int chargeTime;
public:
	ElectroCar() : Car(), maxSpeed(0), chargeTime(0) {}
	ElectroCar(int _maxSpeed, int _chargeTime, string _name, double _volume, string _brand) : Car(_name, _volume, _brand), maxSpeed(_maxSpeed), chargeTime(_chargeTime) {}
	void print(ostream& os) const override
	{
		Car::print(os);
		os << "Max speed:" << this->maxSpeed << endl;
		os << "Charge time:" << this->chargeTime << endl;
	}
	void input(istream& is)
	{
		Car::input(is);
		is >> maxSpeed;
		is >> chargeTime;
	}
	const string getCarType()
	{
		return "ElectroCar";
	}
};
class CombinedCar : public ElectroCar, public FuelCar
{
private:
	int mileageTypedif;
	
public:
	CombinedCar() : mileageTypedif(0){}
	CombinedCar(int mileageTypedif, int _maxSpeed, int maxHoursOnG, string _name, double _engineVolume, int _chargeTime, string _brand) : Car(_name, _engineVolume, _brand), FuelCar(_maxSpeed, _name, _engineVolume, _brand), ElectroCar(_maxSpeed, _chargeTime, _name, _engineVolume, _brand), mileageTypedif(mileageTypedif) {}
	void print(ostream& os) const override
	{
		ElectroCar::print(os);
		FuelCar::print(os);
		os << "Mileage of Different types:" << this->mileageTypedif << endl;
	}
	void input(istream& is)
	{
		ElectroCar::input(is);
		Car::input(is); 
		FuelCar::input(is);
		is >> this->mileageTypedif;
	}
	const string getCarType()
	{
		return "ElectroFuelCar";
	}
};
ostream& operator <<(ostream& os, const Car& a)
{
	a.print(os);
	return os;
}
void bubbleSort(Car** array, unsigned int size)
{
	bool swapped = true;
	int j = 0;
	while (swapped)
	{
		swapped = false;
		j++;
		for (int i = 0; i < size - j; i++)
		{
			if (array[i] < array[i + 1]) {
				swap(array[i], array[i + 1]);
				swapped = true;
			}
		}
	}
}
int main(){} 