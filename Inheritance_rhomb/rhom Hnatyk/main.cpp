#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Car {
protected:
    double engineVolume;
    string name;
    string brand;
public:
    Car(double volume, const string& carName, const string& carBrand)
        : engineVolume(volume), name(carName), brand(carBrand) {}
    
    void printDetails(ostream& output) const {
        output << "Car: " << name << ", Brand: " << brand << ", Engine Volume: " << engineVolume;
    }
    
    double getEngineVolume() const {
        return engineVolume;
    }
    
    string getBrand() const {
        return brand;
    }
};

class GasolineCar : virtual public Car {
protected:
    double tankVolume;
public:
    GasolineCar(double volume, const string& carName, const string& carBrand, double tank)
        : Car(volume, carName, carBrand), tankVolume(tank) {}
    
    void printDetails(ostream& output) const {
        Car::printDetails(output);
        output << ", Tank Volume: " << tankVolume;
    }
};

class ElectricCar : virtual public Car {
protected:
    double maxDistance;
    double chargingTime;
public:
    ElectricCar(double volume, const string& carName, const string& carBrand, double distance, double chargeTime)
        : Car(volume, carName, carBrand), maxDistance(distance), chargingTime(chargeTime) {}
    
    void printDetails(ostream& output) const {
        Car::printDetails(output);
        output << ", Max Distance: " << maxDistance << ", Charging Time: " << chargingTime;
    }
};

class HybridCar : public GasolineCar, public ElectricCar {
public:
    HybridCar(double volume, const string& carName, const string& carBrand, double tank, double distance, double chargeTime)
        : Car(volume, carName, carBrand), GasolineCar(volume, carName, carBrand, tank), ElectricCar(volume, carName, carBrand, distance, chargeTime) {}
    
    void printDetails(ostream& output) const {
        Car::printDetails(output);
        output << ", Tank Volume: " << tankVolume << ", Max Distance: " << maxDistance << ", Charging Time: " << chargingTime;
    }
};

bool compareCars(const Car* car1, const Car* car2) {
    if (car1->getEngineVolume() == car2->getEngineVolume())
        return car1->getBrand() < car2->getBrand();
    else
        return car1->getEngineVolume() < car2->getEngineVolume();
}

int main() {
    vector<Car*> cars;
    
    // Додавання даних про автомобілі
    cars.push_back(new GasolineCar(2.0, "GasolineCar1", "BrandA", 50.0));
    cars.push_back(new ElectricCar(0.0, "ElectricCar1", "BrandB", 200.0, 4.0));
    cars.push_back(new HybridCar(1.8, "HybridCar1", "BrandC", 40.0, 150.0, 3.0));
    
    // Сортування автомобілів за об'ємом двигуна, а потім за маркою
    sort(cars.begin(), cars.end(), compareCars);
    
    // Знаходження марки, яка містить авто всіх трьох типів
    vector<string> allTypes = {"GasolineCar", "ElectricCar", "HybridCar"};
    for (const string& type : allTypes) {
        bool hasType = false;
        for (const Car* car : cars) {
            if (car->getBrand() == type) {
                hasType = true;
                break;
            }
        }
        if (!hasType) {
            cout << "Марка, яка містить авто всіх трьох типів: " << type << endl;
            break;
        }
    }
    
    // Виведення даних про автомобілі у файл
    ofstream outputFile("cars.txt");
    if (outputFile.is_open()) {
        for (const Car* car : cars) {
            car->printDetails(outputFile);
            outputFile << endl;
        }
        outputFile.close();
        cout << "Дані про автомобілі були записані у файл cars.txt" << endl;
    } else {
        cout << "Помилка при відкритті файлу для запису" << endl;
    }
    
   
    
    return 0;
}

