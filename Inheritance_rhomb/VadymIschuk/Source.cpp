#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class Car {
public:
    double engineVolume;
    std::string name;
    std::string brand;

    Car(double engineVolume, const std::string& name, const std::string& brand)
        : engineVolume(engineVolume), name(name), brand(brand) {}
    virtual ~Car() {}
    void printDetails(std::ostream& os) const {
        os << "Name: " << name << std::endl;
        os << "Brand: " << brand << std::endl;
        os << "Engine Volume: " << engineVolume << std::endl;
    }
};

class PetrolCar : virtual public Car {
public:
    double tankCapacity;

    PetrolCar(double engineVolume, const std::string& name, const std::string& brand, double tankCapacity)
        : Car(engineVolume, name, brand), tankCapacity(tankCapacity) {}

    void printDetails(std::ostream& os) const {
        Car::printDetails(os);
        os << "Tank Capacity: " << tankCapacity << std::endl;
    }
};

class ElectricCar : virtual public Car {
public:
    double maxTravelTime;
    double chargingTime;

    ElectricCar(double engineVolume, const std::string& name, const std::string& brand, double maxTravelTime, double chargingTime)
        : Car(engineVolume, name, brand), maxTravelTime(maxTravelTime), chargingTime(chargingTime) {}

    void printDetails(std::ostream& os) const {
        Car::printDetails(os);
        os << "Max Travel Time: " << maxTravelTime << std::endl;
        os << "Charging Time: " << chargingTime << std::endl;
    }
};

class HybridCar : public PetrolCar, public ElectricCar {
public:
    HybridCar(double engineVolume, const std::string& name, const std::string& brand, double tankCapacity, double maxTravelTime, double chargingTime)
        : Car(engineVolume, name, brand), PetrolCar(engineVolume, name, brand, tankCapacity), ElectricCar(engineVolume, name, brand, maxTravelTime, chargingTime) {}
};
int main() {
    std::vector<Car*> cars;

    cars.push_back(new PetrolCar(2.0, "Car A", "Brand A", 60.0));
    cars.push_back(new ElectricCar(0.0, "Car B", "Brand B", 300, 120));
    cars.push_back(new HybridCar(1.8, "Car C", "Brand C", 50.0, 200, 90));
    cars.push_back(new PetrolCar(1.6, "Car D", "Brand A", 55.0));
    cars.push_back(new ElectricCar(0.0, "Car E", "Brand B", 250, 100));
    cars.push_back(new HybridCar(1.5, "Car F", "Brand C", 45.0, 180, 80));

    std::ofstream outFile("car_details.txt");
    if (outFile.is_open()) {
        for (const auto& car : cars) {
            car->printDetails(outFile);
            outFile << std::endl;
        }
        outFile.close();
        std::cout << "Car details written to file: car_details.txt" << std::endl;
    }
    else {
        std::cout << "Unable to open the file for writing." << std::endl;
    }

    std::sort(cars.begin(), cars.end(), [](const Car* car1, const Car* car2) {
        if (car1->engineVolume != car2->engineVolume) {
            return car1->engineVolume < car2->engineVolume;
        }
        else {
            return car1->brand < car2->brand;
        }
        });

    std::cout << "Sorted Car Details:" << std::endl;
    for (const auto& car : cars) {
        car->printDetails(std::cout);
        std::cout << std::endl;
    }

    // Find the brand that has cars of all three types
    std::cout << "Brand with cars of all three types: ";
    bool foundBrand = false;
    for (const auto& car : cars) {
        if (dynamic_cast<PetrolCar*>(car) && dynamic_cast<ElectricCar*>(car) && dynamic_cast<HybridCar*>(car)) {
            std::cout << car->brand << std::endl;
            foundBrand = true;
            break;
        }
    }
    if (!foundBrand) {
        std::cout << "No brand with cars of all three types found." << std::endl;
    }

    // Clean up
    for (const auto& car : cars) {
        delete car;
    }
    cars.clear();

    return 0;
}

