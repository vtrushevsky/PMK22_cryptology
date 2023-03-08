#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Базовий клас для опису товару
class Product {
protected:
    string country_code; // код країни-виробника
    double price; // ціна товару
public:
    // Конструктор з параметрами
    Product(string country_code, double price) {
        this->country_code = country_code;
        this->price = price;
    }

    // Геттери для отримання даних про товар
    string getCountryCode() const {
        return country_code;
    }

    double getPrice() const {
        return price;
    }
};

// Клас для опису іграшки, що наслідує клас товару
class Toy : public Product {
private:
    string name; // назва іграшки
    int min_age; // мінімальний вік для використання
    int max_age; // максимальний вік для використання
public:
    // Конструктор з параметрами, що викликає конструктор базового класу
    Toy(string country_code, double price, string name, int min_age, int max_age)
        : Product(country_code, price) {
        this->name = name;
        this->min_age = min_age;
        this->max_age = max_age;
    }

    // Геттери для отримання даних про іграшку
    string getName() const {
        return name;
    }

    int getMinAge() const {
        return min_age;
    }

    int getMaxAge() const {
        return max_age;
    }
};

int main() {
    // Створення декількох іграшок
    Toy toy1("US", 9.99, "Lego", 4, 12);
    Toy toy2("CN", 4.99, "Rubik's Cube", 8, 99);
    Toy toy3("JP", 14.99, "Tamagotchi", 6, 99);
    Toy toy4("US", 19.99, "Barbie", 3, 8);
    Toy toy5("CN", 24.99, "RC Car", 6, 14);

    // Створення вектору з усіма іграшками
    vector<Toy> toys = { toy1, toy2, toy3, toy4, toy5 };

    // Запит користувача на введення вікового діапазону та цінових меж
    int min_age, max_age;
    double min_price, max_price;
    cout << "Enter minimum age: ";
    cin >> min_age;
    cout << "Enter maximum age: ";
    cin >> max_age;
    cout << "Enter minimum price: ";
    cin >> min_price;
    return 0;
}
