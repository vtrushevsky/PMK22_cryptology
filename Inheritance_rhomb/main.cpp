#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Базовий клас "Автомобіль"
class Automobile {
protected:
    double engineVolume; // Об'єм двигуна
    string name; // Назва
    string brand; // Марка

public:
    Automobile(double volume, string carName, string carBrand) :
        engineVolume(volume), name(carName), brand(carBrand) {}

    virtual void print(ostream& out) const {
        out << "Автомобіль марки " << brand << ", модель " << name << ", об'єм двигуна " << engineVolume << " л" << endl;
    }

    string getBrand() {
        return brand;
    }

    // Для сортування за об'ємом двигуна
    bool operator<(const Automobile& other) const {
        return engineVolume < other.engineVolume;
    }

    // Для сортування за маркою
    bool operator==(const Automobile& other) const {
        return brand == other.brand;
    }
};

// Похідний клас "Бензиновий автомобіль"
class GasolineAutomobile : virtual public Automobile {
protected:
    double fuelTankVolume; // Об'єм баку

public:
    GasolineAutomobile(double volume, string carName, string carBrand, double tankVolume) :
        Automobile(volume, carName, carBrand), fuelTankVolume(tankVolume) {}

    virtual void print(ostream& out) const {
        out << "Бензиновий автомобіль марки " << brand << ", модель " << name << ", об'єм двигуна " << engineVolume << " л, об'єм баку " << fuelTankVolume << " л" << endl;
    }
};

// Похідний клас "Електромобіль"
class ElectricAutomobile : virtual public Automobile {
protected:
    int maxRange; // Максимальний пробіг на одному заряді
    int chargingTime; // Час зарядки

public:
    ElectricAutomobile(double volume, string carName, string carBrand, int range, int time) :
        Automobile(volume, carName, carBrand), maxRange(range), chargingTime(time) {}

    virtual void print(ostream& out) const {
        out << "Електромобіль марки " << brand << ", модель " << name << ", об'єм двигуна " << engineVolume << " л, максимальний пробіг на одному заряді " << maxRange << " км, час зарядки " << chargingTime << " год" << endl;
    }
};

// Клас "Комбінований автомобіль"
class HybridAutomobile : public GasolineAutomobile, public ElectricAutomobile {
public:
    HybridAutomobile(double volume, string carName, string carBrand, double tankVolume, int range, int time) :
        Automobile(volume, carName, carBrand), GasolineAutomobile(volume, carName, carBrand, tankVolume), ElectricAutomobile(volume, carName, carBrand, range, time) {}
    virtual void print(ostream& out) const {
        out << "Комбінований автомобіль марки " << brand << ", модель " << name << ", об'єм двигуна " << engineVolume << " л, об'єм баку " << fuelTankVolume << " л, максимальний пробіг на одному заряді " << maxRange << " км, час зарядки " << chargingTime << " год" << endl;
    }
};
int main() {
    // Створення об'єктів різних типів автомобілів
    Automobile a1(2.0, "Civic", "Honda");
    GasolineAutomobile a2(3.5, "Explorer", "Ford", 70.0);
    ElectricAutomobile a3(1.5, "Model S", "Tesla", 500, 8);
    HybridAutomobile a4(2.5, "Prius", "Toyota", 50.0, 400, 6);

    // Створення масиву автомобілів
    const int NUM_AUTOMOBILES = 4;
    Automobile* automobiles[NUM_AUTOMOBILES] = { &a1, &a2, &a3, &a4 };

    // Відкриття файлу для виведення даних
    ofstream out("output.txt");

    if (out.is_open()) {
        // Виведення даних про автомобілі у файл
        for (int i = 0; i < NUM_AUTOMOBILES; i++) {
            automobiles[i]->print(out);
        }

        out << endl;

        // Сортування за об'ємом двигуна та виведення відсортованих даних у файл
        sort(automobiles, automobiles + NUM_AUTOMOBILES);
        for (int i = 0; i < NUM_AUTOMOBILES; i++) {
            automobiles[i]->print(out);
        }

        out << endl;

        // Сортування за маркою та виведення відсортованих даних у файл
        sort(automobiles, automobiles + NUM_AUTOMOBILES, [](const Automobile* a, const Automobile* b) {
            return a->getBrand() < b->getBrand();
            });

        for (int i = 0; i < NUM_AUTOMOBILES; i++) {
            automobiles[i]->print(out);
        }

        out << endl;

        // Закриття файлу
        out.close();
    }
    else {
        cout << "Не вдалося відкрити файл для запису!" << endl;
        return 1;
    }

    return 0;
}
