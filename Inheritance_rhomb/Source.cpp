#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Car {
protected:
	float engine_capacity;
	string name;
	string firm;
public:
	Car() {
		engine_capacity = 0;
		name = "no data";
		firm = "no data";
	}
	Car(string name, string firm, float engine_capacity) {
		this->name = name;
		this->firm = firm;
		this->engine_capacity = engine_capacity;
	}
	virtual void output(ofstream& os)const
	{
		os << "Car name:" << this->name << endl;
		os << "Brand:" << this->firm << endl;
		os << "Engine volume:" << this->engine_capacity << endl;
	}
	float GetEngine_capacity() {
		return engine_capacity;
	}
	string GetFirm() {
		return firm;
	}
	virtual string GetTipe() {
	}
	
};
class GasCar: public virtual Car {
protected:
	int tank_volume;
	float gas_consumption;
public:
	GasCar() {
		tank_volume = 0;
		gas_consumption = 0;
	}
	GasCar(string name, string firm, float engine_capacity, int tank_volume, float gas_consumption):Car(name, firm, engine_capacity){
		this->tank_volume = tank_volume;
		this->gas_consumption = gas_consumption;
	}
	void output(ofstream& os) const  override{
		os << "name: " << name << endl;
		os << "firm: " << firm << endl;
		os << "engine capacity: " << engine_capacity << endl;
		os << "tank volume: " << tank_volume << endl;
		os << "gas consumption: " << gas_consumption << endl;
		os << "______________________________________________ " << endl;
	}
	 string GetTipe() override {
		 return "GasCar";
	 }
};
class ElectroCar : public virtual Car {
protected:
	int charging_time;
	int driving_time;
public:
	ElectroCar() {
		charging_time = 0;
		driving_time = 0;
	}
	ElectroCar(string name, string firm, int charging_time, int driving_time) :Car(name, firm, 0.0) {
		this->charging_time = charging_time;
		this->driving_time = driving_time;
	}
	void output(ofstream& os) const  override {
		os << "name: " << name << endl;
		os << "firm: " << firm << endl;
		os << "charging time: " << charging_time << endl;
		os << "driving time: " << driving_time << endl;
		os << "______________________________________________ " << endl;
	}
	string GetTipe() override {
		return "ElectroCar";
	}
};
class HybridCar : public GasCar, public ElectroCar {
public:
	HybridCar(string name, string firm, float engine_capacity, int tank_volume, float gas_consumption, int charging_time, int driving_time) :Car(name, firm, engine_capacity) {
		this->name = name;
		this->firm = firm;
		this->engine_capacity = engine_capacity;
		this->tank_volume = tank_volume;
		this->gas_consumption = gas_consumption;
		this->charging_time = charging_time;
		this->driving_time = driving_time;
	}
	void output(ofstream& os) const  override {
		os << "name: " << name << endl;
		os << "firm: " << firm << endl;
		os << "engine capacity: " << engine_capacity << endl;
		os << "tank volume: " << tank_volume << endl;
		os << "gas consumption: " << gas_consumption << endl;
		os << "charging time: " << charging_time << endl;
		os << "driving time: " << driving_time << endl;
		os << "______________________________________________ "  << endl;
	}
	string GetTipe() override {
		return "HybridCar";
	}
	
 };
void sortByEngine(Car* cars[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (cars[j]->GetEngine_capacity() > cars[j + 1]->GetEngine_capacity()) {
				Car* temp = cars[j];
				cars[j] = cars[j + 1];
				cars[j + 1] = temp;
			}
		}
	}
}
int main() {
	Car* cars[6];
	cars[0] = new HybridCar("Camry", "Toyota", 2, 60, 9, 20, 3);
	cars[1] = new ElectroCar("Model x", "Tesla", 20, 6);
	cars[2] = new GasCar("Lanos", "Daewoo", 1.6, 48, 8);
	cars[3] = new GasCar("x5", "BMW", 4.4, 75, 11);
	cars[4] = new GasCar("Corola", "Toyota", 2.5, 55, 9);
	cars[5] = new ElectroCar("RAV 4", "Toyota", 25, 5);
	ofstream fout;
	fout.open("Cars.txt"/*, ofstream::app*/);
	for (int i=0; i<6 ; i++){ cars[i]->output(fout); }
	sortByEngine(cars, 6);
	fout.close();
	string Toyota[3]{ "","","" };
	for (int i = 0; i < 6; i++) {
		if (cars[i]->GetFirm() == "Toyota"&& cars[i]->GetTipe()=="ElectroCar") {
			Toyota[0] = "ElectroCar";
		}
		else if (cars[i]->GetFirm() == "Toyota" && cars[i]->GetTipe() == "GasCar") {
			Toyota[1] = "GasCar";
		}
		else if (cars[i]->GetFirm() == "Toyota" && cars[i]->GetTipe() == "HybridCar") {
			Toyota[2] = "HybridCar";
		}
	}
	//if(Toyota[0] == "ElectroCar" && Toyota[1] == "GasCar" && Toyota[2] == "HybridCar"){ do something}
	delete[]cars;
	return 0;
}