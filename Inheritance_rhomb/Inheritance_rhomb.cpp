#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class Car {
protected:
    int engineCapacity;
    string name;
    string brand;
public:
    Car(int engineCapacity, string name, string brand) {
        this->engineCapacity = engineCapacity;
        this->name = name;
        this->brand = brand;
    }
    virtual void printData(ostream& os) {
        os << "Brand: " << brand << ", Name: " << name << ", Engine Capacity: " << engineCapacity;
    }
    string getBrand() {
        return brand;
    }
    string getName() {
        return name;
    }
    int getEngineCapacity() {
        return engineCapacity;
    }
};

class GasolineCar : virtual public Car {
protected:
    int tankCapacity;
public:
    GasolineCar(int engineCapacity, string name, string brand, int tankCapacity) : Car(engineCapacity, name, brand) {
        this->tankCapacity = tankCapacity;
    }
    virtual void printData(ostream& os) override {
        Car::printData(os);
        os << ", Tank Capacity: " << tankCapacity;
    }
};

class ElectricCar : virtual public Car {
protected:
    int maxMileage;
    int chargingTime;
public:
    ElectricCar(int engineCapacity, string name, string brand, int maxMileage, int chargingTime) : Car(engineCapacity, name, brand) {
        this->maxMileage = maxMileage;
        this->chargingTime = chargingTime;
    }
    virtual void printData(ostream& os) override {
        Car::printData(os);
        os << ", Max Mileage: " << maxMileage << ", Charging Time: " << chargingTime;
    }
};

class HybridCar : public GasolineCar, public ElectricCar {
public:
    HybridCar(int engineCapacity, string name, string brand, int tankCapacity, int maxMileage, int chargingTime) : Car(engineCapacity, name, brand), GasolineCar(engineCapacity, name, brand, tankCapacity), ElectricCar(engineCapacity, name, brand, maxMileage, chargingTime) {
    }
    virtual void printData(ostream& os) override {
        GasolineCar::printData(os);
        os << ", ";
        ElectricCar::printData(os);
        os << ", Mileage on Gasoline: " << tankCapacity * 10 << ", Mileage on Electricity: " << maxMileage;
    }
};

bool compareCars(Car* c1, Car* c2) {
    if (c1->getEngineCapacity() == c2->getEngineCapacity()) {
        return c1->getBrand() < c2->getBrand();
    }
    return c1->getEngineCapacity() < c2->getEngineCapacity();
}

    int main() {
        Car* cars[9] = {
            new GasolineCar(3234, "Toyota Land Cruiser 200", "Toyota", 50),
            new ElectricCar(4566, "Audi e-tron", "Audi", 230, 6),
            new HybridCar(1235, "Toyota Camry Hybrid", "Toyota", 20, 530, 4),
            new GasolineCar(6333, "Mitsubishi Pajero Wagon", "Mitsubishi", 30),
            new ElectricCar(5000, "Toyota C-HR", "Toyota", 540, 8),
            new HybridCar(9234, "Hyundai Sonata Hybrid", "Hyundai", 50, 170, 11),
            new GasolineCar(3000, "Ford Focus", "Ford", 45),
            new ElectricCar(4500, "Chevrolet Spark EV", "Chevrolet", 430, 17),
            new HybridCar(2500, "Honda Insight", "Honda", 60, 180, 4),
        };

        sort(cars, cars + 9, compareCars);

        ofstream outFile("cars.txt");
        for (int i = 0; i < 9; i++) {
            outFile << cars[i]->getEngineCapacity() << " ";
            outFile << cars[i]->getName() << " ";
            outFile << cars[i]->getBrand() << endl;
        }
        outFile.close();

        string brands[] = { "Toyota", "Audi", "Mitsubishi", "Hyundai", "Ford", "Chevrolet", "Honda" };
        for (int i = 0; i < 3; i++) {
            bool hasGasolineCar = false;
            bool hasElectricCar = false;
            bool hasHybridCar = false;
            for (int j = 0; j < 9; j++) {
                if (cars[j]->getBrand() == brands[i]) {
                    if (dynamic_cast<GasolineCar*>(cars[j])) {
                        hasGasolineCar = true;
                    }
                    if (dynamic_cast<ElectricCar*>(cars[j])) {
                        hasElectricCar = true;
                    }
                    if (dynamic_cast<HybridCar*>(cars[j])) {
                        hasHybridCar = true;
                    }
                }
            }
            if (hasGasolineCar && hasElectricCar && hasHybridCar) {
                cout << brands[i] << " contains cars of all three types." << endl;
                break;
            }
            if (hasGasolineCar && hasElectricCar || hasElectricCar && hasHybridCar || hasHybridCar && hasGasolineCar)
            {
                cout << "Brand, who contains all types of cars is not found." << endl;
            }
        }

        for (int i = 0; i < 9; i++) {
            delete cars[i];
        }

        return 0;
    }
